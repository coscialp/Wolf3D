/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   libft.h                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: coscialp <coscialp@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/10/07 14:37:20 by coscialp     #+#   ##    ##    #+#       */
/*   Updated: 2019/12/11 15:35:54 by coscialp    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stddef.h>
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>

# define TRUE 1
# define FALSE 0
# define STR_INT_MIN "-2147483648"

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 8
# endif

typedef int	t_bool;

/*
**┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓
**┃                          structure linked list                            ┃
**┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛
*/

typedef struct		s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;

/*
**┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓
**┃                            Function : Char                                ┃
**┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛
*/

t_bool				ft_isalpha(int c);
t_bool				ft_isdigit(int c);
t_bool				ft_isalnum(int c);
t_bool				ft_isascii(int c);
t_bool				ft_isprint(int c);
t_bool				ft_isspace(int c);
t_bool				ft_islower(int c);
t_bool				ft_isupper(int c);
int					ft_toupper(int c);
int					ft_tolower(int c);

/*
**┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓
**┃                            Function : String                              ┃
**┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛
*/

void				ft_strdel(char **ptr);
void				ft_putchar(char c);
void				ft_putstr(const char *str);
void				ft_putendl(char *str);
void				ft_putstr_tab(char **tab);
void				ft_putchar_fd(char c, int fd);
void				ft_putstr_fd(const char *str, int fd);
void				ft_putendl_fd(char *str, int fd);
void				ft_whilestris(char *str, int *i, int (*f)(int), char neg);
int					ft_free_tab(char **strs);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
int					ft_strcmp(const char *s1, const char *s2);
int					get_next_line(int fd, char **line);
char				*ft_strrev(char *str);
char				*ft_strtrim(const char *s1, const char *set);
char				*ft_strcat(char *dest, const char *src);
char				*ft_strjoin(const char *s1, const char *s2);
char				*ft_strcpy(char *dest, const char *src);
char				*ft_strncpy(char *dest, char *src, unsigned int n);
char				*ft_strchr(const char *str, int c);
char				*ft_strrchr(const char *str, int c);
char				*ft_strstr(const char *str, const char *to_find);
char				*ft_strnstr(const char *str, const char *fnd, size_t size);
char				**ft_split(const char *s, char c);
char				**ft_split_line(const char *s);
char				*ft_substr(char const *s, unsigned int start, size_t len);
char				*ft_strjoin(const char *s1, const char *s2);
char				*ft_strfjoin(char *s1, char *s2, int free);
char				*ft_strmapi(const char *s, char (*f)(unsigned int, char));
char				*ft_strtrim(const char *s1, const char *set);
char				*ft_strdup(const char *str);
char				*ft_strwcdup(char *src, char c);
char				*ft_strndup(const char *s, size_t n);
t_bool				ft_stris(char *str, int (*f)(int));
size_t				ft_strlen(const char *str);
size_t				ft_strnlen(const char *str, size_t maxlen);
size_t				ft_strlcpy(char *dest, const char *src, size_t size);
size_t				ft_strlcat(char *dest, const char *src, size_t size);

/*
**┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓
**┃                        Function : Linked list                             ┃
**┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛
*/

int					ft_lstsize(t_list *list);
void				ft_lstadd_back(t_list **alst, t_list *new);
void				ft_lstdelone(t_list *lst, void (*del)(void *));
void				ft_lstadd_front(t_list **alst, t_list *new);
void				ft_lstiter(t_list *lst, void (*f)(void *));
t_list				*ft_lstlast(t_list *lst);
t_list				*ft_lstnew(void *content);

/*
**┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓
**┃                            Function : Memory                              ┃
**┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛
*/

void				ft_memdel(void **ptr);
void				ft_bzero(void *s, size_t n);
int					ft_memcmp(const void *s1, const void *s2, size_t n);
void				*ft_memset(void *s, int c, size_t n);
void				*ft_memccpy(void *dest, const void *src, int c, size_t n);
void				*ft_memcpy(void *dest, const void *src, size_t n);
void				*ft_memmove(void *dest, const void *src, size_t n);
void				*ft_memchr(const void *s, int c, size_t n);
void				*ft_calloc(size_t nb, size_t size);
void				*ft_memalloc(size_t size);
void				*ft_realloc(void *ptr, size_t size);

/*
**┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓
**┃                            Function : Math                                ┃
**┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛
*/

int					ft_atoi(const char *str);
char				*ft_ftoa(double fl, int second_part);
char				*ft_itoa(int n);
char				*ft_itoa_base(int n, int ibase);
char				*ft_itoa_u_base(unsigned int n, char *base);
char				*ft_itoa_ll_base(unsigned long n, char *base);
void				ft_putnbr_base(int nbr, char *base);
void				ft_putnbr_fd(int n, int fd);

#endif
