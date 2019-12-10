/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   libftprintf.h                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: coscialp <coscialp@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/10/28 10:06:37 by tclaudel     #+#   ##    ##    #+#       */
/*   Updated: 2019/12/10 17:45:43 by coscialp    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include "libft.h"

typedef struct	s_printf
{
	char		flags[5];
	char		option;
	char		zero;
	char		sign;
	int			fd;
	size_t		width;
	size_t		accu;
	size_t		return_size;
}				t_printf;

int				ft_printf(const char *fmt, ...);
char			*ft_strjoin_zero(char *s1, char *s2);
char			*ft_c_converter(int nb, t_printf *pf);
char			*ft_d_converter(int nb, t_printf *pf);
char			*ft_s_converter(char *str, size_t width, char *flags);
char			*ft_f_converter(double nb);
char			*ft_p_converter(long long address, t_printf *pf);
char			*ft_u_converter(unsigned int nb);
char			*ft_x_converter(unsigned int nb);
char			*ft_upx_converter(unsigned int nb);
char			*ft_pourcent_converter(void);
char			*ft_itoa_pf(int n, t_printf *pf);
int				ft_is_pourcent(char c);
int				ft_is_flag(char c);
int				ft_is_option(char c);
char			*ft_analyser(char *tmp, t_printf *pf, va_list ap);
t_printf		*ft_set_flags(t_printf *pf, char *str);
char			*ft_new_fmt(char *old, t_printf *pf);
char			*ft_set_width(char *str, t_printf *pf, va_list ap, size_t i);
char			*ft_router(char *str, t_printf *pf, va_list ap);
char			*ft_apply_flags(char *str, t_printf *pf);
char			*ft_apply_convert(t_printf *pf, va_list ap);
int				ft_isone_nine(int c);
int				ft_is_in_flags(char c, t_printf *pf);
char			*ft_zero_flag(char *str, t_printf *pf, char sign);
char			*ft_width_accu(char *str, t_printf *pf, int *sign, char *str2);
int				ft_dprintf(int fd, const char *s, ...);
char			**ft_set_tmp(const char *str);
char			*ft_join_result(char *result, char *tmp, t_printf *pf);
t_printf		*setup_struct(void);

#endif
