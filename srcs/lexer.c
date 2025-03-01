/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyan-bin <yyan-bin@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/01 20:29:13 by yyan-bin          #+#    #+#             */
/*   Updated: 2025/03/02 01:38:53 by yyan-bin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3D.h"  

int    init_dir(t_dir *dir, char **infile)
{
    if (ft_arrlen(infile) < 4)
        return (1);
    dir->dir = ft_arrdup_n(infile, 4);
    dir->e = 0;
    dir->n = 0;
    dir->s = 0;
    dir->w = 0;
    return (0);
}

int lexer(t_cub *cub)
{
    // int i;

    // i = 0;
    if (init_dir(&cub->dir, cub->infile))
        return (1);
    if (check_direction(&cub->dir))
        return (1);
    return (0);
}