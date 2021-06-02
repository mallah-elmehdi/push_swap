#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# define ERROR -1
# define SUCCESS 0
# define MAXINT 2147483647
# define MININT -2147483648

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>

int		syntax(char **str);
int		duplicate(char **str);
int		maxint(char **str);
int		error(void);

int		get_down(int *list, int max);
int		get_up(int *list, int max);

int		*get_stack_a(char **str);

int		check_stack(int *list, int max);
int		get_max_index(int *list);
int		get_min_index(int *list);
int		delim(char **str);
int		sort(char **str);
int		sorted(int *list, int vect);
int		ft_strlen(char *str);
int		arrlen(int *list);
int		ft_strcmp(const char *str1, const char *str2);
int		is_num(char c);
int		get_data_element(char *str, char **temp);
int		has_space(char *str);
int		ft_strlen_v2(char **str);
int		*get_list_index(char **str);
int     check_error(char **str);
int		*get_stack_b(char **str);
char	*ft_calloc(int a, int b);
char	*ft_strdup(char *str);
char	*ft_strcdup(char *str);
// char	**get_list(char **str);
char	**get_data(char **str);
char	**ft_calloc_v2(int a, int b);
void	sort_all(int *stack_a, int *stack_b);
void	sort_a(int *stack_a, int *stack_b);
void	sort_num(int *stack_a, int *stack_b, int max);
void	get_num_data(char **str, int *temp);
void	case_3(int *list, char c);
void	case_5(int *stack_a, int *stack_b);
void	s(int *list, char ins);
void	rr(int *list, char ins);
void	r(int *list, char ins);
void	p(int *from, int *to, char ins);
void	move_list(int *list);
void	free_2(char **str);
long	ft_atoi(char *str);
#endif