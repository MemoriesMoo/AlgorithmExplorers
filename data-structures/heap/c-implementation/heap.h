#ifndef HEAP_H
#define HEAP_H

#include <stddef.h>

/**
 * @brief The Heap structure represents a min-heap.
 */
typedef struct
{
    int *elements;   /**< An array to store heap elements */
    size_t capacity; /**< The maximum capacity of the heap */
    size_t size;     /**< The current number of elements in the heap */
} Heap;

/**
 * @brief Creates a new heap with the specified capacity.
 *
 * @param capacity The maximum number of elements the heap can hold.
 * @return A pointer to the created heap.
 */
Heap *createHeap(size_t capacity);

/**
 * @brief Inserts a value into the heap.
 *
 * @param heap The heap to insert into.
 * @param val The value to be inserted.
 */
void insert(Heap *heap, int val);

/**
 * @brief Extracts the top element from the heap.
 *
 * @param heap The heap to extract from.
 * @return The top element from the heap.
 */
int extract(Heap *heap);

/**
 * @brief Returns the top element from the heap without removing it.
 *
 * @param heap The heap to peek into.
 * @return The top element from the heap.
 */
int peek(const Heap *heap);

/**
 * @brief Checks if the heap is empty.
 *
 * @param heap The heap to check for emptiness.
 * @return 1 if the heap is empty, otherwise 0.
 */
int isEmpty(const Heap *heap);

/**
 * @brief Gets the current number of elements in the heap.
 *
 * @param heap The heap to get the size of.
 * @return The size of the heap.
 */
size_t getSize(const Heap *heap);

/**
 * @brief Destroys the heap and frees memory.
 *
 * @param heap The heap to be destroyed.
 */
void destroyHeap(Heap *heap);

#endif
