#include "push_swap.h"

void rotate(t_stack **stack)
{
    t_stack *tmp;
    t_stack *tail;

    tmp = *stack;
    tail = get_tail(*stack);
    *stack = (*stack)->next;
    tmp->next = NULL;
    tail->next = tmp;
}

