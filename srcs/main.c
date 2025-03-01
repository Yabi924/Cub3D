/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyan-bin <yyan-bin@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/01 20:33:30 by yyan-bin          #+#    #+#             */
/*   Updated: 2025/03/02 01:40:38 by yyan-bin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3D.h"

void    init_cub(t_cub *cub, char **argv)
{
    cub->path = ft_strdup(argv[1]);
    cub->infile = NULL;
    cub->n_path = NULL;
    cub->s_path = NULL;
    cub->w_path = NULL;
    cub->e_path = NULL;
}

int is_cub_file(char *file_name)
{
    int i;

    if (!file_name)
        return (1);
    i = ft_strlen(file_name);
    if (file_name[i - 4] == '.' && file_name[i - 3] == 'c' && \
        file_name[i - 2] == 'u' && file_name[i - 1] == 'b')
        return (0);
    return (1);
}

int check_invalid(t_cub *cub)
{
    int fd;
    char    *temp;
    char    *readd;

    if (is_cub_file(cub->path))
        err("Not .cub file!", 1);
    fd = open(cub->path, O_RDONLY);
    if (fd < 0)
        err("Invalid map path!", 1);
    temp = get_next_line(fd);
    readd = ft_calloc(1, 1);
    while (temp)
    {
        readd = ft_strjoin_free(readd, temp);
        if (temp)
            free(temp);
        temp = get_next_line(fd);
    }
    cub->infile = ft_split(readd, '\n');
    if (!cub->infile)
        err("Error: fatal", 1);
    if (readd)
        free(readd);
    return (lexer(cub));
}

int main(int argc, char **argv)
{
    t_cub cub;

    if (argc != 2)
        err("Invaild input! Please follow ./cub3D <map_path>", 1);
    init_cub(&cub, argv);
    if (check_invalid(&cub))
    {
        free_data(&cub);
        err("Invaild Map!", 1);
    }
    printf("good\n");
    free_data(&cub);
    return (0);
}

void    print_arr(char **arr)
{
    int i = -1;
    
    ft_putendl_fd("debug: ", 2);
    while (arr[++i])
        ft_putendl_fd(arr[i], 2);
}

void    debug(int n)
{
    ft_putstr_fd("debug", 2);
    ft_putnbr_fd(n, 2);
    ft_putendl_fd(" ", 2);
}