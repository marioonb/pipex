/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_path.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelorge <mbelorge@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/19 12:26:08 by mbelorge          #+#    #+#             */
/*   Updated: 2021/06/19 12:27:41 by mbelorge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	var_lenght(char *str)
{
	int	i;

	i = 0;
	while (str[i] && str[i] != '=')
		i++;
	return (i);
}

char	*find_var(char *str, char **env)
{
	int	i;
	int	lenght;

	i = 0;
	while (env[i])
	{
		lenght = var_lenght(env[i]);
		if (ft_strncmp(str, env[i], lenght) == 0
			&& (int)ft_strlen(str) <= lenght)
			return (ft_substr(env[i] + 1, lenght, ft_strlen(env[i]) - lenght));
		i++;
	}
	return (NULL);
}

static char	*check_tab_path(char **path_split, char *bin, char *cmd)
{
	int		i;

	i = 0;
	while (path_split[i])
	{
		bin = (char *)ft_calloc(sizeof(char), (ft_strlen(path_split[i]) + 1
					+ ft_strlen(cmd) + 1));
		if (bin == NULL)
			ft_error(2, " ");
		ft_strcat(bin, path_split[i]);
		ft_strcat(bin, "/");
		ft_strcat(bin, cmd);
		if (access(bin, F_OK) == 0)
			break ;
		free(bin);
		bin = NULL;
		i++;
	}
	return (bin);
}

static char	*get_path_2(char *cmd, char **env)
{
	char		*path;
	char		**path_split;
	char		*bin;

	bin = NULL;
	path_split = NULL;
	path = NULL;
	path = find_var("PATH", env);
	if (path == NULL)
		return (NULL);
	path_split = ft_split(path, ':');
	free(path);
	path = NULL;
	bin = check_tab_path(path_split, bin, cmd);
	free_tab_char(path_split);
	return (bin);
}

int	get_path(char **cmd, char **env)
{
	char	*bin;

	bin = NULL;
	if (cmd[0][0] != '/' && ft_strncmp(cmd[0], "./", 2) != 0)
	{
		bin = get_path_2(cmd[0], env);
		if (bin == NULL)
			return (0);
	}
	execve(bin, cmd, env);
	free(bin);
	return (1);
}
