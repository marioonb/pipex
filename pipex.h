/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelorge <mbelorge@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/19 12:26:08 by mbelorge          #+#    #+#             */
/*   Updated: 2021/06/19 12:27:41 by mbelorge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <string.h>
# include <signal.h>
# include <stdbool.h>
# include "./libft/libft.h"
# include <fcntl.h>

typedef struct s_cmd
{
	char	*cmd1;
	char	*cmd2;
	int		filefd1;
	int		filefd2;
}				t_cmd;

void	exec_cmd1(char *cmd, int filefd, int fd[2], char **env);
void	exec_cmd2(char *cmd, int filefd, int fd[2], char **env);
int		ft_error(int index, char *string);
int		get_path(char **cmd, char **env);

#endif
