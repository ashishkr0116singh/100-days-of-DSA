#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

// Node structure for stack
typedef struct Node {
    int data;
    struct Node* next;
} Node;

// Push function
void push(Node** top, int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (!newNode) {
        printf("Memory allocation failed\n");
        exit(1);
    }
    newNode->data = value;
    newNode->next = *top;
    *top = newNode;
}

// Pop function
int pop(Node** top) {
    if (*top == NULL) {
        printf("Stack underflow\n");
        exit(1);
    }
    Node* temp = *top;
    int value = temp->data;
    *top = (*top)->next;
    free(temp);
    return value;
}

// Function to evaluate postfix expression
int evaluatePostfix(char* expression) {
    Node* stack = NULL;
    char* token = strtok(expression, " ");

    while (token != NULL) {
        if (isdigit(token[0])) {
            // Operand → push to stack
            push(&stack, atoi(token));
        } else {
            // Operator → pop two operands
            int val2 = pop(&stack);
            int val1 = pop(&stack);
            int result;

            switch (token[0]) {
                case '+': result = val1 + val2; break;
                case '-': result = val1 - val2; break;
                case '*': result = val1 * val2; break;
                case '/': result = val1 / val2; break;
                default:
                    printf("Invalid operator: %s\n", token);
                    exit(1);
            }
            push(&stack, result);
        }
        token = strtok(NULL, " ");
    }

    return pop(&stack);
}

int main() {
    char expression[100];

    printf("Enter postfix expression (space separated):\n");
    fgets(expression, sizeof(expression), stdin);

    // Remove newline character if present
    expression[strcspn(expression, "\n")] = '\0';

    int result = evaluatePostfix(expression);
    printf("Result: %d\n", result);

    return 0;
}