#include "push_swap.h"

void rotate(t_stack **stack)
{
    t_stack *tmp;
    t_stack *tail;

    if (!*stack || !(*stack)->next)
        return;
    tmp = *stack;
    tail = get_tail(*stack);
    *stack = (*stack)->next;
    tmp->next = NULL;
    tail->next = tmp;
}

void ra(t_stack **a)
{
    rotate (a);
    ft_putstr("ra\n");
}
void rb(t_stack **b)
{
    rotate (b);
    ft_putstr("rb\n");
}
void rr(t_stack **a, t_stack **b)
{
    rotate (a);
    rotate (a);
    ft_putstr("rr\n");
}

void rotate_both (t_stack **a, t_stack **b, t_stack *cheapest_node)
{
    while (*a != cheapest_node && *b != cheapest_node->target)
    {
        rr(a, b);
    }
    current_index(*a);
    current_index(*b);
}
