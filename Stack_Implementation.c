#include<stdio.h>
#define MAX 100

// Global variables
int stack[MAX];
int top = -1;

// Function Prototypes
int isfull();
int isempty();
void push(int);
int pop();

// --- Function Definitions ---

int isfull()
{
    return top == (MAX - 1);
}

int isempty()
{
    return top == -1;
}

void push(int ele)
{
    if (isfull())
    {
        // FIX: Added \n
        printf("The stack has reached its limit (Overflow).\n");
    }
    else
    {
        stack[++top] = ele;
        // FIX: Added \n
        printf("%d has been pushed onto the stack.\n", ele); 
    }
}

int pop()
{
    if (isempty())
    {
        // FIX: Added \n
        printf("Cannot pop an element from an empty stack (Underflow)!\n");
        return -1; // Sentinel value for failure
    }
    else 
        // Post-decrement: returns the element at 'top', then decreases 'top'
        return stack[top--];
}

// FIX: Changed void main() to standard int main()
int main()
{
    int choice, ele;
    
    printf("1 - Push an item\n2 - Pop an item\n3 - Display the current contents of the stack\n4 - Exit\n"); // FIX: Added \n
    
    printf("\nEnter your choice: ");
    scanf("%d",&choice);
    
    while (choice != 4)
    {
        switch (choice)
        {
            case 1:
                printf("Enter the element to be pushed: ");
                scanf("%d",&ele);
                push(ele);
                break;
                
            case 2:
                {
                    // FIX: Store pop result and check for the error sentinel
                    int popped_val = pop();
                    if (popped_val != -1) {
                        printf("%d has been popped.\n", popped_val);
                    }
                }
                break;
                
            case 3:
                printf("The elements in the stack are: ");
                if (isempty()) {
                    printf("Stack is empty.\n");
                } else {
                    for(int i = 0; i <= top; i++)
                        // FIX: Added space for readability
                        printf("%d ", stack[i]); 
                    printf("\n"); // Newline after display
                }
                break;
                
            default:
                // FIX: Added \n
                printf("Invalid choice! Please enter again.\n"); 
        }
        
        printf("\nEnter your choice: ");
        scanf("%d",&choice);
    }
    
    // Standard return for int main()
    return 0;
}