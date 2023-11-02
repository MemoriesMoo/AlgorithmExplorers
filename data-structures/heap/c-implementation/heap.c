#include "heap.h"
#include <stdlib.h>
#include <stdio.h>

// Helper function to swap two integers.
static void swap(int *x, int *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}

// Helper function to adjust the heap upwards to maintain the heap property.
static void heapifyUp(Heap *heap, size_t index)
{
    size_t parent = (index - 1) / 2;

    while (index > 0 && heap->elements[index] < heap->elements[parent])
    {
        swap(&heap->elements[index], &heap->elements[parent]);
        index = parent;
        parent = (index - 1) / 2;
    }
}

// Helper function to adjust the heap downwards to maintain the heap property.
static void heapifyDown(Heap *heap, size_t index)
{
    while (1)
    {
        size_t leftChild = (index * 2) + 1;
        size_t rightChild = leftChild + 1;
        size_t smallest = index;

        if (leftChild < heap->size && heap->elements[leftChild] < heap->elements[smallest])
        {
            smallest = leftChild;
        }

        if (rightChild < heap->size && heap->elements[rightChild] < heap->elements[smallest])
        {
            smallest = rightChild;
        }

        if (smallest != index)
        {
            swap(&heap->elements[smallest], &heap->elements[index]);
            index = smallest;
        }
        else
        {
            break;
        }
    }
}

// Create a new heap with the specified capacity.
Heap *createHeap(size_t capacity)
{
    Heap *heap = (Heap *)malloc(sizeof(Heap));
    heap->elements = (int *)malloc(sizeof(int) * capacity);
    heap->capacity = capacity;
    heap->size = 0;
    return heap;
}

// Insert a value into the heap.
void insert(Heap *heap, int val)
{
    if (heap->size >= heap->capacity)
    {
        fprintf(stderr, "Heap is full\n");
        exit(1);
    }

    heap->elements[heap->size] = val;
    heapifyUp(heap, heap->size);
    heap->size++;
}

// Extract the top element from the heap.
int extract(Heap *heap)
{
    if (heap->size == 0)
    {
        fprintf(stderr, "Heap is empty\n");
        exit(1);
    }

    int top = heap->elements[0];
    heap->elements[0] = heap->elements[heap->size - 1];
    heap->size--;
    heapifyDown(heap, 0);
    return top;
}

// Return the top element from the heap without removing it.
int peek(const Heap *heap)
{
    if (heap->size == 0)
    {
        fprintf(stderr, "Heap is empty\n");
        exit(1);
    }

    return heap->elements[0];
}

// Check if the heap is empty.
int isEmpty(const Heap *heap)
{
    return (heap->size == 0) ? 1 : 0;
}

// Get the current number of elements in the heap.
size_t getSize(const Heap *heap)
{
    return heap->size;
}

// Destroy the heap and free memory.
void destroyHeap(Heap *heap)
{
    free(heap->elements);
    free(heap);
}
