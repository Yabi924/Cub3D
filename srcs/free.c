/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyan-bin <yyan-bin@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/02 01:26:41 by yyan-bin          #+#    #+#             */
/*   Updated: 2025/03/02 01:28:48 by yyan-bin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3D.h"

void    free_arr(char **arr)
{
    int i;

    i = -1;
    if (!arr || !arr[0])
        return ;
    while (arr[++i])
        free(arr[i]);
    if (arr)
        free(arr);
}

void    free_data(t_cub *cub)
{
    if (cub->infile)
        free_arr(cub->infile);
    if (cub->path)
        free(cub->path);
}