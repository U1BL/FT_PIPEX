/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mofaisal <mofaisal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 22:04:28 by mofaisal          #+#    #+#             */
/*   Updated: 2023/02/21 22:21:07 by mofaisal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int argc, char *argv[], char *env[])
{
	char	*path;
	char	**dirs;
	char	*cmd_path;

	if (argc != 5)
		exit(ft_printf(STRING) * 0 + 1);
	open_file_and_redirect_input(argv[1]);
	path = get_path_from_env(env);
	if (!(path))
		return (ft_printf("ERROR WHILE FINDING THE PATH\n") * 0 + 1);
	dirs = ft_split(path, ':');
	cmd_path = find_command_path(dirs, argv[2]);
	if (!cmd_path)
	{
		ft_printf("the command %s doesn't exist\n", argv[2]);
		return (1);
	}
	redirect_output_to_file(argv[2], argv[4], cmd_path);
	free_string_array(dirs);
	free(cmd_path);
	free(path);
	return (0);
}
