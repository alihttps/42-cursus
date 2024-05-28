#include "push_swap.h" 

void init_nodes_a(t_stack *a, t_stack *b)
{
    current_index(a);
    current_index(b);
    set_target_a(a, b);
    cost_calculation_a(a, b);
    set_cheapest(a);
}

void current_index (t_stack *stack)
{
    int i = 0;
    int median;

    median = get_stack_size(stack) / 2;
    while (stack)
    {
        stack->index = i;
        if (i <= median)
            stack->above_median = true;
        else
            stack->above_median = false;
        stack = stack->next;
        i++;
    }
}

void set_target_a (t_stack *a, t_stack *b)
{
    t_stack *current_b;
    t_stack *target;
    long best_match_index;

    while (a)
    {
        best_match_index = LONG_MIN;
        current_b = b;
        while (current_b)
        {
            if (current_b->data < a->data && current_b->data > best_match_index)
            {
                best_match_index = current_b->data;
                target = current_b;
            }
            current_b = current_b->next;
        }
        if (best_match_index == LONG_MIN)
            a->target = find_max_value(b);
        else
            a->target = target;
        a = a->next;
    }
}

void cost_calculation_a (t_stack *a, t_stack *b)
{
    int len_a = get_stack_size(a);
    int len_b = get_stack_size(b);

    while (a)
    {
        a->cost = a->index;
        if (!(a->above_median))
        {
            a->cost = len_a - (a->index);
        }
        if(a->target->above_median)
        {
            a->cost += a->target->index; 
        }
        else
        {
            a->cost += len_b - (a->target->index);
        }
        a = a->next;
    }
}

t_stack *set_cheapest (t_stack *stack)
{
    long cheapest_value;
    t_stack *cheapest_node;

    if (!stack)
        return;
    cheapest_value = LONG_MAX;
    while (stack)
    {
        if (stack->cost < cheapest_value)
        {
            cheapest_value = stack->cost;
            cheapest_node = stack;
        }
        stack = stack->next;
    }
    stack->cheapest = true;
    return stack;
}

void push_a_to_b (t_stack **a, t_stack **b)
{
    t_stack *cheapest_node;

    cheapest_node = set_cheapest(*a);
    if (cheapest_node->above_median && cheapest_node->target->above_median)
        rotate_both (a, b, cheapest_node);
    else if (!(cheapest_node->above_median) && !(cheapest_node->target->above_median))
        rev_rotate_both (a, b, cheapest_node);
    prep_for_push (a, cheapest_node, 'a');
    prep_for_push(b, cheapest_node->target, 'b');
    pb(b, a, false);
}

void sort_stack(t_stack **a, t_stack **b)
{
    int a_len;

    a_len = get_stack_size(*a);
    if (a_len > 3 && !stack_sorted(*a))
    {
        pb(a, b, true);
        a_len--;
    }
    if (a_len > 3 && !stack_sorted(*a))
    {
        pb(a, b, true);
        a_len--;
    }
    while (a_len-- > 3 && !stack_sorted(*a))
    {
        init_nodes_a(*a, *b);
        push_a_to_b(a, b);
    }
    sort_three(a);
    while (*b)
    {
        init_nodes_b(*a, *b);
        push_b_to_a(a, b);
    }
    current_index(*a);
    min_on_top(a);
}