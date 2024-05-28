#include "push_swap.h"

t_stack *create_node(int value)
{
    t_stack *new_node = (t_stack *)malloc(sizeof(t_stack));
    if (!new_node)
        return NULL;
    new_node->data = value;
    new_node->next = NULL;
    return new_node;
}

int	get_stack_size(t_stack	*stack)
{
	int	size;

	size = 0;
	if (!stack)
		return (0);
	while (stack)
	{
		stack = stack->next;
		size++;
	}
	return (size);
}

t_stack *get_tail (t_stack *stack)
{
    if (!stack)
        return NULL;
    while (stack->next)
    {
        stack = stack->next;
    }
    return stack;
}

void add_bottom(t_stack **stack, int n)
{
    t_stack *new_node;
    t_stack *tail;

    if (!stack)
        return;
    new_node = malloc (sizeof (t_stack));
    new_node->next = NULL;
    new_node->data = n;
    if(!*stack)
    {
        *stack = new_node;
        new_node->prev = NULL;
        return;
    }
    tail = get_tail(*stack);
    tail->next = new_node;
}

int main ()
{
    t_stack *stack = NULL;
    t_stack *node1 = create_node(1);
    t_stack *node2 = create_node(2);
    t_stack *node3 = create_node(3);
    t_stack *node4 = create_node(4);

    add_bottom (&stack, node1);
    add_bottom (&stack, node2);
    add_bottom (&stack, node3);
    add_bottom (&stack, node4);

    swap(&stack);
    //rotate (&stack);

    t_stack *current = stack;
    while (current != NULL)
    {
        printf ("%d\n", current->data);
        current = current->next;
        free (current);
    }
}
