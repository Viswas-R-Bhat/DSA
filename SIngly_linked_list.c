#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* head = NULL;

// Function prototypes
void insertAtBeginning(int);
void insertAtEnd(int);
void insertAtPosition(int, int);
void insertBeforeElement(int, int);
void insertAfterElement(int, int);
void deleteAtBeginning();
void deleteAtEnd();
void deleteAtPosition(int);
void deleteBeforeElement(int);
void deleteAfterElement(int);
void display();

int main() {
    int choice, data, pos, key;

    while (1) {
        printf("\n----- Singly Linked List Menu -----\n");
        printf("1. Insert at Beginning\n");
        printf("2. Insert at End\n");
        printf("3. Insert at Position\n");
        printf("4. Insert Before Element\n");
        printf("5. Insert After Element\n");
        printf("6. Delete at Beginning\n");
        printf("7. Delete at End\n");
        printf("8. Delete at Position\n");
        printf("9. Delete Before Element\n");
        printf("10. Delete After Element\n");
        printf("11. Display List\n");
        printf("12. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {

        case 1:
            printf("Enter value: ");
            scanf("%d", &data);
            insertAtBeginning(data);
            break;

        case 2:
            printf("Enter value: ");
            scanf("%d", &data);
            insertAtEnd(data);
            break;

        case 3:
            printf("Enter value: ");
            scanf("%d", &data);
            printf("Enter position: ");
            scanf("%d", &pos);
            insertAtPosition(data, pos);
            break;

        case 4:
            printf("Insert value: ");
            scanf("%d", &data);
            printf("Before which element? ");
            scanf("%d", &key);
            insertBeforeElement(data, key);
            break;

        case 5:
            printf("Insert value: ");
            scanf("%d", &data);
            printf("After which element? ");
            scanf("%d", &key);
            insertAfterElement(data, key);
            break;

        case 6:
            deleteAtBeginning();
            break;

        case 7:
            deleteAtEnd();
            break;

        case 8:
            printf("Enter position: ");
            scanf("%d", &pos);
            deleteAtPosition(pos);
            break;

        case 9:
            printf("Delete before which element? ");
            scanf("%d", &key);
            deleteBeforeElement(key);
            break;

        case 10:
            printf("Delete after which element? ");
            scanf("%d", &key);
            deleteAfterElement(key);
            break;

        case 11:
            display();
            break;

        case 12:
            exit(0);

        default:
            printf("Invalid choice! Try again.\n");
        }
    }

    return 0;
}

//
// ---------------- INSERT FUNCTIONS ----------------
//

void insertAtBeginning(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = head;
    head = newNode;
    printf("Inserted %d at beginning.\n", data);
}

void insertAtEnd(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;

    if (head == NULL) {
        head = newNode;
        printf("Inserted %d at end.\n", data);
        return;
    }

    struct Node* temp = head;
    while (temp->next != NULL)
        temp = temp->next;

    temp->next = newNode;
    printf("Inserted %d at end.\n", data);
}

void insertAtPosition(int data, int position) {
    if (position == 1) {
        insertAtBeginning(data);
        return;
    }

    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;

    struct Node* temp = head;
    for (int i = 1; temp != NULL && i < position - 1; i++)
        temp = temp->next;

    if (temp == NULL) {
        printf("Position out of range!\n");
        free(newNode);
        return;
    }

    newNode->next = temp->next;
    temp->next = newNode;

    printf("Inserted %d at position %d.\n", data, position);
}

void insertBeforeElement(int data, int key) {
    if (head == NULL) {
        printf("List is empty!\n");
        return;
    }

    if (head->data == key) {
        insertAtBeginning(data);
        return;
    }

    struct Node* temp = head;
    while (temp->next != NULL && temp->next->data != key)
        temp = temp->next;

    if (temp->next == NULL) {
        printf("Element %d not found!\n", key);
        return;
    }

    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = temp->next;
    temp->next = newNode;

    printf("Inserted %d before %d.\n", data, key);
}

void insertAfterElement(int data, int key) {
    struct Node* temp = head;

    while (temp != NULL && temp->data != key)
        temp = temp->next;

    if (temp == NULL) {
        printf("Element %d not found!\n", key);
        return;
    }

    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = temp->next;
    temp->next = newNode;

    printf("Inserted %d after %d.\n", data, key);
}

//
// ---------------- DELETE FUNCTIONS ----------------
//

void deleteAtBeginning() {
    if (head == NULL) {
        printf("List is empty!\n");
        return;
    }
    struct Node* temp = head;
    head = head->next;
    printf("Deleted %d from beginning.\n", temp->data);
    free(temp);
}

void deleteAtEnd() {
    if (head == NULL) {
        printf("List is empty!\n");
        return;
    }

    if (head->next == NULL) {
        printf("Deleted %d from end.\n", head->data);
        free(head);
        head = NULL;
        return;
    }

    struct Node* temp = head;
    while (temp->next->next != NULL)
        temp = temp->next;

    struct Node* last = temp->next;
    temp->next = NULL;
    printf("Deleted %d from end.\n", last->data);
    free(last);
}

void deleteAtPosition(int position) {
    if (head == NULL) {
        printf("List is empty!\n");
        return;
    }

    if (position == 1) {
        deleteAtBeginning();
        return;
    }

    struct Node* temp = head;
    for (int i = 1; temp != NULL && i < position - 1; i++)
        temp = temp->next;

    if (temp == NULL || temp->next == NULL) {
        printf("Position out of range!\n");
        return;
    }

    struct Node* delNode = temp->next;
    temp->next = delNode->next;
    printf("Deleted %d from position %d.\n", delNode->data, position);
    free(delNode);
}

void deleteBeforeElement(int key) {
    if (head == NULL || head->data == key) {
        printf("No node exists before %d.\n", key);
        return;
    }

    if (head->next != NULL && head->next->data == key) {
        deleteAtBeginning();
        return;
    }

    struct Node* temp = head;
    struct Node* prev = NULL;

    while (temp->next != NULL && temp->next->data != key) {
        prev = temp;
        temp = temp->next;
    }

    if (temp->next == NULL) {
        printf("Element %d not found!\n", key);
        return;
    }

    if (prev == NULL)
        return;

    prev->next = temp->next;
    printf("Deleted %d before %d.\n", temp->data, key);
    free(temp);
}

void deleteAfterElement(int key) {
    struct Node* temp = head;

    while (temp != NULL && temp->data != key)
        temp = temp->next;

    if (temp == NULL || temp->next == NULL) {
        printf("No node exists after %d.\n", key);
        return;
    }

    struct Node* delNode = temp->next;
    temp->next = delNode->next;
    printf("Deleted %d after %d.\n", delNode->data, key);
    free(delNode);
}

//
// ---------------- DISPLAY FUNCTION ----------------
//

void display() {
    if (head == NULL) {
        printf("List is empty!\n");
        return;
    }

    struct Node* temp = head;
    printf("Current List: ");
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}
