#include <stdio.h>

// Swap function to swap two elements
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int arr[], int start, int end) {
    int pivot = arr[start]; // pivot is the first element
    int i = start;
    int j = end;

    while (i < j) {
        while (arr[i] <= pivot && i < end)
            i++;
        while (arr[j] > pivot)
            j--;
        if (i < j) {
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[start], &arr[j]);
    return j;
}

void quicksort(int arr[], int start, int end) {
    if (start < end) {
        int loc = partition(arr, start, end);
        quicksort(arr, start, loc - 1);
        quicksort(arr, loc + 1, end);
    }
}

int main() {
    int arr[5] = {3, 2, 1, 5, 4};
    int n = 5;

    printf("Original array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    quicksort(arr, 0, n - 1);

    printf("Sorted array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}
