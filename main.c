#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(void) {
    int matrix[100][100];
    int row, column;

    printf("Enter the number of rows in the matrix: ");
    scanf("%d", &row);

    printf("Enter the number of columns in the matrix: ");
    scanf("%d", &column);

    int i, a;
    for (i = 0; i < row; i++) {
        printf("Enter elements in row %d: \n", i);
        for (a = 0; a < column; a++) {
            scanf("%d", &matrix[i][a]);
        }
    }

    printf("Matrix Entered: \n");
    for (i = 0; i < row; i++) {
        for (a = 0; a < column; a++) {
            if (a == column - 1) {
                printf(" | %d", matrix[i][a]);
            } else if (a == 0) {
                printf("%d", matrix[i][a]);
            } else {
                printf("%4d", matrix[i][a]);
            }
        }
        printf("\n");
    }
    return 0;
}