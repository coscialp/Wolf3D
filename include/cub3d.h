/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   cub3d.h                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: coscialp <coscialp@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/11/30 16:40:25 by coscialp     #+#   ##    ##    #+#       */
/*   Updated: 2019/12/09 12:07:42 by coscialp    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "libft.h"
# include "libftprintf.h"
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>

/*
**┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓
**┃								struct parsing map                            ┃
**┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛
*/

typedef struct		s_data
{
	int				fd;
	int				res_x;
	int				res_y;
	int				color_floor;
	int				color_sky;
	char			*north_texture;
	char			*south_texture;
	char			*west_texture;
	char			*east_texture;
	char			*sprite_texture;

}					t_data;

typedef struct		s_map
{
	char			compass;
	int				start_pos_x;
	int				start_pos_y;
	int				length;
	int				height;
	char			*map_1d;
	char			**map_2d;
}					t_map;

/*
**┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓
**┃								struct color                                  ┃
**┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛
*/

typedef struct		s_rgba
{
	unsigned char	b;
	unsigned char	g;
	unsigned char	r;
	unsigned char	a;
}					t_rgba;

typedef union		u_color
{
	int				color;
	t_rgba			rgba;
}					t_color;

/*
**┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓
**┃								function parsing                              ┃
**┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛
*/

int					parsing_core(t_data *data, t_map *map, t_color *color);
int					parsing_texture(char *current_line, size_t i, t_data *data);
int					parsing_resolution(char *line, t_data *data);
int					parsing_analyser(char *line, t_data *data, t_map *map, t_color *color);
int					parsing_color(char *line, t_color *color, t_data *data);
int					parsing_name(char *name);
int					map_dimension(t_map *map);
int					read_map(int fd, t_map *map, char *current_line);
int					parsing_map(t_map *map);
int					check_map(t_map *map, int i, int j);
int					texture_is_valid(char *path);


/*
**┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓
**┃								function error                                ┃
**┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛
*/

void				ft_exit(t_data *data, t_map *map, t_color *color, int f);
int					msg_error(char *reason);
int					ft_isargb(unsigned char color);
int					ft_ismap(char c);
int					ft_ispos(char pos);
int					secu_initialize(char **map_1d, int fd);

/*
**┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓
**┃								function struct                               ┃
**┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛
*/

void				ft_free_struct(t_data *data);
t_data				*init_data(int fd);
t_map				*init_map(void);
t_color				*init_color(t_data *data, t_map *map);

#endif
