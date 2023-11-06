#include <stdio.h>

// 希尔排序函数
void shellSort(int arr[], int n) {
    int gap, i, j;

    // 选择Hibbard增量序列
    for (gap = 1; gap < n / 3; gap = 3 * gap + 1);

    while (gap > 0) {
        for (i = gap; i < n; i++) {
            int temp = arr[i]; // 当前子序列的第一个元素
            j = i;

            // 在当前子序列中，将元素插入到正确的位置
            while (j >= gap && arr[j - gap] > temp) {
                arr[j] = arr[j - gap]; // 将较大的元素向后挪动
                j -= gap; // 移动到前一个子序列中的元素位置
            }

            arr[j] = temp; // 插入元素到正确位置
        }

        gap /= 3; // 缩小增量
    }
}

int main() {
    int arr[] = {12, 34, 11, 3, 22, 54, 87, 32};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Before shellSort: \n");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    shellSort(arr, n);

    printf("\nAfter shellSort: \n");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}
