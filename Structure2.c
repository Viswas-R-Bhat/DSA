#include <stdio.h>

struct Date {
    int day, month, year;
};

struct Holder {
    char name[50];
    struct Date dob;
    char address[100];
    char nationality[30];
};

struct Passport {
    int passport_no;
    struct Date issue_date;
    struct Date expiry_date;
    char issue_country[30];
    struct Holder holder;
};

int main() {
    struct Passport p;

    printf("Enter Passport Number: ");
    scanf("%d", &p.passport_no);

    printf("Enter Issue Date (dd mm yyyy): ");
    scanf("%d %d %d", &p.issue_date.day, &p.issue_date.month, &p.issue_date.year);

    printf("Enter Expiry Date (dd mm yyyy): ");
    scanf("%d %d %d", &p.expiry_date.day, &p.expiry_date.month, &p.expiry_date.year);

    printf("Enter Issuing Country: ");
    scanf("%s", p.issue_country);

    printf("Enter Holder Name: ");
    scanf("%s", p.holder.name);

    printf("Enter DOB (dd mm yyyy): ");
    scanf("%d %d %d", &p.holder.dob.day, &p.holder.dob.month, &p.holder.dob.year);

    printf("Enter Address: ");
    scanf("%s", p.holder.address);

    printf("Enter Nationality: ");
    scanf("%s", p.holder.nationality);

    printf("\n--- Passport Details ---\n");
    printf("Passport No: %d\n", p.passport_no);
    printf("Issue Date: %d/%d/%d\n", p.issue_date.day, p.issue_date.month, p.issue_date.year);
    printf("Expiry Date: %d/%d/%d\n", p.expiry_date.day, p.expiry_date.month, p.expiry_date.year);
    printf("Issued in: %s\n", p.issue_country);
    printf("Name: %s\n", p.holder.name);
    printf("DOB: %d/%d/%d\n", p.holder.dob.day, p.holder.dob.month, p.holder.dob.year);
    printf("Address: %s\n", p.holder.address);
    printf("Nationality: %s\n", p.holder.nationality);

    return 0;
}
