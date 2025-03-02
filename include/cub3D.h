#ifndef CUB3D_H
# define CUB3D_H

# include "../minilibx-linux/mlx.h"
# include "../minilibx-linux/mlx_int.h"
# include "../libft/libft.h"
# include <math.h>
# include <fcntl.h>
# include <stdio.h>

typedef struct s_mlx
{
    char    *n_path;
    char    *w_path;
    char    *s_path;
    char    *e_path;

}   t_mlx;

typedef struct s_dir
{
    char **dir;

    int n;
    int s;
    int w;
    int e;

}   t_dir;

typedef struct s_cub
{
    char    *path;
    char    **infile;
    char    *n_path;
    char    *s_path;
    char    *w_path;
    char    *e_path;
    t_mlx   mlx;
    t_dir   dir;
}   t_cub;

//init.c
void    init_cub(t_cub *cub, char **argv);
int     init_mlx(t_mlx *mlx, t_dir *dir);
int     init_dir(t_dir *dir, char **infile);

//utils.c
char    **ft_arrdup(char **arr);
char    **ft_arrdup_n(char **arr, int n);
char    *ft_strjoin_free(char *s1, char *s2);
int     ft_arrlen(char **arr);
void    err(char *message, int q);

//free.c
void    free_data(t_cub *cub);
void    free_arr(char **arr);

//check_dir.c
int check_direction(t_dir *dir);
int check_direction_path(t_dir *dir, t_cub *cub);

//lexer.c
int lexer(t_cub *cub);

//debug
void    print_arr(char **arr);
void    debug(int n);

#endif