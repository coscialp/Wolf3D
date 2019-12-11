/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   cub3d.h                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: coscialp <coscialp@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/11/30 16:40:25 by coscialp     #+#   ##    ##    #+#       */
/*   Updated: 2019/12/11 19:09:59 by coscialp    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "libft.h"
# include "key.h"
# include "libftprintf.h"
# include "mlx.h"
# include <math.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>

# define MAP c->map
# define PLAYER c->player
# define DATA c->data
# define COL c->color

/*
**┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓
**┃								struct parsing map                            ┃
**┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛
*/

typedef struct	s_data
{
	int				fd;
	int				res_x;
	int				res_y;
	int				color_floor;
	int				color_ceiling;
	int				cam_height;
	char			*north_texture;
	char			*south_texture;
	char			*west_texture;
	char			*east_texture;
	char			*sprite_texture;
	void			*ptrwin;
	void			*win;

}				t_data;

typedef struct	s_map
{
	char			compass;
	int				start_pos_x;
	int				start_pos_y;
	int				length;
	int				height;
	char			*map_1d;
	char			**map_2d;
}				t_map;

/*
**┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓
**┃								struct color                                  ┃
**┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛
*/

typedef struct	s_rgba
{
	unsigned char	b;
	unsigned char	g;
	unsigned char	r;
	unsigned char	a;
}				t_rgba;

typedef union	u_color
{
	int				color;
	t_rgba			rgba;
}				t_color;

/*
**┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓
**┃								struct img                                  ┃
**┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛
*/

typedef struct	s_image
{
	int			bpp;
	int			size_line;
	int			endian;
	int			width;
	int			height;
	void		*img;
	char		*ptr;
}				t_image;

/*
**┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓
**┃								struct math                                   ┃
**┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛
*/

typedef struct	s_vector
{
	double		u;
	double		v;
}				t_vector;

typedef struct	s_player
{
	int			rotation;
	double		pos_x;
	double		pos_y;
}				t_player;

/*
**┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓
**┃								struct cub3D                                  ┃
**┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛
*/

typedef struct	s_cub3d
{
	t_data		*data;
	t_map		*map;
	t_color		*color;
	t_player	player;
}				t_cub3d;

/*
**┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓
**┃								function parsing                              ┃
**┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛
*/

void			parsing_core(t_cub3d *c);
int				parsing_texture(char *current_line, size_t i, t_data *data);
int				parsing_resolution(char *line, t_data *data);
int				parsing_analyser(char *line, t_data *data, t_map *map,
				t_color *color);
int				parsing_color(char *line, t_color *color, t_data *data);
int				parsing_name(char *name);
int				map_dimension(t_map *map);
int				read_map(int fd, t_map *map, char *current_line);
int				parsing_map(t_cub3d *c);
int				check_map(t_map *map, int i, int j, t_cub3d *c);
int				texture_is_valid(char *path);

/*
**┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓
**┃								function error                                ┃
**┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛
*/

void			ft_exit(t_cub3d *c, int f);
void			print_params(t_cub3d *c);
int				msg_error(char *reason);
t_bool			ft_isargb(unsigned char color);
t_bool			ft_ismap(char c);
t_bool			ft_ispos(char pos);
int				secu_initialize(char **map_1d, int fd);

/*
**┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓
**┃								function struct                               ┃
**┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛
*/

void			ft_free_struct(t_data *data);
t_cub3d			*init_cub3d(char *fd);
t_data			*init_data(char *fd);
t_map			*init_map(t_cub3d *c);
t_color			*init_color(t_cub3d *c);

/*
**┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓
**┃								function events                               ┃
**┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛
*/

void			ft_exit_sucess(t_cub3d *c);
int				close_prgm(t_cub3d *c);
int				key_press(int keycode, t_cub3d *c);

/*
**┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓
**┃								function raycast                              ┃
**┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛
*/

int				raycast(t_cub3d *c);

#endif
