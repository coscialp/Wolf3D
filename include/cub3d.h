/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   cub3d.h                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: coscialp <coscialp@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/11/30 16:40:25 by coscialp     #+#   ##    ##    #+#       */
/*   Updated: 2020/01/02 19:37:20 by coscialp    ###    #+. /#+    ###.fr     */
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

# define MOVSPEED 0.1
# define ROTSPEED 0.05

/*
**┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓
**┃								struct math                                   ┃
**┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛
*/

typedef struct	s_vector
{
	double		x;
	double		y;
}				t_vector;

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
	int				col_floor;
	int				col_ceil;
	char			*north_texture;
	char			*south_texture;
	char			*west_texture;
	char			*east_texture;
	char			*sprite_texture;
	void			*ptrwin;
	void			*win;
	t_vector		plane;

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
**┃								struct img                                    ┃
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
	int			*ptr;
}				t_image;

/*
**┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓
**┃								struct player                                 ┃
**┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛
*/

typedef struct	s_player
{
	t_vector	dir;
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
	char		move;
	char		rotate;
	int			map_x;
	int			map_y;
	int			step_x;
	int			step_y;
	int			hit;
	int			side;
	int			height_draw;
	int			draw_start;
	int			draw_end;
	int			tex_x;
	int			tex_y;
	int			direction;
	double		step;
	double		tex_pos;
	double		cam_x;
	double		movspeed;
	double		rotspeed;
	double		wall_pos;
	t_vector	old_plane;
	t_vector	old_dir;
	t_vector	side_dist;
	t_vector	delta_dist;
	t_data		data;
	t_map		map;
	t_color		color;
	t_player	player;
	t_image		img;
	t_image		tex[5];
}				t_cub3d;

/*
**┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓
**┃								function parsing                              ┃
**┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛
*/

void			loading_all_tex(t_cub3d *c);
void			parsing_core(t_cub3d *c);
int				parsing_texture(char *current_line, size_t i, t_data *data);
int				parsing_resolution(char *line, t_data *data);
int				parsing_analyser(char *line, t_cub3d *c);
int				parsing_color(char *line, t_cub3d *c);
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

void			ft_exit(t_cub3d *c);
void			print_params(t_cub3d *c);
int				secu_initialize(char **map_1d, int fd);
int				msg_error(char *reason);
t_bool			ft_isargb(unsigned char color);
t_bool			ft_ismap(char c);
t_bool			ft_ispos(char pos);

/*
**┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓
**┃								function struct                               ┃
**┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛
*/

void			ft_free_struct(t_data data);
t_cub3d			*init_cub3d(char *file);
t_data			init_data(char *file);
t_map			init_map(void);
t_color			init_color(void);

/*
**┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓
**┃								function events                               ┃
**┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛
*/

void			ft_exit_sucess(t_cub3d *c);
int				close_prgm(t_cub3d *c);
int				key_press(int keycode, t_cub3d *c);
int				key_release(int keycode, t_cub3d *c);
void			rotate(t_cub3d *c, char rotate);
void			move_camera(t_cub3d *c, char orientation);

/*
**┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓
**┃								function raycast                              ┃
**┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛
*/

int				raycast(t_cub3d *c);
void			draw(t_cub3d *c, int x);

#endif
