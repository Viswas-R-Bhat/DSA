#include<stdio.h>
#define MAX 100
int Queue[MAX];
int f=-1;
int r=-1;
int isEmpty(){
    if(f==-1 && r==-1){
        return 1;
    }
    else{
        return 0;
    }
}
int isFull(){
    if((r+1)%MAX==f){
        return 1;
    }
    else{
        return 0;
    }
}
void enqueueR(int ele){
    if(isFull()){
        printf("Queue Overflow!!\n");
    }
    else{ 
        if(isEmpty()){
            f=r=0;
        }
    else
        r=(r+1)%MAX; 
    Queue[r]=ele;
    }
}
void enqueueF(int ele){
    if(isFull()){
        printf("Queue Overflow!!\n");
    }
    else if(isEmpty())
        f=r=0;
    else
        f=(f+MAX-1)%MAX;
    Queue[f]=ele;
}
void dequeueF()
{
    if(isEmpty()){
        printf("Queue Underflow!!\n");
    }
    else if(f==r){
            f=r=-1;
    }
    else{
        printf("The deleted element is %d\n",Queue[f]);
        f=(f+1)%MAX;
    }
}
void dequeueR()
{
    if(isEmpty()){
        printf("Queue Underflow!!\n");
    }
    else if(f==r){
            f=r=-1;
    }
    else{
        printf("The deleted element is %d\n",Queue[r]);
        r=(r+MAX-1)%MAX;
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
        printf("1. Enqueue From Front\n");
        printf("2. Enqueue From Rear\n");
        printf("3. Dequeue From Front\n");
        printf("4. Dequeue From Rear\n");
        printf("5. Display\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch(choice) {
            case 1:
                printf("Enter element to enqueue: ");
                scanf("%d", &ele);
                enqueueF(ele);
                break;
            case 2:
                printf("Enter element to enqueue: ");
                scanf("%d", &ele);
                enqueueR(ele);
                break;
            case 3:
                dequeueF();
                break;
            case 4:
                dequeueR();
                break;
            case 5:
                display();
                break;
            case 6:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while(choice != 6);
    return 0;
}


