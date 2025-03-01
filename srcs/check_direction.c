/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_direction.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyan-bin <yyan-bin@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/02 00:39:59 by yyan-bin          #+#    #+#             */
/*   Updated: 2025/03/02 01:39:22 by yyan-bin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3D.h"

int check_direction(t_dir *dir)
{
    int i;

    i = -1;
    while (dir->dir[++i])
    {
        if (!ft_strncmp(dir->dir[i], "NO ", 3) && dir->n == 0)
            dir->n = 1;
        else if (!ft_strncmp(dir->dir[i], "SO ", 3) && dir->s == 0)
            dir->s = 1;
        else if (!ft_strncmp(dir->dir[i], "WE ", 3) && dir->w == 0)
            dir->w = 1;
        else if (!ft_strncmp(dir->dir[i], "EA ", 3) && dir->e == 0)
            dir->e = 1;
    }
    if (dir->dir)
        free_arr(dir->dir);
    if (!dir->n || !dir->s || !dir->w || !dir->e)
        return (1);
    return (0);
}