#include <stdio.h>
#include <string.h>

struct Student {
    int rollno;
    char name[50];
    float marks;
};

// Function to accept student details (Call by reference)
void accept(struct Student *s) {
    printf("Enter Roll Number: ");
    scanf("%d", &s->rollno);
    printf("Enter Name: ");
    scanf("%s", s->name);
    printf("Enter Marks: ");
    scanf("%f", &s->marks);
}

// Function to display student details (Call by value)
void display(struct Student s) {
    printf("\n--- Student Details ---\n");
    printf("Roll Number: %d\n", s.rollno);
    printf("Name: %s\n", s.name);
    printf("Marks: %.2f\n", s.marks);
}

int main() {
    struct Student s1;

    // Accept details by reference
    accept(&s1);

    // Display details by value
    display(s1);

    return 0;
}
