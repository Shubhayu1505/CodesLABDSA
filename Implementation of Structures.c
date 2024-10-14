#include <stdio.h>

// Defining a structure for a student
struct Student {
    char name[50];
    int rollNumber;
    float marks;
};

// Function to display student details
void displayStudent(struct Student s) {
    printf("Student Details:\n");
    printf("Name: %s\n", s.name);
    printf("Roll Number: %d\n", s.rollNumber);
    printf("Marks: %.2f\n", s.marks);
}

int main() {
    // Declaring a structure variable
    struct Student student1;

    // Input student details
    printf("Enter name: ");
    fgets(student1.name, sizeof(student1.name), stdin);  // Read student name
    printf("Enter roll number: ");
    scanf("%d", &student1.rollNumber);
    printf("Enter marks: ");
    scanf("%f", &student1.marks);

    // Display student details
    displayStudent(student1);

    return 0;
}
