#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define SIZE    100

int row_reduction(int matrix[SIZE][SIZE], int column, int row, int total_row);
int leading_zeroes(int matrix[SIZE][SIZE], int column, int row);

int main(void) {
    int matrix[SIZE][SIZE];
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
                printf("%3d", matrix[i][a]);
            }
        }
        printf("\n");
    }

    for (i = 0; i < row; i++) {
        int transform = row_reduction(matrix, i, i, row);
        if (transform == 1) {
            printf("doing row reductions\n");
        } else {
            printf("not doing row reductions\n");
        }
    }

    return 0;
}


int row_reduction(int matrix[SIZE][SIZE], int column, int row, int total_row) {

    int all_zeroes = 0;
    for (int i = row; i < total_row; i++) {
        if (matrix[i][column] == 0) {
            all_zeroes++;
        }
    }

    if (all_zeroes != (total_row - (row + 1))) {
        return 1;
    } else {
        return 0;
    }
}

int leading_zeroes(int matrix[SIZE][SIZE], int column, int row) {

    int zeroes = 0;
    for (int i = 0; i < column; i++) {
        if (matrix[row][i] == 0) {
            zeroes++;
        } else {
            return zeroes;
        }
    }
    
    return zeroes;
}

