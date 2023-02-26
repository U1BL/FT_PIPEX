/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mofaisal <mofaisal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 18:16:01 by mofaisal          #+#    #+#             */
/*   Updated: 2023/02/26 17:12:05 by mofaisal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# define STRING "You Have Entered Few Arguments Than Expected\n"
# define STRING1 "Error: Command not found\n"
# define STRING2 "Error: Executing the command failed\n"

# include <unistd.h>
# include "./libft/libft.h"
# include "./printf/ft_printf.h"
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <errno.h>
# include <sys/wait.h>
# include <time.h>
# include <fcntl.h>
# include <sys/stat.h>
# include <sys/types.h>
# include <unistd.h>

typedef struct s_pipe
{
	char	**flags;
	char	*path;
	char	**dirs;
	char	*tmp;
}t_pipe;

void	free_string_array(char **array);
void	execute(char *argv, char **env, int fd);
char	*get_path_from_env(char **env);
char	*find_command_path(char **directories, char *command);
char	*find_command_existance(char **dir, char *cmd);
void	child_process(char **argv, char **env, int *fd);
void	parent_process(char	**argv, char **env, int *fd);

#endif