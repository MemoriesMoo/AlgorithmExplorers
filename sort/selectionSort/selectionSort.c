#include <stdio.h>

// 选择排序函数
void selectionSort(int arr[], int n)
{
    int i, j, minIndex, temp;

    for (i = 0; i < n - 1; i++)
    {
        minIndex = i; // 假定当前位置的元素是最小的

        // 在未排序部分中查找最小的元素
        for (j = i + 1; j < n; j++)
        {
            if (arr[j] < arr[minIndex])
            {
                minIndex = j;
            }
        }

        // 将找到的最小元素与当前位置的元素交换
        temp = arr[i];
        arr[i] = arr[minIndex];
        arr[minIndex] = temp;
    }
}

int main()
{
    int arr[] = {64, 25, 12, 22, 11};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Before selectionSort: \n");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }

    selectionSort(arr, n);

    printf("\nAfter selectionSort: \n");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}
