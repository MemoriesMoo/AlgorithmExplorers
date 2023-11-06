// topK问题
// 解决思路：
// 先建堆（元素个数为K）
// 再将剩下的元素依次与堆顶元素比较
// 判断是否需要交换并调整堆
// 找前K大的则需要建小堆 不断去除最小的 留下大值
// 找前K小的则需要建大堆 不断取出最大的 留下小值

#include <stdio.h>
#include <stdlib.h>

void swap(int *num1, int *num2);
void adjustDown(int arr[], int size, int index);

// 找出前K个最大元素
void findTopK(int arr[], int size, int k) {
    if (k <= 0 || k > size) {
        printf("Invalid value of k\n");
        return;
    }

    // 建立一个最小堆，包含前K个元素
    for (int i = (k - 1) / 2; i >= 0; i--) {
        adjustDown(arr, k, i);
    }

    // 从第K+1个元素开始，依次与堆顶比较，如果大于堆顶，则替换堆顶并重新调整堆
    for (int i = k; i < size; i++) {
        if (arr[i] > arr[0]) {
            swap(&arr[i], &arr[0]);
            adjustDown(arr, k, 0);
        }
    }

    // 打印前K个最大元素
    printf("Top %d largest elements are: ", k);
    for (int i = 0; i < k; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int arr[] = {5, 7, 1, 9, 3, 2, 6, 8, 4};
    int size = sizeof(arr) / sizeof(arr[0]);
    int k = 3;  // 要找出前K个最大元素

    findTopK(arr, size, k);

    return 0;
}
