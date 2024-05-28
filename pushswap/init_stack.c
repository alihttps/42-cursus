#include "push_swap.h"

long ft_atoi (char *av)
{
    long result = 0;
    int sign = 1;
    int i = 0;

    while (is_space(av[i]))
        i++;
    if (av[i] == '-' || av[i] == '+')
    {
        if (av[i] == '-')
            sign = -1;
        i++;
    }
    
    while (is_digit(av[i]))
    {
        result = result * 10 + (av[i] - '0');
        i++;
    }
    return result * sign;
}

void add_bottom(t_stack **stack, int n)
{
    t_stack *new_node;
    t_stack *tail;

    if (!stack)
        return;
    new_node = malloc (sizeof (t_stack));
    if (!new_node)
        return;
    new_node->next = NULL;
    new_node->data = n;
    if(!(*stack))
    {
        *stack = new_node;
        new_node->prev = NULL;
    }
    tail = get_tail(*stack);
    tail->next = new_node;
    new_node->prev = tail;
}

void init_stack_a (t_stack **a, char **av)
{
    long n;
    int i;

    i = 0;
    while (av[i])
    {
        if (error_syntax(av[i]))
            free_error(a);
        n = ft_atoi(av[i]);
        if (n > INT_MAX || n < INT_MIN)
            free_error(a);
        if (error_duplicate(*a, (int)n))
            free_error(a);
        add_bottom(a, n);
        i++;
    }
}
