#include<stdio.h>
#define MAX 100
int Queue[MAX];
int f=-1;
int r=-1;
int enqueue(int ele){
    if((r+1)%MAX == f){
        printf("Queue Overflow!!\n");
        return -1;
    }
    else{
        if(f==-1)
        f=0;
        r=(r+1)%MAX;
        Queue[r]=ele;
        return 0;
    }
}
int dequeue()
{
    if(f==-1){
        printf("Queue Underflow!!\n");
        return -1;
    }
    else{
        printf("The deleted element is %d\n",Queue[f]);
        f=(f+1)%MAX;
        if(f > r){
            f=-1;
            r=-1;
        }
        return 0;
    }
}
void display()
{
    int i;
    if(f==-1){
        printf("Queue is empty!!\n");
    }
    else{
        for(i=f; i!=r; i=(i+1)%MAX)
            printf("%d ",Queue[i]);
        printf("%d ",Queue[i]);
        printf("\n");
    }
}

int main() {
    int choice, ele;
    do {
        printf("\nMenu:\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch(choice) {
            case 1:
                printf("Enter element to enqueue: ");
                scanf("%d", &ele);
                enqueue(ele);
                break;
            case 2:
                dequeue();
                break;
            case 3:
                display();
                break;
            case 4:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while(choice != 4);
    return 0;
}


