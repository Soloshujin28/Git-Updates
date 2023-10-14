#include <stdio.h>
#include <string.h>

struct Student
{
    char name[50];
    int roll_number;
    float marks;
};

void addStudent(struct Student students[], int *count)
{
    printf("Enter student name: ");
    scanf("%s", students[*count].name);

    printf("Enter roll number: ");
    scanf("%d", &students[*count].roll_number);

    printf("Enter marks: ");
    scanf("%f", &students[*count].marks);

    (*count)++;
}

void displayStudents(struct Student students[], int count)
{
    printf("\nStudent List:\n");
    printf("%-20s %-15s %-10s\n", "Name", "Roll Number", "Marks");

    for (int i = 0; i < count; i++)
    {
        printf("%-20s %-15d %-10.2f\n", students[i].name, students[i].roll_number, students[i].marks);
    }
}

int main()
{
    struct Student students[100]; // Assuming a maximum of 100 students
    int count = 0;
    int choice;

    do
    {
        printf("\n1. Add Student\n2. Display Students\n3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            addStudent(students, &count);
            break;
        case 2:
            displayStudents(students, count);
            break;
        case 3:
            printf("Exiting the program.\n");
            break;
        default:
            printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 3);

    return 0;
}
