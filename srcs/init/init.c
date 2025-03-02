/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyan-bin <yyan-bin@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/02 11:54:25 by yyan-bin          #+#    #+#             */
/*   Updated: 2025/03/02 11:56:56 by yyan-bin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3D.h"

void    init_cub(t_cub *cub, char **argv)
{
    cub->path = ft_strdup(argv[1]);
    cub->infile = NULL;
    cub->n_path = NULL;
    cub->s_path = NULL;
    cub->w_path = NULL;
    cub->e_path = NULL;
}

int init_mlx(t_mlx *mlx, t_dir *dir)
{
    mlx->e_path = ft_substr(dir->dir[dir->e], 3, ft_strlen(dir->dir[dir->e]) - 3);
    mlx->w_path = ft_substr(dir->dir[dir->w], 3, ft_strlen(dir->dir[dir->w]) - 3);
    mlx->n_path = ft_substr(dir->dir[dir->n], 3, ft_strlen(dir->dir[dir->n]) - 3);
    mlx->s_path = ft_substr(dir->dir[dir->s], 3, ft_strlen(dir->dir[dir->s]) - 3);
    if (!mlx->e_path || !mlx->w_path || !mlx->n_path || !mlx->s_path)
        return (1);
    return (0);
}

int    init_dir(t_dir *dir, char **infile)
{
    if (ft_arrlen(infile) < 4)
        return (1);
    dir->dir = ft_arrdup_n(infile, 4);
    dir->e = -1;
    dir->n = -1;
    dir->s = -1;
    dir->w = -1;
    return (0);
}