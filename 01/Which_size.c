#include <stdio.h>
#include <stdlib.h>

#pragma warning(disable:4996)

int main() {
    int arr_size1, arr_size2;
    scanf("%d%d",&arr_size1,&arr_size2);
    int* a;
    a = (int*)malloc(arr_size1 * sizeof(int));
    if (arr_size1 >= arr_size2) {
        for (int i = 0;i < arr_size2;i++) {
            *(a + i) = 100;
        }
        for (int i = 0;i < arr_size2;i++) {
            printf("%d ", *(a + i));
        }
    }
    else {
        a = (int*)realloc(a ,arr_size2 * sizeof(int));
        int i = 0;
        while (i < arr_size1) {
            *(a + i) = 100;
            i++;
        }
        while (i < arr_size2) {
            *(a + i) = 0;
            i++;
        }
        for (int i = 0;i < arr_size2;i++) {
            printf("%d ", *(a + i));
        }
    }
    free(a);

    return 0;
}