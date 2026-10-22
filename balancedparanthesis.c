#include <stdio.h>

#define MAX 100

char stack[MAX];
int top = -1;

void push(char ch) {
    stack[++top] = ch;
}

char pop() {
    if (top == -1) return '\0';
    return stack[top--];
}

int checkBalanced(char exp[]) {
    for (int i = 0; exp[i] != '\0'; i++) {
        char ch = exp[i];

        if (ch == '(' || ch == '{' || ch == '[') {
            push(ch);
        } else if (ch == ')' || ch == '}' || ch == ']') {
            if (top == -1) return 0;
            char open = pop();
            if (ch == ')' && open != '(') return 0;
            if (ch == '}' && open != '{') return 0;
            if (ch == ']' && open != '[') return 0;
        }
    }
    return top == -1; // 1 if balanced, 0 if not
}

int main() {
    char exp[MAX];
    printf("Enter expression with brackets: ");
    scanf("%s", exp);

    if (checkBalanced(exp)) {
        printf("Balanced Parentheses.\n");
    } else {
        printf("Not Balanced.\n");
    }

    return 0;
}