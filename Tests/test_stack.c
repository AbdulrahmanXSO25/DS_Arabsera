#include "tests.h"

void print_stack_entry(StackEntry e) {
    printf("%d ", e);
}

void test_Stack() {

    #ifdef LINKED_STACK
        printf("Testing stack using linked-based implementation.\n");
    #else
        printf("Testing stack using array-based implementation.\n");
    #endif
    
    Stack myStack;
    StackEntry value;
    int i;

    Stack_init(&myStack);

    if (Stack_empty(&myStack)) {
        printf("The stack is empty.\n");
    }

    printf("Pushing values 1 to 10 onto the stack...\n");
    for (i = 1; i <= 10; i++) {
        if (!Stack_full(&myStack)) {
            Stack_push(i, &myStack);
            printf("Pushed %d\n", i);
        } else {
            printf("Stack is full; can't push %d.\n", i);
            break;
        }
    }

    printf("Stack size after pushes: %zu\n", Stack_size(&myStack));

    Stack_top(&value, &myStack);
    printf("Top element after pushes: %d\n", value);

    printf("Traversing stack: ");
    Stack_traverse(&myStack, print_stack_entry);
    printf("\n");

    for (i = 0; i < 2; i++) {
        if (!Stack_empty(&myStack)) {
            Stack_pop(&value, &myStack);
            printf("Popped %d\n", value);
        } else {
            printf("Stack is empty; nothing to pop.\n");
            break;
        }
    }

    printf("Stack size after pops: %zu\n", Stack_size(&myStack));

    printf("Clearing the stack...\n");
    Stack_clear(&myStack);

    if (Stack_empty(&myStack)) {
        printf("The stack is now empty after clearing.\n");
    }
}