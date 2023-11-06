#include <stdio.h>

// 插入排序函数
void insertionSort(int arr[], int size) {
    // 从数组的第二个元素开始遍历
    for (int currentIndex = 1; currentIndex < size; ++currentIndex) {
        // 暂存当前元素的值
        int currentElement = arr[currentIndex];
        int i = currentIndex;

        // 从当前位置向前比较并移动较大的元素
        while (i > 0 && arr[i - 1] > currentElement) {
            arr[i] = arr[i - 1];
            i--;
        }

        // 将当前元素插入到合适的位置
        arr[i] = currentElement;
    }
}

int main() {
    // 测试用例数组
    int arr[9] = {2, 4, 1, 3, 5, 1, 9, 8, 10};

    // 打印排序前的数组
    printf("Before insertionSort: ");
    for (int i = 0; i < 9; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    
    // 调用插入排序函数
    insertionSort(arr, 9);

    // 打印排序后的数组
    printf("After insertionSort: ");
    for (int i = 0; i < 9; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}
