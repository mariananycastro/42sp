/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mariana <mariana@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/24 17:02:32 by mariana           #+#    #+#             */
/*   Updated: 2022/10/04 14:21:47 by mariana          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H
# include <errno.h>
# include <stdio.h>
# include <sys/wait.h>
# include "libft.h"
// # include <sys/types.h>

# define ERRARG 1
# define ERRINFILE 2
# define ERROUTFILE 3
# define ERRARGS 4
# define ERRPROCESS 5
# define ERRPIPE 6
# define ERRFORK 7
# define ERRPROCESSARGS 8

void	ft_set_stdout(char *file2);
void	ft_error(char *file2, char *message);
void	ft_check_error(char *message);
void	ft_error_fork(char *argv[], int *fd, int argc, char *message);
void	ft_close_fd(int *fd);
void	ft_exec_p1(char *argv[], int *fd, char *envp[]);
void	ft_set_stdin(char *file, int *fd);
void	ft_exec_cmd(char *cmd, char *envp[]);
void	ft_exec_p2(char *argv[], int *fd, char *envp[], int argc);
#endif
