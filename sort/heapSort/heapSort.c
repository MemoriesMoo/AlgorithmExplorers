#include <stdio.h>

void swap(int *num1, int *num2);
void adjustDown(int arr[], int size, int index);

void heapSort(int arr[], int size) {
    // 堆排序
    // 第一步：建立最小堆
    for (int index = (size - 1 - 1) / 2; index >= 0; --index) {
        adjustDown(arr, size, index);
    }

    // 第二步：排序
    int count = 1;
    while (count < size) {
        swap(&arr[0], &arr[size - count]);
        adjustDown(arr, size - count, 0);
        ++count;
    }
}

int main() {
    int arr[9] = {5, 7, 1, 9, 3, 2, 6, 8, 4};
    int size = sizeof(arr) / sizeof(arr[0]);

    // 打印原始数组
    printf("Before: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    // 执行堆排序
    heapSort(arr, size);

    // 打印排序后的结果
    printf("After: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}
