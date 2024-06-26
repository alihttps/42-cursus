#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>
#include <limits.h>
#include <unistd.h>
#include <string.h>

typedef struct s_stack 
{
    int data;
    int index;
    int cost;
    bool above_median;
    bool cheapest;
    struct s_stack *target;
    struct s_stack *next;
    
} t_stack;

void ft_putstr(char *str);
int	get_stack_size(t_stack	*stack);
t_stack *get_tail (t_stack *stack);
t_stack *get_before_tail (t_stack *stack);
void add_bottom(t_stack **stack, int n);
long	ft_atol(const char *s);
void init_stack_a (t_stack **a, char **av);
bool stack_sorted(t_stack *stack);
t_stack *find_min_value (t_stack *stack);
t_stack *find_max_value (t_stack *stack);
void sort_three (t_stack **a);
void push (t_stack **source, t_stack **dest);
void pa(t_stack **a, t_stack **b);
void pb (t_stack **b, t_stack **a);
void reverse_rotate (t_stack **stack);
void rra (t_stack **a);
void rrb (t_stack **b);
void rrr (t_stack **a , t_stack **b);
void reverse_rotate_both (t_stack **a,  t_stack **b, t_stack *cheapest_node);
void rotate(t_stack **stack);
void ra(t_stack **a);
void rb(t_stack **b);
void rr(t_stack **a, t_stack **b);
void rotate_both (t_stack **a, t_stack **b, t_stack *cheapest_node);
void swap(t_stack **stack);
void sa(t_stack **a);
void sb(t_stack **b);
void ss(t_stack **a, t_stack **b);
void init_nodes_a(t_stack *a, t_stack *b);
void current_index (t_stack *stack);
void set_target_a (t_stack *a, t_stack *b);
void cost_calculation_a (t_stack *a, t_stack *b);
void set_cheapest (t_stack *stack);
t_stack	*get_cheapest(t_stack *stack);
void push_a_to_b (t_stack **a, t_stack **b);
void push_b_to_a (t_stack **a, t_stack **b);
void prep_for_push (t_stack **stack , t_stack *top_node , char stack_name);
void init_nodes_b(t_stack *a, t_stack *b);
void set_target_b(t_stack *a, t_stack *b);
void min_on_top (t_stack **a);
void sort_stack(t_stack **a, t_stack **b);
char **ft_split(char const *s, char sep);
void free_stack (t_stack **stack);



int is_digit(int av);
int is_space (int av);

#endif