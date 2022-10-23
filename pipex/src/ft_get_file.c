/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_file.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mariana <mariana@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/09 21:44:33 by mariana           #+#    #+#             */
/*   Updated: 2022/10/23 16:31:43 by mariana          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char *ft_copy_str(char *src)
{
	int		size;
	int		i;
	char	*answer;

	size = 0;
	size = ft_strlen(src);
	if (size == 0)
		return (NULL);
	i = 0;
	answer = (char *) malloc(sizeof(char) * size + 1);
	while (src[i])
	{
		answer[i] = src[i];
		i++;
	}
	answer[i] = '\0';
	return (answer);
}

char	*ft_get_file(char *file_name, char *envp[])
{
	char	*complete_path;
	char	*file_path1;
	char	*file_path2;
	int		i;

	i = 0;
	while (!ft_strnstr(envp[i], "PWD", 3))
		i++;
	file_path1 = ft_copy_str(envp[i] + 4);
	file_path2 = ft_strjoin(file_path1, "/");
	complete_path = ft_strjoin(file_path2, file_name);
	free(file_path1);
	free(file_path2);
	return (complete_path);
}
