/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mariana <mariana@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/24 17:02:32 by mariana           #+#    #+#             */
/*   Updated: 2022/10/24 16:24:23 by mariana          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H
# include <errno.h>
# include <stdio.h>
# include <sys/wait.h>
# include "libft.h"

void	ft_check_error(char *message);
void	ft_close_fd(int *fd);
char	*ft_copy_str(char *src);
char	*ft_get_file(char *file_name, char *envp[]);
char	*ft_get_path(char *cmd, char *envp[]);
void	ft_error(char *message);
void	ft_error_fork(int *fd, char *message);
void	ft_exec_cmd(char *cmd, char *envp[]);
void	ft_exec_p1(char *argv[], int *fd, char *envp[]);
void	ft_exec_p2(char *argv[], int *fd, char *envp[], int argc);
void	ft_set_stdout(char *file2);
void	ft_set_stdin(char *file, int *fd);

#endif
