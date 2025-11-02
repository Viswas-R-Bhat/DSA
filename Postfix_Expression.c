#include <stdio.h>
#include <ctype.h>

#define MAX 50

int stack[MAX];
int top = -1;

void push(int x) {
    stack[++top] = x;
}

int pop() {
    return stack[top--];
}

int evaluatePostfix(char exp[]) {
    int i;
    char ch;
    int val1, val2;

    for (i = 0; exp[i] != '\0'; i++) {
        ch = exp[i];

        if (isdigit(ch)) {
            // Convert char to int and push
            push(ch - '0');
        } 
        else if (ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '%') {
            val2 = pop();
            val1 = pop();

            switch (ch) {
                case '+': push(val1 + val2); break;
                case '-': push(val1 - val2); break;
                case '*': push(val1 * val2); break;
                case '/': push(val1 / val2); break;
                case '%': push(val1 % val2); break;
            }
        }
    }

    return pop();
}

int main() {
    char exp[MAX];

    printf("Enter a postfix expression: ");
    scanf("%s", exp);

    printf("Result of postfix expression = %d\n", evaluatePostfix(exp));

    return 0;
}
