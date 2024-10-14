#include <stdio.h>
#include <stdlib.h>

// Function to allocate memory for a matrix
int** allocateMatrix(int rows, int cols) {
    int** matrix = (int**)malloc(rows * sizeof(int*));
    for (int i = 0; i < rows; i++) {
        matrix[i] = (int*)malloc(cols * sizeof(int));
    }
    return matrix;
}

// Function to free memory allocated for a matrix
void freeMatrix(int** matrix, int rows) {
    for (int i = 0; i < rows; i++) {
        free(matrix[i]);
    }
    free(matrix);
}

// Function to input a matrix
void inputMatrix(int** matrix, int rows, int cols) {
    printf("Enter the elements of the matrix:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }
}

// Function to print a matrix
void printMatrix(int** matrix, int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

// Function to multiply two matrices
int** multiplyMatrices(int** matrix1, int rows1, int cols1, 
                       int** matrix2, int rows2, int cols2) {
    if (cols1 != rows2) {
        printf("Error: The number of columns in the first matrix must be equal to the number of rows in the second matrix.\n");
        return NULL;
    }

    int** result = allocateMatrix(rows1, cols2);

    for (int i = 0; i < rows1; i++) {
        for (int j = 0; j < cols2; j++) {
            result[i][j] = 0;
            for (int k = 0; k < cols1; k++) {
                result[i][j] += matrix1[i][k] * matrix2[k][j];
            }
        }
    }

    return result;
}

int main() {
    int rows1, cols1, rows2, cols2;

    // Input dimensions for the first matrix
    printf("Enter the number of rows and columns for the first matrix: ");
    scanf("%d %d", &rows1, &cols1);

    // Input dimensions for the second matrix
    printf("Enter the number of rows and columns for the second matrix: ");
    scanf("%d %d", &rows2, &cols2);

    // Check if multiplication is possible
    if (cols1 != rows2) {
        printf("Error: The number of columns in the first matrix must be equal to the number of rows in the second matrix.\n");
        return 1;
    }

    // Allocate memory for matrices
    int** matrix1 = allocateMatrix(rows1, cols1);
    int** matrix2 = allocateMatrix(rows2, cols2);

    // Input matrices
    printf("For the first matrix:\n");
    inputMatrix(matrix1, rows1, cols1);
    printf("For the second matrix:\n");
    inputMatrix(matrix2, rows2, cols2);

    // Perform matrix multiplication
    int** result = multiplyMatrices(matrix1, rows1, cols1, matrix2, rows2, cols2);

    // Print the result
    if (result != NULL) {
        printf("Resultant matrix after multiplication:\n");
        printMatrix(result, rows1, cols2);

        // Free the memory for the result matrix
        freeMatrix(result, rows1);
    }

    // Free memory for input matrices
    freeMatrix(matrix1, rows1);
    freeMatrix(matrix2, rows2);

    return 0;
}