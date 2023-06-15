/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zvan-de- <zvan-de-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 11:37:21 by zvan-de-          #+#    #+#             */
/*   Updated: 2023/06/15 12:48:53 by zvan-de-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include	<stdlib.h>
# include	<string.h>
# include	<unistd.h>
# include	<stddef.h>
# include	<stdarg.h>
# include	<limits.h>
# include	<stdint.h>

# define BUFFER_SIZE 100

typedef struct s_node	t_node;

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;

/*Alpha_digit*********************************/
int			ft_isalpha(int c);
int			ft_isdigit(int c);
int			ft_isalnum(int c);
int			ft_isascii(int c);
int			ft_isprint(int c);
int			ft_toupper(int c);
int			ft_tolower(int c);

/*Memory*********************************/
void		ft_bzero(void *s, size_t n);
void		*ft_memchr(const void *s, int c, size_t n);
int			ft_memcmp(const void *s1, const void *s2, size_t n);
void		*ft_memcpy(void *dst, const void *src, size_t n);
void		*ft_memmove(void *dst, const void *src, size_t len);
void		*ft_memset(void *b, int c, size_t len);

/*STRING*********************************/
void		ft_striteri(char *s, void (*f)(unsigned int, char *));
int			ft_strncmp(const char *s1, const char *s2, size_t n);
size_t		ft_strlen(const char *s);
size_t		ft_strlcpy(char *dst, const char *src, size_t dstsize);
size_t		ft_strlcat(char *dst, const char *src, size_t dstsize);
char		*ft_strchr(const char *s, int c);
char		*ft_strrchr(const char *s, int c);
char		*ft_strnstr(const char *haystack, const char *needle, size_t len);
char		*ft_strdup(const char *s);
char		*ft_substr(char const *s, unsigned int start, size_t len);
char		*ft_strjoin(char const *s1, char const *s2);
char		*ft_strtrim(char const *s1, char const *set);
char		**ft_split(char const *s, char c);
int			ft_strisdigit(char *str);

/*Utils*********************************/
char		*ft_strmapi(char const *s, char (*f)(unsigned int, char));
void		ft_putchar_fd(char c, int fd);
void		ft_putstr_fd(char *s, int fd);
void		ft_putendl_fd(char *s, int fd);
void		ft_putnbr_fd(int n, int fd);
char		*ft_itoa(int n);
void		ft_putnbr_base(int nbr, char *base);
long int	ft_atol(const char *nptr);
void		*ft_calloc(size_t nmemb, size_t size);
void		ft_swap(int *a, int *b);
void		ft_free_ar(char **ar);
void		ft_printmap(char **map);
int			ft_atoi(const char *nptr);

/*LIST*********************************/
t_list		*ft_lstnew(void *content);
void		ft_lstadd_front(t_list **lst, t_list *new);
int			ft_lstsize(t_list *lst);
t_list		*ft_lstlast(t_list *lst);
void		ft_lstadd_back(t_list **lst, t_list *new);
void		ft_lstdelone(t_list *lst, void (*del)(void*));
void		ft_lstclear(t_list **lst, void (*del)(void*));
void		ft_lstiter(t_list *lst, void (*f)(void *));
t_list		*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));

/*PRINTF*********************************/
int			ft_printf(const char *s, ...);
size_t		ft_strlen(const char *s);
void		ft_putchar(char c);
int			ft_putnbr_pf(int n, int count);
int			ft_putstr(char *str);
int			ft_putunsing(unsigned int n, int count);
int			ft_putnbr_base_pf(unsigned int nbr, int count, int b);
int			ft_printadr(va_list *args);

/*GNL*********************************/
char		*get_next_line(int fd);
char		*ft_make_line(char *s, char *nl);
char		*ft_stash(char *stash_ptr);
char		*ft_readline(char *s, int fd);
size_t		ft_strlen_gnl(const char *s);
void		*ft_calloc_gnl(size_t nmemb, size_t size);
char		*ft_strjoin_gnl(char *s1, char *s2, int r);
int			strchr_gnl(const char *s, int c);
int			ft_strlcpy_gnl(char *dst, char *src, int dstsize);
void		*calloc_gnl(size_t nmemb, size_t size);
char		*ft_free_gnl(char *s);

#endif
