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