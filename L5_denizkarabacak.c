#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

// Stack structure
struct Stack {
    int top;
    char items[MAX_SIZE];
};

// Function prototypes
void init(struct Stack *s);
void push(struct Stack *s, char c);//first four given in instrcutions
char pop(struct Stack *s);
char peek(struct Stack *s);

int is_empty(struct Stack *s);//This function returns 1 if the stack is empty and 0 otherwise.
int is_full(struct Stack *s);//This function returns 1 if the stack is full and 0 otherwise.
int is_matching_pair(char c1, char c2);//This function takes two characters as input and returns 1 if they form a matching pair of opening and closing brackets  and 0 otherwise.
int is_balanced(char exp[]);//This function takes a string expression as input and uses a stack to check if the expression is balanced 

// Initialize stack
void init(struct Stack *s) {
    s->top = -1;
}

// Push op
void push(struct Stack *s, char c) {
    if (is_full(s)) {
        printf("Stack overflow\n");
        exit(EXIT_FAILURE);
    }
    s->items[++(s->top)] = c;
}

// Pop op
char pop(struct Stack *s) {
    if (is_empty(s)) {
        printf("Stack underflow\n");
        exit(EXIT_FAILURE);
    }
    return s->items[(s->top)--];
}

// Peek op
char peek(struct Stack *s) {
    if (is_empty(s)) {
        printf("Stack is empty\n");
        exit(EXIT_FAILURE);
    }
    return s->items[s->top];
}

// Check stack is empty
int is_empty(struct Stack *s) {
    return (s->top == -1);
}

// Check stack is full
int is_full(struct Stack *s) {
    return (s->top == MAX_SIZE - 1);
}

// Check two characters form a matching pair
int is_matching_pair(char c1, char c2) {
    if (c1 == '(' && c2 == ')')
        return 1;
    else if (c1 == '{' && c2 == '}')
        return 1;
    else if (c1 == '[' && c2 == ']')
        return 1;
    else
        return 0;
}

// Check is balanced
int is_balanced(char exp[]) {
    struct Stack s;
    init(&s);
    int i;
    for (i = 0; i < strlen(exp); i++) {
        if (exp[i] == '(' || exp[i] == '{' || exp[i] == '[')
            push(&s, exp[i]);
        else if (exp[i] == ')' || exp[i] == '}' || exp[i] == ']') {
            if (is_empty(&s) || !is_matching_pair(pop(&s), exp[i]))
                return 0;
        }
    }
    return is_empty(&s);
}

// take input print output(debugg ?)
int main() {
    char exp[MAX_SIZE];
    printf("Enter an expression: ");
    fgets(exp, MAX_SIZE, stdin);
    if (is_balanced(exp))
        printf("Balanced\n");
    else
        printf("Not Balanced\n");
    return 0;
}
