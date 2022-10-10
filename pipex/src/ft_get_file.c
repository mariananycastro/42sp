/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_file.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mariana <mariana@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/09 21:44:33 by mariana           #+#    #+#             */
/*   Updated: 2022/10/09 22:19:59 by mariana          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*ft_get_file(char *file_name, char *envp[])
{
	char	*complete_path;
	char	*file_path;
	int		i;
	int		len;

	i = 0;
	while (!ft_strnstr(envp[i], "PWD", 3))
		i++;
	len = 0;
	while (envp[len])
		len++;
	file_path = (char *) malloc(sizeof(char) * len + 1);
	ft_strlcpy(file_path, envp[i] + 4, len + 1);
	file_path = ft_strjoin(file_path, "/");
	complete_path = ft_strjoin(file_path, file_name);
	free(file_path);
	return (complete_path);
}
