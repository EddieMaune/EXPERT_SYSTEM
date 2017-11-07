/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaune <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/30 07:47:23 by emaune            #+#    #+#             */
/*   Updated: 2017/10/17 17:04:13 by emaune           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <unistd.h>
# include <string.h>
# include "get_next_line.h"
# include <stdlib.h>

typedef	struct		s_trim
{
	size_t			sz;
	size_t			i;
	int				start;
	char			*result;
}					t_trim;

typedef struct		s_split
{
	int				i;
	int				j;
	int				w;
	char			**ret;
	char			*trim;
	char			*temp;
}					t_split;

typedef struct		s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}					t_list;

typedef struct		s_lcat
{
	size_t			i;
	size_t			dstlen;
	size_t			srclen;
}					t_lcat;

void				ft_putchar(char c);
void				ft_putstr(char const *str);
void				ft_putnbr(int n);
void				ft_putnbr_fd(int n, int fd);
void				ft_bzero(void *str, unsigned int n);
void				*ft_memset(void *str, int c, unsigned int n);
void				*ft_memcpy(void *dest, const void *src, unsigned int n);
void				*ft_memccpy(void *dest, const void *src, int c,
					unsigned int n);
void				*ft_memmove(void *dest, const void *src, size_t n);
void				*ft_memchr(const void *str, unsigned int c, unsigned int n);
int					ft_memcmp(const void *s1, const void *s2, size_t n);
size_t				ft_strlen(const char *str);
char				*ft_strdup(const char *s1);
char				*ft_strcpy(char *dest, const char *src);
char				*ft_strncpy(char *dest, const char *src, size_t len);
char				*ft_strcat(char *dest, const char *src);
char				*ft_strncat(char *dest, const char *src, size_t len);
char				*ft_strchr(const char *str, int c);
char				*ft_strrchr(const char *str, int c);
char				*ft_strrev(char *str);
char				*ft_strstr(char *big, const char *little);
char				*ft_strjoin(char const *s1, char const *s2);
char				*ft_strsub(char const *s, unsigned int start, size_t len);
size_t				ft_strlcat(char *dest, const char *src, size_t size);
int					ft_strcmp(const char *s1, const char *s2);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
int					ft_atoi(const char *str);
int					ft_toupper(int c);
int					ft_tolower(int c);
int					ft_isdigit(int c);
int					ft_isupper(int c);
int					ft_islower(int c);
int					ft_isalpha(int c);
int					ft_isalnum(int c);
int					ft_isascii(int c);
int					ft_isprint(int c);
int					ft_isspace(int c);
void				*ft_memalloc(size_t size);
void				ft_memdel(void **ap);
char				*ft_strnew(size_t size);
void				ft_strdel(char **as);
void				ft_strclr(char *str);
void				ft_striter(char *s, void (*f)(char *));
void				ft_striteri(char *s, void (*f)(unsigned int, char *));
void				ft_putchar_fd(char c, int fd);
void				ft_putstr_fd(char const *c, int fd);
void				ft_putendl(char const *s);
void				ft_putendl_fd(char const *s, int fd);
int					ft_strequ(char const *s1, char const *s2);
int					ft_strnequ(char const *s1, char const *s2, size_t n);
char				*ft_strtrim(char const *s);
char				**ft_strsplit(char const *s, char c);
char				*ft_strmap(char const *s, char (*f) (char));
char				*ft_strmapi(char const *s, char (*f) (unsigned int, char));
char				*ft_strnstr(const char *little,
		const char *big, size_t len);
char				*ft_itoa(int n);
t_list				*ft_lstnew(void const *content, size_t content_size);
void				ft_lstdelone(t_list **alst, void (*del)(void *, size_t));
void				ft_lstdel(t_list **alst, void (*del)(void *, size_t));
void				ft_lstadd(t_list **alst, t_list *new);
void				ft_lstiter(t_list *lst, void (*f)(t_list *elem));
t_list				*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));

#endif
