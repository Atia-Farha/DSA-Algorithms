#include <stdio.h>

void selectionSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int mn = i;

        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[mn]) {
                mn = j;
            }
        }

        int t = arr[i];
        arr[i] = arr[mn];
        arr[mn] = t;
    }
}

int main() {
    int arr[] = {5, 2, 4, 6, 1, 3};
    int n = sizeof(arr) / sizeof(arr[0]);

    insertionSort(arr, n);

    for(int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    printf("\n");

    return 0;
}