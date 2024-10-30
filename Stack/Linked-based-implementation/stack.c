#define LINKED_STACK

#include "stack.h"
#include "stdlib.h"

void Stack_init(Stack *sp)
{
    sp->top = NULL; // == (*sp).top = NULL;
    sp->size = 0;
}

void Stack_push(StackEntry e, Stack *sp)
{
    StackNode np = (StackNode)malloc(sizeof(struct stacknode));
    
    if (!np) {
        printf("Error: Memory allocation failed. Unable to push element onto stack.\n");
        return;
    }

    np->entry = e;
    np->next = sp->top;

    sp->top = np;
    sp->size++;
}

void Stack_pop(StackEntry *e, Stack *sp)
{
    StackNode temp_pn;

    *e = sp->top->entry;

    temp_pn = sp->top;

    sp->top = sp->top->next;

    free(temp_pn);
    sp->size--;
}

int8_t Stack_empty(Stack *sp)
{
    return sp->size == 0;
}

int8_t Stack_full(Stack *sp)
{
    UNUSED(sp);
    return 0;
}

void Stack_top(StackEntry *e,Stack *sp)
{
    *e = sp->top->entry;
}

size_t Stack_size(Stack *sp)
{
    return sp->size;
}

void Stack_clear(Stack *sp)
{
    StackNode temp_np;

    while(sp->top) {
        temp_np = sp->top;
        sp->top = temp_np->next;
        free(temp_np);
    }

    sp->size = 0;
}

void Stack_traverse(Stack *sp, void (*fp) (StackEntry e))
{
    StackNode top_np = sp->top;

    while(top_np) {
        (*fp)(top_np->entry);
        top_np = top_np->next;
    }
}