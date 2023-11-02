#include "heap.h"
#include <stdio.h>

int main()
{
    Heap *heap = createHeap(10);

    // Insert values into the heap.
    for (int i = 1; i <= 10; i++)
    {
        insert(heap, i);
    }

    printf("Heap Size: %zu\n", getSize(heap));

    // Extract and print elements from the heap.
    while (!isEmpty(heap))
    {
        int top = extract(heap);
        printf("%d ", top);
    }
    printf("\n");

    // Destroy the heap and free memory.
    destroyHeap(heap);

    return 0;
}
