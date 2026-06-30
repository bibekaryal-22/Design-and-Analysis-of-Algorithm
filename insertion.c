#include <stdio.h>

int main() {
    int arr[100], n, i, j, key;

    // Input number of elements
    printf("Enter number of elements: ");
    scanf("%d", &n);

    // Input array elements
    printf("Enter %d elements:\n", n);
    for(i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // Display original array
    printf("\nOriginal array:\n");
    for(i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    // Insertion Sort (Iterative)
    for(i = 1; i < n; i++) {
        key = arr[i];
        j = i - 1;

        // Shift elements greater than key
        while(j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }

        arr[j + 1] = key;
    }

    // Display sorted array
    printf("\nSorted array:\n");
    for(i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    printf("\n");

    return 0;
}