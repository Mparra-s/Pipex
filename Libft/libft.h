/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mparra-s <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 12:19:02 by mparra-s          #+#    #+#             */
/*   Updated: 2025/04/28 09:28:57 by mparra-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H 

# include <stdio.h>
# include <unistd.h>
# include <string.h>
# include <fcntl.h>
# include <stdlib.h>
# include <limits.h>
# include <stdarg.h>

int		ft_isalnum(int alnum);
int		ft_isalpha(int alpha);
int		ft_isdigit(int num);
int		ft_isascii(int ascii);
int		ft_isprint(int print);
int		ft_tolower(int letter);
int		ft_toupper(int letter);
char	*ft_strchr(const char *str, int c);
size_t	ft_strlcat(char *dest, const char *src, size_t size);
size_t	ft_strlcpy(char *dest, const char *src, size_t size);
int		ft_strlen(const char *str);
int		ft_strncmp(const char *src1, const char *src2, size_t n);
char	*ft_strnstr(const char *str, const char *to_find, size_t len);
char	*ft_strrchr(const char *str, int c);
void	*ft_memchr(const void *scr, int c, size_t len);
int		ft_memcmp(const void *src1, const void *src2, size_t n);
void	*ft_memcpy(void *dest, const void *src, size_t size);
void	*ft_memmove(void *dest, const void *src, size_t size);
void	*ft_memset(void *str, int c, size_t size);
void	ft_bzero(void *src, size_t size);
int		ft_atoi(const char *nptr);
void	*ft_calloc(size_t nmemb, size_t size);
char	*ft_strdup(const char *src);
char	*ft_strtrim(char const *str, char const *set);
char	*ft_substr(char const *src, unsigned int start, size_t len);
char	*ft_strjoin(char const *str1, char const *str2);
char	**ft_split(char const *str, char letter);
char	*ft_itoa(int n);
char	*ft_strmapi(char const *str, char (*fun)(unsigned int, char));
void	ft_striteri(char *str, void (*fun)(unsigned int, char*));
void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *str, int fd);
void	ft_putendl_fd(char *str, int fd);
void	ft_putnbr_fd(int n, int fd);
/*typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}	t_list;

t_list	*ft_lstnew(void *content);
void	ft_lstadd_front(t_list **lst, t_list *new);
int		ft_lstsize(t_list *lst);
t_list	*ft_lstlast(t_list *lst);
void	ft_lstadd_back(t_list **lst, t_list *new);
void	ft_lstclear(t_list **lst, void (*del)(void*));
void	ft_lstdelone(t_list *lst, void (*del)(void*));
void	ft_lstiter(t_list *lst, void (*f)(void *));
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));*/

//Printf
int		ft_printf(char const *str, ...);
int		ft_printf_putchar(va_list vargs, int *count);
int		ft_printf_putstr(va_list vargs, int *count);
int		ft_printf_p(va_list vargs, int *count);
int		ft_printf_putnbr_hex(va_list vargs, int *count, char type);
int		ft_printf_putnbr(va_list vargs, int *count);
int		ft_printf_putnbru(va_list vargs, int *count);
void	ft_putc_fd2(char c, int fd);

#endif
