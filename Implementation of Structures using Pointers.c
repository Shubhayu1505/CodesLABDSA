#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LENGTH 50
#define MAX_EMPLOYEES 100

// Structure to hold employee details
struct Employee {
    int id;
    char name[MAX_NAME_LENGTH];
    float salary;
    char department[MAX_NAME_LENGTH];
};

// Function to create a new employee
struct Employee* createEmployee(int id, const char* name, float salary, const char* department) {
    struct Employee* emp = (struct Employee*)malloc(sizeof(struct Employee));
    if (emp == NULL) {
        printf("Memory allocation failed!\n");
        return NULL;
    }
    emp->id = id;
    strncpy(emp->name, name, MAX_NAME_LENGTH - 1);
    emp->name[MAX_NAME_LENGTH - 1] = '\0';  // Ensure null-termination
    emp->salary = salary;
    strncpy(emp->department, department, MAX_NAME_LENGTH - 1);
    emp->department[MAX_NAME_LENGTH - 1] = '\0';  // Ensure null-termination
    return emp;
}

// Function to display employee details
void displayEmployee(const struct Employee* emp) {
    printf("ID: %d\n", emp->id);
    printf("Name: %s\n", emp->name);
    printf("Salary: %.2f\n", emp->salary);
    printf("Department: %s\n", emp->department);
    printf("\n");
}

// Function to update employee salary
void updateSalary(struct Employee* emp, float newSalary) {
    emp->salary = newSalary;
    printf("Salary updated for employee %s\n", emp->name);
}

// Function to free memory allocated for an employee
void freeEmployee(struct Employee* emp) {
    free(emp);
}

int main() {
    struct Employee* employees[MAX_EMPLOYEES];
    int employeeCount = 0;
    int choice;

    while (1) {
        printf("\nEmployee Management System\n");
        printf("1. Add Employee\n");
        printf("2. Display All Employees\n");
        printf("3. Update Employee Salary\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: {
                if (employeeCount >= MAX_EMPLOYEES) {
                    printf("Maximum number of employees reached!\n");
                    break;
                }
                int id;
                char name[MAX_NAME_LENGTH];
                float salary;
                char department[MAX_NAME_LENGTH];

                printf("Enter Employee ID: ");
                scanf("%d", &id);
                printf("Enter Employee Name: ");
                scanf(" %[^\n]s", name);
                printf("Enter Employee Salary: ");
                scanf("%f", &salary);
                printf("Enter Employee Department: ");
                scanf(" %[^\n]s", department);

                employees[employeeCount] = createEmployee(id, name, salary, department);
                if (employees[employeeCount] != NULL) {
                    employeeCount++;
                    printf("Employee added successfully!\n");
                }
                break;
            }
            case 2:
                if (employeeCount == 0) {
                    printf("No employees to display.\n");
                } else {
                    printf("Employee Details:\n");
                    for (int i = 0; i < employeeCount; i++) {
                        displayEmployee(employees[i]);
                    }
                }
                break;
            case 3: {
                int id;
                float newSalary;
                printf("Enter Employee ID to update salary: ");
                scanf("%d", &id);
                printf("Enter new salary: ");
                scanf("%f", &newSalary);

                int found = 0;
                for (int i = 0; i < employeeCount; i++) {
                    if (employees[i]->id == id) {
                        updateSalary(employees[i], newSalary);
                        found = 1;
                        break;
                    }
                }
                if (!found) {
                    printf("Employee with ID %d not found.\n", id);
                }
                break;
            }
            case 4:
                // Free allocated memory before exiting
                for (int i = 0; i < employeeCount; i++) {
                    freeEmployee(employees[i]);
                }
                printf("Exiting program.\n");
                return 0;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}