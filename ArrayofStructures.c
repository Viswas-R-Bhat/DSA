#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define structure
struct Student {
    int id;
    char name[50];
    float marks;
};

int main() {
    struct Student s[100];
    int n, i;
    FILE *fp;

    // Open file for reading
    fp = fopen("students.txt", "r");
    if (fp == NULL) {
        printf("Error opening file!\n");
        return 1;
    }

    // Read number of students
    fscanf(fp, "%d", &n);

    // Read data for n students
    for (i = 0; i < n; i++) {
        fscanf(fp, "%d %s %f", &s[i].id, s[i].name, &s[i].marks);
    }

    fclose(fp);

    // Display student data
    printf("\n--- Student Details from File ---\n");
    for (i = 0; i < n; i++) {
        printf("\nStudent %d\n", i + 1);
        printf("ID     : %d\n", s[i].id);
        printf("Name   : %s\n", s[i].name);
        printf("Marks  : %.2f\n", s[i].marks);
    }

    return 0;
}
