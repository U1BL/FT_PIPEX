/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mofaisal <mofaisal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 22:04:20 by mofaisal          #+#    #+#             */
/*   Updated: 2023/02/26 18:15:10 by mofaisal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*get_path_from_env(char **env)
{
	int	i;

	i = 0;
	while (env[i])
	{
		if ((ft_strncmp("PATH=", env[i], 5) == 0))
			return (ft_strdup((env[i] + 5)));
		i++;
	}
	return (NULL);
}

char	*find_command_existance(char **dir, char *cmd)
{
	char	*joinedstr;
	int		i;

	i = 0;
	while (dir[i])
	{
		joinedstr = ft_strjoin(dir[i], cmd);
		if (access(joinedstr, F_OK) == 0)
			return (free_string_array(dir), (free(cmd)), joinedstr);
		free(joinedstr);
		i++;
	}
	return (free(cmd), NULL);
}

char	*find_command_path(char **directories, char *command)
{
	int		i;
	int		j;
	char	*cmd;

	i = 0;
	j = 1;
	cmd = malloc(ft_strlen(command) + 2);
	cmd[0] = '/';
	i = 0;
	while (command[i] && command[i] != ' ')
		cmd[j++] = command[i++];
	cmd[ft_strlen(command) + 1] = '\0';
	i = 0;
	if (access(command, F_OK) == 0)
		return (command);
	return (find_command_existance(directories, cmd));
	i = -1;
	free_string_array(directories);
	return (NULL);
}

void	check_path(t_pipe *pipe, char *argv)
{
	if (!pipe->path)
	{
		pipe->flags = ft_split(argv, ' ');
		if (!pipe->flags)
			pipe->tmp = NULL;
		else
			pipe->tmp = pipe->flags[0];
	}
	else
	{
		pipe->flags = ft_split(argv, ' ');
		if (!pipe->flags || argv[0] == ' ')
			pipe->tmp = NULL;
		else
		{
			pipe->dirs = ft_split(pipe->path, ':');
			pipe->tmp = find_command_path(pipe->dirs, pipe->flags[0]);
		}
	}
}

void	execute(char *argv, char **env, int fd)
{
	t_pipe	pipe;

	pipe.tmp = NULL;
	pipe.path = get_path_from_env(env);
	if (argv && argv[0] && argv[0] != ' ')
	{
		check_path(&pipe, argv);
		close(fd);
		if (pipe.tmp)
		{
			if (execve(pipe.tmp, pipe.flags, env) < 0)
			{
				free(pipe.tmp);
				exit((write(2, STRING2, ft_strlen(STRING2))) * 0 + 1);
			}
		}
		else
		{
			free(pipe.tmp);
			exit((write(2, STRING1, ft_strlen(STRING1))) * 0 + 1);
		}
	}
	free(pipe.path);
	exit((write(2, STRING1, ft_strlen(STRING1))) * 0 + 1);
}
