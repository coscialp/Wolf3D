/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   save.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: coscialp <coscialp@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/01/07 17:39:12 by coscialp     #+#   ##    ##    #+#       */
/*   Updated: 2020/01/07 18:16:13 by coscialp    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "cub3d.h"

void	bitmap_image(t_cub3d *c, int fd, t_bpm2 bih)
{
	int				x;
	int				y;
	int				ble;
	unsigned char	color[3];
	
	write(fd, &bih, sizeof(bih));
	y = c->data.res_y - 1;
	while (y >= 0)
	{
		x = 0;
		while (x < c->data.res_x)
		{
			ble = c->img.ptr[y * c->data.res_x + x];
			color[0] = ble % 256;
			ble /= 256;
			color[1] = ble % 256;
			ble /= 256;
			color[2] = ble % 256;
			write(fd, &color, sizeof(color));
			x++;
		}
		y--;
	}
}

void	save_bitmap(const char *filename, t_cub3d *c)
{
	int			fd;
	t_bpm		bfh;
	t_bpm2		bih;
	
	ft_memcpy(&bfh.bitmap_type, "BM", 2);
	bfh.file_size = c->data.res_x * c->data.res_y * 4 + 54;
	bfh.reserved1 = 0;
	bfh.reserved2 = 0;
	bfh.offset_bits = 0;
	bih.size_header = sizeof(bih);
	bih.width = c->data.res_x;
	bih.height = c->data.res_y;
	bih.planes = 1;
	bih.bit_count = 24;
	bih.compression = 0;
	bih.image_size = c->data.res_x * c->data.res_y * 4 + 54;
	bih.ppm_x = 2;
	bih.ppm_y = 2;
	bih.clr_used = 0;
	bih.clr_important = 0;
	close(open(filename, O_RDONLY | O_CREAT, S_IRWXU));
	fd = open(filename, O_RDWR);
	write(fd, &bfh, 14);
	bitmap_image(c, fd, bih);
	close(fd);
}