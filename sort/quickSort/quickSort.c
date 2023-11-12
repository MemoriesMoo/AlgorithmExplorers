#include <stdio.h>

// 交换函数
int swap(int *num1, int *num2)
{
    int temp = *num1;
    *num1 = *num2;
    *num2 = temp;
    return 0;
}

// 划分操作
int partSort(int arr[], int left, int right)
{
    // 定义最左边为key值
    int keyIndex = left;

    // 当左指针小于右指针时进行循环
    while (left < right)
    {
        // 从右边找到第一个小于key的值
        while (left < right && arr[right] >= arr[keyIndex])
            right--;

        // 从左边找到第一个大于key的值
        while (left < right && arr[left] <= arr[keyIndex])
            left++;

        // 交换左右指针对应的值
        swap(&arr[left], &arr[right]);
    }

    // 当左右指针相遇时，将key值与相遇位置的值交换
    int meetIndex = right;
    swap(&arr[keyIndex], &arr[meetIndex]);

    // 返回最终相遇索引
    return meetIndex;
}

// 快速排序递归函数
void quickSort(int arr[], int begin, int end)
{
    if (begin < end)  // 添加此条件以处理空数组
    {
        // 获取划分操作后的相遇索引
        int keyIndex = partSort(arr, begin, end);

        // 递归对左右两个子数组进行排序
        quickSort(arr, begin, keyIndex - 1);
        quickSort(arr, keyIndex + 1, end);
    }
}

// 打印数组
void printArray(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main()
{
    // 测试用例1
    int arr1[] = {12, 4, 5, 6, 7, 3, 1, 15};
    int n1 = sizeof(arr1) / sizeof(arr1[0]);
    printf("Original array: ");
    printArray(arr1, n1);

    quickSort(arr1, 0, n1 - 1);

    printf("Sorted array: ");
    printArray(arr1, n1);
    printf("\n");

    // 测试用例2
    int arr2[] = {64, 25, 12, 22, 11};
    int n2 = sizeof(arr2) / sizeof(arr2[0]);
    printf("Original array: ");
    printArray(arr2, n2);

    quickSort(arr2, 0, n2 - 1);

    printf("Sorted array: ");
    printArray(arr2, n2);
    printf("\n");

    // 测试用例3：空数组
    int arr3[] = {};
    int n3 = sizeof(arr3) / sizeof(arr3[0]);
    printf("Original array: ");
    printArray(arr3, n3);

    quickSort(arr3, 0, n3 - 1);

    printf("Sorted array: ");
    printArray(arr3, n3);
    printf("\n");

    return 0;
}
