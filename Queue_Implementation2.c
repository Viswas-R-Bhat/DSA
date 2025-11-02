#include <stdio.h>
#define SIZE 100

int Queue[SIZE];  // Queue[0] = front, Queue[1] = rear

void initialize() {
    Queue[0] = 2;  // front index starts at position 2
    Queue[1] = 1;  // rear starts before front (empty queue)
}

void enqueue(int value) {
    if (Queue[1] == SIZE - 1)
        printf("Queue Overflow!\n");
    else {
        Queue[++Queue[1]] = value;
        if (Queue[0] == 2 && Queue[1] == 2)  // if first element inserted
            Queue[0] = 2;
    }
}

void dequeue() {
    if (Queue[0] > Queue[1])
        printf("Queue Underflow!\n");
    else {
        printf("Deleted: %d\n", Queue[Queue[0]]);
        Queue[0]++; // move front forward
    }
}

void display() {
    if (Queue[0] > Queue[1])
        printf("Queue is empty.\n");
    else {
        printf("Queue elements: ");
        for (int i = Queue[0]; i <= Queue[1]; i++)
            printf("%d ", Queue[i]);
        printf("\n");
    }
}

int main() {
    initialize();

    enqueue(10);
    enqueue(20);
    enqueue(30);
    display();

    dequeue();
    display();

    enqueue(40);
    display();

    return 0;
}
