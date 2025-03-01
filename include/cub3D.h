#ifndef CUB3D_H
# define CUB3D_H

#include "../libft/libft.h"
#include <math.h>
# include <fcntl.h>

typedef struct s_mlx
{

}   t_mlx;

typedef struct s_cub
{
    char    *path;
    char    **infile;
    char    *n_path;
    char    *s_path;
    char    *w_path;
    char    *e_path;
    t_mlx   mlx;
}   t_cub;

//utils.c
char    **ft_arrdup(char **arr);
char    *ft_strjoin_free(char *s1, char *s2);
void    err(char *message, int q);

//lexer.c
int lexer(t_cub *cub);


//debug
void    print_arr(char **arr);
void    debug(int n);

#endif