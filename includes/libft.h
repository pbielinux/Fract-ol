/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbielik <pbielik@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/15 16:50:09 by pbielik           #+#    #+#             */
/*   Updated: 2021/08/03 22:01:34 by pbielik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define	LIBFT_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <limits.h>

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}	t_list;

int					ft_atoi(const char *s);
void				ft_bzero(void *str, size_t n);
void				*ft_calloc(size_t n, size_t n_size);
int					ft_isalnum(int c);
int					ft_isalpha(int c);
int					ft_isascii(int c);
int					ft_isdigit(int c);
int					ft_isprint(int c);
int					ft_isspace(int c);
int					ft_isupper(int c);
char				*ft_itoa(int n);
void				*ft_memccpy(void *dest, const void *src, int c, size_t n);
void				*ft_memchr(const void *str, int c, size_t n);
int					ft_memcmp(const void *str1, const void *str2, size_t n);
void				*ft_memcpy(void *dest, const void *src, size_t n);
void				*ft_memmove(void *dest, const void *src, size_t n);
void				*ft_memset(void *str, char c, size_t n);
void				ft_putchar_fd(char c, int fd);
void				ft_putchar(char c);
void				ft_putendl_fd(char const *s, int fd);
void				ft_putendl(char const *s);
void				ft_putnbr_fd(int n, int fd);
void				ft_putnbr(int n);
void				ft_putstr_fd(char const *s, int fd);
void				ft_putstr(char const *s);
char				**ft_split(const char *str, char c);
char				*ft_strchr(const char *str, int c);
char				*ft_strcpy(char *dest, const char *src);
char				*ft_strdup(const char *str);
char				*ft_strjoin(const char *s1, const char *s2);
char				*ft_strcat(char	*dst, const char	*src);
size_t				ft_strlcat(char *dest, const char *src, size_t maxlen);
size_t				ft_strlcpy(char *dest, const char *src, size_t maxlen);
size_t				ft_strlen(const char *str);
char				*ft_strmap(char const *s, char (*f)(char));
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));
int					ft_strncmp(const char *str1, const char *str2, size_t n);
char				*ft_strndup(const char *str, size_t n);
char				*ft_strnstr(const char *str1, const char *str2, size_t n);
char				*ft_strrchr(const char *s, int c);
char				*ft_strstr(const char *str1, const char *str2);
char				*ft_strtrim(const char *s1, const char *set);
char				*ft_substr(const char *s, unsigned int start, size_t len);
int					ft_tolower(int c);
int					ft_toupper(int c);
int					ft_wrdcnt(const char *str, char c);
int					ft_counter(int n);
size_t				ft_strnlen(const char *str, size_t maxlen);
t_list				*ft_lstnew(void *content);
void				ft_lstadd_front(t_list **lst, t_list *new);
int					ft_lstsize(t_list *lst);
t_list				*ft_lstlast(t_list *lst);
void				ft_lstadd_back(t_list **lst, t_list *new);
void				ft_lstdelone(t_list *lst, void (*del)(void *));
void				ft_lstclear(t_list **lst, void (*del)(void *));
void				ft_lstiter(t_list *lst, void (*f)(void *));
t_list				*ft_lstmap(t_list *lst, void *(*f)(void *),
						void (*del)(void *));
int					ft_numLength(long n);
int					ft_numLengthBase(unsigned long n, int base);
char				*ft_uitoa(unsigned int n);
int					ft_putnbrBase(unsigned long n, char *base);
long				ft_strtol(const char *nptr, char **endptr, int base);

#endif
