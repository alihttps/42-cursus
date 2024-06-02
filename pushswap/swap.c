#include "push_swap.h"

void swap(t_stack **stack)
{
    int tmp;
    if (*stack == NULL || (*stack)->next == NULL)
        return;
    tmp = (*stack)->data;
    (*stack)->data = (*stack)->next->data;
    (*stack)->next->data = tmp; 
}

void sa(t_stack **a)
{
    swap(a);
    ft_putstr ("sa\n");
}

void sb(t_stack **b)
{
    swap(b);
    ft_putstr ("sb\n");
}

void ss(t_stack **a, t_stack **b)
{
    swap(a);
    swap(b);
    ft_putstr("ss\n");
}