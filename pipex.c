/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mofaisal <mofaisal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 22:04:28 by mofaisal          #+#    #+#             */
/*   Updated: 2023/02/26 18:13:50 by mofaisal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int argc, char **argv, char **env)
{
	pid_t	pid;
	int		fd[2];

	if (argc != 5)
		exit(ft_printf(STRING) * 0 + 1);
	if (pipe(fd) == -1)
		ft_printf("Error\n");
	pid = fork();
	if (pid == 0)
		child_process(argv, env, fd);
	else if (pid > 0)
	{
		wait(NULL);
		parent_process(argv, env, fd);
	}
	else
		return (ft_printf("Forking the process failed\n") * 0);
	return (0);
}

void	child_process(char **argv, char **env, int *fd)
{
	int	infile;

	infile = open(argv[1], O_RDONLY, 0777);
	if (infile < 0)
	{
		perror("Error while opening the output file");
		exit(1);
	}
	dup2(fd[1], STDOUT_FILENO);
	dup2(infile, STDIN_FILENO);
	close(fd[0]);
	close(fd[1]);
	close(infile);
	execute(argv[2], env, infile);
}

void	parent_process(char **argv, char **env, int *fd)
{
	int	outfile;

	outfile = open(argv[4], O_CREAT | O_WRONLY | O_TRUNC, 0777);
	if (outfile < 0)
	{
		perror("Error while opening the output file");
		exit(1);
	}
	dup2(outfile, STDOUT_FILENO);
	dup2(fd[0], STDIN_FILENO);
	close(fd[1]);
	close(fd[0]);
	close(outfile);
	execute(argv[3], env, outfile);
}

void	free_string_array(char **array)
{
	int	i;

	i = 0;
	while (array[i] != NULL)
	{
		free(array[i]);
		array[i] = NULL;
		i++;
	}
	free(array);
	array = NULL;
}
