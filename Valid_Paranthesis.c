#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define MAX 10000  // Maximum possible string length

bool isValid(char *s) {
    char stack[MAX];
    int top = -1;

    for (int i = 0; s[i] != '\0'; i++) {
        char ch = s[i];

        // If it's an opening bracket, push to stack
        if (ch == '(' || ch == '{' || ch == '[') {
            stack[++top] = ch;
        } 
        // If it's a closing bracket, check top of stack
        else {
            if (top == -1) return false;  // No opening bracket available

            char topChar = stack[top--];  // Pop the top element

            // Check for matching type
            if ((ch == ')' && topChar != '(') ||
                (ch == '}' && topChar != '{') ||
                (ch == ']' && topChar != '[')) {
                return false;
            }
        }
    }

    // Stack should be empty at the end
    return top == -1;
}

int main() {
    char s[100];
    printf("Enter a string of brackets: ");
    scanf("%s", s);

    if (isValid(s))
        printf("Valid\n");
    else
        printf("Invalid\n");

    return 0;
}
