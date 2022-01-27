/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tblaase <tblaase@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/26 15:06:10 by tblaase           #+#    #+#             */
/*   Updated: 2022/01/27 20:03:09 by tblaase          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <unistd.h>
# include <stdlib.h>
# include <stddef.h>
# include <fcntl.h>
# include <stdbool.h>

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;

char		**ft_add_single_str(char ***arr, int pos, char *new);
int			ft_atoi(const char *str);
long long	ft_atol(char *str);
void		ft_bzero(void *s, size_t n);
void		*ft_calloc(size_t nelem, size_t elsize);
int			ft_count_c(char *str, char c);
int			ft_count_lines(int fd);
void		ft_free_str_array(char ***arr);
void		ft_free_str(char **p);
int			ft_intlen(int n);
int			ft_isalnum(int c);
int			ft_isalpha(int c);
int			ft_isascii(int c);
int			ft_isdigit(int c);
int			ft_isprint(int c);
char		*ft_itoa(int n);
int			ft_line_length(int fd);
void		ft_lstadd_back(t_list **lst, t_list *new);
void		ft_lstadd_front(t_list **lst, t_list *new);
void		ft_lstclear(t_list **lst, void (*del)(void*));
void		ft_lstdelone(t_list *lst, void (*del)(void*));
void		ft_lstiter(t_list *lst, void (*f)(void *));
t_list		*ft_lstlast(t_list *lst);
t_list		*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));
t_list		*ft_lstnew(void *content);
int			ft_lstsize(t_list *lst);
void		*ft_memccpy(void *dst, const void *src, int c, size_t n);
void		*ft_memchr(const void *s, int c, size_t n);
int			ft_memcmp(const void *s1, const void *s2, size_t n);
void		*ft_memcpy(void *dst, const void *src, size_t n);
void		*ft_memmove(void *dst, const void *src, size_t len);
void		*ft_memset(void *s, int c, size_t n);
void		ft_put_unsigned_nbr(unsigned int a);
void		ft_putchar_fd(char c, int fd);
void		ft_putendl_fd(char *s, int fd);
void		ft_putnbr_fd(int n, int fd);
void		ft_putnbr(int n, char *str, unsigned int i);
void		ft_putstr_fd(char *s, int fd);
char		**ft_realloc_str_arr(char **arr, int size);
char		*ft_realloc_str(char *str, int size);
char		**ft_split(const char *s, char c);
char		**ft_str_arr_dup(char **arr);
int			ft_str_arr_len(char **arr);
char		*ft_strchr(const char *s, int c);
char		*ft_strcjoin(const char *s1, const char *s2, char divider);
char		*ft_strdup(const char *s1);
char		*ft_strjoin(char *s1, const char *s2);
size_t		ft_strlcat(char *dst, const char *src, size_t dstsize);
size_t		ft_strlcpy(char *dst, const char *src, size_t dstsize);
size_t		ft_strlen(const char *s);
char		*ft_strmapi(const char *s, char (*f) (unsigned int, char));
int			ft_strncmp(const char *s1, const char *s2, size_t n);
char		*ft_strndup(char *input, int n);
char		*ft_strnjoin(char *s1, char *s2, int n);
char		*ft_strnstr(const char *haystack, const char *needle, size_t len);
char		*ft_strrchr(const char *s, int c);
char		*ft_strstrjoin(char *s1, const char *s2, char *divider);
char		*ft_strtrim(const char *s1, const char *set);
char		*ft_substr(const char *s, unsigned int start, size_t len);
int			ft_tolower(int c);
int			ft_toupper(int c);

// get_next_line

//this part lets you controll the BUFFER_SIZE without adding it when compiling
//this is really usefull when used inside libft
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

void		ft_free_gnl(char **p);
int			ft_strlen_gnl(char *s);
int			ft_strchr_gnl(char *s, int c, int flag);
char		*ft_strnjoin_gnl(char *s1, char *s2, int n);
char		*ft_strndup_gnl(char *str, int n);
void		*ft_calloc_gnl(size_t nelem, size_t elsize);
char		*ft_update_nl_gnl(char **next_line, int position);
char		*ft_output_gnl(char **next_line, int position, int bytes);
char		*get_next_line(int fd);
#endif
