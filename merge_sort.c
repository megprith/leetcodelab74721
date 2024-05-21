#include <stdio.h>

int b[5]; // Global array for merging

void merge(int arr[5], int start, int end, int mid) {
    int i = start;
    int j = mid + 1;
    int k = start;

    while (i <= mid && j <= end) {
        if (arr[i] > arr[j]) {
            b[k] = arr[j];
            j++;
        } else {
            b[k] = arr[i];
            i++;
        }
        k++;
    }

    while (i <= mid) {
        b[k] = arr[i];
        i++;
        k++;
    }

    while (j <= end) {
        b[k] = arr[j];
        j++;
        k++;
    }

    // Copy merged elements back to the original array
    for (int x = start; x <= end; x++) {
        arr[x] = b[x];
    }
}

void mergesort(int arr[5], int lb, int ub) {
    if (lb < ub) {
        int mid = (ub + lb) / 2;
        mergesort(arr, lb, mid);
        mergesort(arr, mid + 1, ub);
        merge(arr, lb, ub, mid);
    }
}

int main() {
    int arr[5] = {3, 2, 1, 5, 4};

    mergesort(arr, 0, 4); // Initial call to mergesort

    printf("Sorted array: ");
    for (int i = 0; i < 5; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}
