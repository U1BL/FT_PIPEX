/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mofaisal <mofaisal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 22:04:20 by mofaisal          #+#    #+#             */
/*   Updated: 2023/02/21 22:26:29 by mofaisal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void free_string_array(char **array)
{
    int i;

    i = 0;
    while (array[i] != NULL)
    {
        free(array[i]);
        i++;
    }
    free (array);
}

void open_file_and_redirect_input(char *file_path) 
{
    int fd;

    fd = open(file_path, O_RDONLY);
    if (fd == -1)
    {
        perror("Error while opening the file");
        exit(1);
    }
    dup2(fd, STDIN_FILENO);
}

char *get_path_from_env(char **env) 
{
    int i;

    i = 0;
    while (env[i])
    {
        if ((strncmp("PATH=", env[i], 5) == 0))
            return strdup((env[i] + 5));
        i++;
    }
    return NULL;
}

char *find_command_path(char **directories, char *command) 
{
    char *joinedstr;
    int i;

    i = 0;
    while (directories[i])
    {
        char *dir_path = directories[i];
        int dir_len = strlen(dir_path);
        int cmd_len = strlen(command);
        joinedstr = malloc(dir_len + cmd_len + 2);
        if (!joinedstr)
        {
            perror("Error while allocating memory");
            exit(1);
        }
        strcpy(joinedstr, dir_path);
        joinedstr[dir_len] = '/';
        strcpy(joinedstr + dir_len + 1, command);
        if (access(joinedstr, F_OK) == 0)
        {
            return joinedstr;
        }
        free(joinedstr);
        i++;
    }
    return NULL;
}

void redirect_output_to_file(char *command, char *output_file_path, char *command_path)
{
    int fd;

    fd = open(output_file_path, O_CREAT | O_WRONLY | O_TRUNC, 0666);
    if (fd == -1)
    {
        perror("Error while opening the output file");
        exit(1);
    }
    dup2(fd, STDOUT_FILENO);
    execl(command_path, command, NULL);
}
