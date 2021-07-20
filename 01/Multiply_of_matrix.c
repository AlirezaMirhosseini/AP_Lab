#include <stdio.h>
#include <stdlib.h>

#pragma warning(disable:4996)

void CreateMatrix(int*** arr, int row, int cul);
void FillMatrix(int** arr, int row, int cul);
void Multiply(int** arr1, int** arr2, int** arr3, int row, int cul, int temp);
void PrintMatrix(int** arr3, int row, int cul);
void FreeMatrix(int** arr, int row);

int main() {
    int n1, n2, n3;
    int** arr1;
    int** arr2;
    int** arr3;

    scanf("%d%d%d", &n1, &n2, &n3);

    CreateMatrix(&arr1, n1, n2);
    CreateMatrix(&arr2, n2, n3);
    CreateMatrix(&arr3, n1, n3);

    FillMatrix(arr1, n1, n2);
    FillMatrix(arr2, n2, n3);

    Multiply(arr1, arr2, arr3, n1, n3, n2);

    PrintMatrix(arr3, n1, n3);

    FreeMatrix(arr1, n1);
    FreeMatrix(arr2, n2);
    FreeMatrix(arr3, n1);

	return 0;
}
void CreateMatrix(int*** arr, int row, int cul) {
    *arr = (int**)malloc(row * sizeof(int*));
    for (int i = 0; i < row; i++) {
        (*arr)[i] = (int*)malloc(cul * sizeof(int));
    }
}
void FillMatrix(int** arr, int row, int cul) {
    for (int i = 0;i < row;i++) {
        for (int j = 0;j < cul;j++) {
            scanf("%d", &arr[i][j]);
        }
    }
}
void Multiply(int** arr1, int** arr2, int** arr3, int row, int cul, int temp) {
    for (int r = 0;r < row;r++) {
        for (int c = 0;c < cul;c++) {
            arr3[r][c] = 0;
            int m = 0, n = 0;
            for (int k = 0;k < temp;k++) {
                arr3[r][c] += arr1[r][m] * arr2[n][c];
                n++;
                m++;
            }
        }
    }
}
void PrintMatrix(int** arr3, int n1, int n3) {
    for (int i = 0;i < n1;i++) {
        for (int j = 0;j < n3;j++)
            printf("%d ", arr3[i][j]);
        printf("\n");
    }
}
void FreeMatrix(int** arr, int row) {
    for (int i = 0;i < row;i++) {
        free(arr[i]);
    }
    free(arr);
}
