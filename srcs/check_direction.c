/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_direction.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyan-bin <yyan-bin@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/02 00:39:59 by yyan-bin          #+#    #+#             */
/*   Updated: 2025/03/02 11:56:35 by yyan-bin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3D.h"

int check_direction(t_dir *dir)
{
    int i;

    i = -1;
    while (dir->dir[++i])
    {
        if (!ft_strncmp(dir->dir[i], "NO ", 3) && dir->n == -1)
            dir->n = i;
        else if (!ft_strncmp(dir->dir[i], "SO ", 3) && dir->s == -1)
            dir->s = i;
        else if (!ft_strncmp(dir->dir[i], "WE ", 3) && dir->w == -1)
            dir->w = i;
        else if (!ft_strncmp(dir->dir[i], "EA ", 3) && dir->e == -1)
            dir->e = i;
    }
    if (dir->n == -1 || dir->s == -1 || dir->w == -1 || dir->e == -1)
    {
        if (dir->dir)
        free_arr(dir->dir);
        return (1);
    }
    return (0);
}

int check_direction_path(t_dir *dir, t_cub *cub)
{
    if (init_mlx(&cub->mlx, dir))
        return (1);
    return (0);
}
