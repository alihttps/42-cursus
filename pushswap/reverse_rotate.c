#include "push_swap.h"

void reverse_rotate (t_stack **stack)
{
    t_stack *tmp;
    t_stack *tail;
    t_stack *before_tail;

    if (!*stack || !(*stack)->next)
		return ;
    tail = get_tail(*stack);
    before_tail = get_before_tail(*stack);

    tmp = *stack;
    *stack = tail;
    (*stack)->next = tmp;
    before_tail->next = NULL;
}

void rra (t_stack **a)
{
    reverse_rotate(a);
    ft_putstr("rra\n");
}

void rrb (t_stack **b)
{
    reverse_rotate(b);
    ft_putstr("rra\n");
}

void rrr (t_stack **a , t_stack **b)
{
    reverse_rotate(a);
    reverse_rotate(b);
    ft_putstr("rrr\n");
}

void reverse_rotate_both (t_stack **a,  t_stack **b, t_stack *cheapest_node)
{
    while (*a != cheapest_node && *b != cheapest_node->target)
    {
        rrr(a, b);
    }
    current_index(*a);
    current_index(*b);
}