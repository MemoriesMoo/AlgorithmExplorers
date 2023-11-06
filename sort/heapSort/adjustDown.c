// 交换数据
void swap(int *num1, int *num2) {
    int temp = *num1;
    *num1 = *num2;
    *num2 = temp;
}

// 向下调整算法
void adjustDown(int arr[], int size, int index) {
    while (1) {
        int leftChild = index * 2 + 1;
        int rightChild = leftChild + 1;
        int smallest = index;

        if (leftChild < size && arr[leftChild] < arr[smallest]) {
            smallest = leftChild;
        }

        if (rightChild < size && arr[rightChild] < arr[smallest]) {
            smallest = rightChild;
        }

        if (smallest != index) {
            swap(&arr[smallest], &arr[index]);
            index = smallest;
        } else {
            break;
        }
    }
}