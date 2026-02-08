#include <stdio.h>

void addMatrix(int a[10][10], int b[10][10], int r, int c) {
    int i, j, sum[10][10];
    printf("Result (Addition):\n");
    for (i = 0; i < r; i++) {
        for (j = 0; j < c; j++) {
            sum[i][j] = a[i][j] + b[i][j];
            printf("%d ", sum[i][j]);
        }
        printf("\n");
    }
}

void multiplyMatrix(int a[10][10], int b[10][10], int r1, int c1, int r2, int c2) {
    int i, j, k, mul[10][10];
    for (i = 0; i < r1; i++) {
        for (j = 0; j < c2; j++) {
            mul[i][j] = 0;
            for (k = 0; k < c1; k++) {
                mul[i][j] += a[i][k] * b[k][j];
            }
        }
    }
    printf("Result (Multiplication):\n");
    for (i = 0; i < r1; i++) {
        for (j = 0; j < c2; j++) {
            printf("%d ", mul[i][j]);
        }
        printf("\n");
    }
}

void transposeMatrix(int a[10][10], int r, int c) {
    int i, j;
    printf("Transpose Matrix:\n");
    for (i = 0; i < c; i++) {
        for (j = 0; j < r; j++) {
            printf("%d ", a[j][i]);
        }
        printf("\n");
    }
}

int main() {
    int choice;
    int a[10][10], b[10][10];
    int r1, c1, r2, c2;
    int i, j;

    printf("Matrix Operations Program\n");
    printf("1. Matrix Addition\n");
    printf("2. Matrix Multiplication\n");
    printf("3. Transpose\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            printf("Enter rows and columns: ");
            scanf("%d %d", &r1, &c1);
            printf("Enter elements of first matrix:\n");
            for (i = 0; i < r1; i++)
                for (j = 0; j < c1; j++)
                    scanf("%d", &a[i][j]);
            printf("Enter elements of second matrix:\n");
            for (i = 0; i < r1; i++)
                for (j = 0; j < c1; j++)
                    scanf("%d", &b[i][j]);
            addMatrix(a, b, r1, c1);
            break;

        case 2:
            printf("Enter rows and columns of first matrix: ");
            scanf("%d %d", &r1, &c1);
            printf("Enter rows and columns of second matrix: ");
            scanf("%d %d", &r2, &c2);
            if (c1 != r2) {
                printf("Matrix multiplication not possible!\n");
                break;
            }
            printf("Enter elements of first matrix:\n");
            for (i = 0; i < r1; i++)
                for (j = 0; j < c1; j++)
                    scanf("%d", &a[i][j]);
            printf("Enter elements of second matrix:\n");
            for (i = 0; i < r2; i++)
                for (j = 0; j < c2; j++)
                    scanf("%d", &b[i][j]);
            multiplyMatrix(a, b, r1, c1, r2, c2);
            break;

        case 3:
            printf("Enter rows and columns: ");
            scanf("%d %d", &r1, &c1);
            printf("Enter matrix elements:\n");
            for (i = 0; i < r1; i++)
                for (j = 0; j < c1; j++)
                    scanf("%d", &a[i][j]);
            transposeMatrix(a, r1, c1);
            break;

        default:
            printf("Invalid choice!\n");
    }

    return 0;
}
