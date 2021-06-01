#ifndef CHECKER_H
# define CHECKER_H

# include "push_swap.h"

void	update_temp(char *temp);
void	result(int *stack_a, int *stack_b);
int		ins_a(int *stack_a, int *stack_b, char *temp);
int		ins_b(int *stack_a, int *stack_b, char *temp);
int		ins_ab(int *stack_a, int *stack_b, char *temp);
int		exec_ins(int *stack_a, int *stack_b, char *temp);
int		read_data(char **str, char *temp);

#endif