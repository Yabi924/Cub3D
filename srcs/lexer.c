/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyan-bin <yyan-bin@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/01 20:29:13 by yyan-bin          #+#    #+#             */
/*   Updated: 2025/03/02 11:55:59 by yyan-bin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3D.h"  

int lexer(t_cub *cub)
{
    // int i;

    // i = 0;
    if (init_dir(&cub->dir, cub->infile))
        return (1);
    if (check_direction(&cub->dir))
        return (1);
    if (check_direction_path(&cub->dir, cub))
        return (1);
    return (0);
}
