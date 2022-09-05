/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_img_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mariana <mariana@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 23:02:38 by mariana           #+#    #+#             */
/*   Updated: 2022/09/04 19:17:01 by mariana          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

t_img	ft_create_img_bonus(t_data *data, char *imgPath)
{
	t_img	new_img;

	new_img.mlx_img = mlx_xpm_file_to_image(
			data->mlx_ptr, imgPath, &new_img.width, &new_img.height
			);
	new_img.addr = mlx_get_data_addr(
			new_img.mlx_img, &new_img.bpp, &new_img.line_len, &new_img.endian
			);
	return (new_img);
}
