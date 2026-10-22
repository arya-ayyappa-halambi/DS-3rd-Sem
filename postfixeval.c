#include <stdio.h>
#include <ctype.h>
#include <math.h>

#define MAX 100

int stack[MAX];
int top = -1;

void push(int val) {
    stack[++top] = val;
}

int pop() {
    return stack[top--];
}

int evaluatePostfix(char exp[]) {
    for (int i = 0; exp[i] != '\0'; i++) {
        char ch = exp[i];

        if (isdigit(ch)) {
            push(ch - '0');
        } else {
            int op2 = pop();
            int op1 = pop();
            switch (ch) {
                case '+': push(op1 + op2); break;
                case '-': push(op1 - op2); break;
                case '*': push(op1 * op2); break;
                case '/': push(op1 / op2); break;
                case '^': push((int)pow(op1, op2)); break;
            }
        }
    }
    return pop();
}

int main() {
    char exp[MAX];
    printf("Enter Postfix Expression (single digits, e.g., 231*+9-): ");
    scanf("%s", exp);

    int result = evaluatePostfix(exp);
    printf("Evaluation Result: %d\n", result);

    return 0;
}