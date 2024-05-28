#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>
#include <limits.h>

typedef struct s_stack 
{
    int data;
    int index;
    int cost;
    bool above_median;
    bool cheapest;
    struct s_stack *target;
    struct s_stack *next;
    struct s_stack *prev;
    
} t_stack;

#endif