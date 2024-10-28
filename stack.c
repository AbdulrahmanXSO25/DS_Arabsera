#include <stdio.h>

#define MAX_STACK 100

typedef int StackEntry;

typedef struct stack
{
    int top;
    StackEntry entry[MAX_STACK];
} Stack;

void Stack_init(Stack *sp)
{
    sp->top = -1;
}

/*  Pre: The stack is initialized and not full
    Post: The element `e` has been stored at the top of the stack, and `e` does not change.
*/
void Stack_push(StackEntry e, Stack *sp)
{
    sp->entry[++sp->top] = e;
}

void Stack_print(Stack s)
{
    while (s.top > -1)
    {
        printf("Stack Entry %d: %d\n", s.top, s.entry[s.top]);
        s.top--;
    }
}

int main() {

    Stack s;
    Stack_init(&s);

    StackEntry e1 = 10;

    Stack_push(e1, &s);

    return 0;
}