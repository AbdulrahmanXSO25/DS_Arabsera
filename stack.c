#include "stack.h"
#include <stdio.h>

void Stack_init(Stack *sp)
{
    sp->top = -1;
}

void Stack_push(StackEntry e, Stack *sp)
{
    if (sp->top < (MAX_STACK - 1))
        sp->entry[++sp->top] = e;
    else
        printf("Error: Stack overflow\n");
}

void Stack_pop(StackEntry *e, Stack *sp)
{
    if (sp->top >= 0)
        *e = sp->entry[sp->top--];
    else
        printf("Error: Stack underflow\n");
}

int Stack_empty(Stack *sp)
{
    return sp->top < 0;
}

int Stack_full(Stack *sp)
{
    return sp->top >= (MAX_STACK - 1);
}

void Stack_top(StackEntry *e,Stack *sp)
{
    *e = sp->entry[sp->top];
}

int Stack_size(Stack *sp)
{
    return (sp->top + 1);
}

void Stack_clear(Stack *sp)
{
    sp->top = -1;
}

void Stack_traverse(Stack *sp, void (*pf) (StackEntry e))
{
    for(int i = 0; i <= sp->top; i++)
        pf(sp->entry[i]);
}