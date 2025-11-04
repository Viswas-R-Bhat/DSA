#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX 100

char stack[MAX];
int top = -1;

void push(char c) {
    if (top==MAX-1){
        printf("Stack Overflow!!");
    }
    else{
        stack[++top] = c; 
    }
}
char pop() {
    if (top==-1){
        printf("Stack Underflow!!");
    }
    else{
        return stack[top--]; 
    }
}

int isPalindrome(char str[]) {
    char filtered[MAX];
    int j = 0;

    // Remove spaces and punctuation, convert to lowercase
    for (int i = 0; str[i]; i++) {
        if (isalnum(str[i])) {
            filtered[j++] = tolower(str[i]);
        }
    }
    filtered[j] = '\0';

    // Push all characters
    for (int i = 0; i < j; i++) push(filtered[i]);

    // Compare by popping
    for (int i = 0; i < j; i++)
        if (filtered[i] != pop())
            return 0;

    return 1;
}

int main() {
    char str[MAX];
    printf("Enter a string: ");
    gets(str);

    if (isPalindrome(str))
        printf("Palindrome\n");
    else
        printf("Not a Palindrome\n");

    return 0;
}

