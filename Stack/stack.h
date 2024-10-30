#ifndef STACK_H
#define STACK_H

#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include "../Include/include.h"

typedef int StackEntry;

#ifdef LINKED_STACK

struct stacknode {
    StackEntry entry;
    struct stacknode *next;
};

typedef struct stacknode* StackNode;

typedef struct stack {
    StackNode top;
    size_t size;
} Stack;

#else // ARRAY_BASED_STACK

#define MAX_STACK 100

typedef struct stack {
    int top;
    StackEntry entry[MAX_STACK];
} Stack;

#endif // LINKED_STACK

void Stack_init(Stack *);

void Stack_push(StackEntry, Stack *);

void Stack_pop(StackEntry *, Stack *);

int8_t Stack_empty(Stack *);

int8_t Stack_full(Stack *);

void Stack_top(StackEntry *,Stack *);

size_t Stack_size(Stack *);

void Stack_clear(Stack *);

void Stack_traverse(Stack *, void (*) (StackEntry));

#endif // STACK_H