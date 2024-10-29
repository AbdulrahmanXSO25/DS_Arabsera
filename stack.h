#define MAX_STACK 100

typedef int StackEntry;

typedef struct stack
{
    int top;
    StackEntry entry[MAX_STACK];
} Stack;

void Stack_init(Stack *);

void Stack_push(StackEntry, Stack *);

void Stack_pop(StackEntry *, Stack *);

int Stack_empty(Stack *);

int Stack_full(Stack *);

void Stack_top(StackEntry *,Stack *);

int Stack_size(Stack *);

void Stack_clear(Stack *);

void Stack_traverse(Stack *, void (*) (StackEntry));