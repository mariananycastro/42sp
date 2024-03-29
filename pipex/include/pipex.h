/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mariana <mariana@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/24 17:02:32 by mariana           #+#    #+#             */
/*   Updated: 2022/10/25 08:48:56 by mariana          ###   ########.fr       */
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
void	ft_error_fork(int *fd, char *message);
void	ft_error(char *message);
void	ft_exec_cmd(char *cmd, char *envp[]);
void	ft_exec_p1(char *argv[], int *fd, char *envp[]);
void	ft_exec_p2(char *argv[], int *fd, char *envp[], int argc);
void	ft_free_array(char **args);
char	*ft_get_file(char *file_name, char *envp[]);
char	*ft_get_path(char *cmd, char *envp[]);
void	ft_set_stdin(char *file, int *fd);
void	ft_set_stdout(char *file2);
#endif
