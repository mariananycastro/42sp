/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_path.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mariana <mariana@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/24 17:00:04 by mariana           #+#    #+#             */
/*   Updated: 2022/10/24 16:30:40 by mariana          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_free_split(char **args)
{
	int	i;

	i = 0;
	while (args[i])
	{
		free(args[i]);
		i++;
	}
	free(args);
}

char	*ft_get_path(char *cmd, char *envp[])
{
	char	**paths;
	int		i;
	char	*path;
	char	*partial_path;

	i = 0;
	while (!ft_strnstr(envp[i], "PATH", 4))
		i++;
	paths = ft_split(envp[i] + 5, ':');
	i = 0;
	while (paths[++i])
	{
		partial_path = ft_strjoin(paths[i], "/");
		path = ft_strjoin(partial_path, cmd);
		free(partial_path);
		if (!access(path, F_OK))
		{
			ft_free_array(paths);
			return (path);
		}
		free(path);
	}
	ft_free_array(paths);
	return (NULL);
}
