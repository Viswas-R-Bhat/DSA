#include<stdio.h>
#include<stdlib.h>
typedef struct node{
    int data;
    struct node* next;
}Node;
Node* head=NULL;
Node* head1=NULL;
void insert_at_rear_first(int ele){
    Node* newnode = (Node*)malloc(sizeof(Node));
    newnode->data = ele;
    newnode->next = NULL;
    if(head == NULL){
        head = newnode;
    } else {
        Node* cur = head;
        while(cur->next != NULL){
            cur = cur->next;
        }
        cur->next = newnode;
    }
}

void insert_at_rear_second(int ele){
    Node* newnode = (Node*)malloc(sizeof(Node));
    newnode->data = ele;
    newnode->next = NULL;
    if(head1 == NULL){
        head1 = newnode;
    } else {
        Node* cur = head1;
        while(cur->next != NULL){
            cur = cur->next;
        }
        cur->next = newnode;
    }
}
void concatenate(){
    if(head == NULL){
        head = head1;
        head1 = NULL;
        return;
    }
    if(head1 == NULL){
        return;
    }
    Node* cur = head;
    while(cur->next != NULL){
        cur = cur->next;
    }
    cur->next = head1;
    head1 = NULL;
}
void display(Node* head){
    if(head == NULL){
        printf("List is empty!\n");
        return;
    }
    Node* cur = head;
    printf("The list contains: ");
    while(cur != NULL){
        printf("%d", cur->data);
        if(cur->next != NULL){
            printf("->");
        }
        cur = cur->next;
    }
    printf("->NULL\n");
}
int main(){
    int choice,ele;
    printf("Menu Driven Program to demonstrate concatenation of 2 singly linked lists.\n\n");
    while(1){
        printf("Choices:\n");
        printf("1<-Insert into first list.\n");
        printf("2<-Insert into second list.\n");
        printf("3<-Display list 1.\n");
        printf("4<-Display list 2.\n");
        printf("5<-Concatenate.\n");
        printf("6<-Exit.\n");
        printf("Enter your Choice: ");
        scanf("%d",&choice);
        switch(choice){
            case 1:
            printf("Enter the element: ");
            scanf("%d",&ele);
            insert_at_rear_first(ele);
            break;

            case 2:
            printf("Enter the element: ");
            scanf("%d",&ele);
            insert_at_rear_second(ele);
            break;

            case 3:
            display(head);
            break;

            case 4:
            display(head1);
            break;

            case 5:
            concatenate();
            printf("Lists concatenated.\n");
            printf("Concatenated list: ");
            display(head);
            break;

            case 6:
            printf("Exiting Program...");
            exit(0);
        }
    }
}