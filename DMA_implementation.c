#include <stdio.h>
#include <stdlib.h>

struct Employee {
    int id;
    char name[50];
    float salary;
};

int main() {
    int n;
    float ae = 0;

    printf("Enter the number of employees: ");
    scanf("%d", &n);

    struct Employee* ptr = (struct Employee*)malloc(n * sizeof(struct Employee));
    
    if(ptr!=NULL){
        for (int i = 0; i < n; i++) {
            printf("\nEnter the details of Employee %d:\n", i + 1);

            printf("Enter id: ");
            scanf("%d", &(ptr+i)->id);

            printf("Enter name: ");
            scanf("%s", (ptr+i)->name);

            printf("Enter salary: ");
            scanf("%f", &(ptr+i)->salary);

            ae += (ptr+i)->salary;
        }

        printf("\nAnnual Expenditure is %f\n", ae);

        free(ptr);
    }
    else{
        printf("Memory Allocation Failed!");
        return -1;
    }
    return 0;
}
