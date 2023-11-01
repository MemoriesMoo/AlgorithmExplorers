#include "Heap.hpp"

int main() {
    // Create a min-heap with a capacity of 10.
    Heap<int> minHeap(10);

    // Insert elements into the heap.
    minHeap.insert(5);
    minHeap.insert(3);
    minHeap.insert(8);
    minHeap.insert(1);
    minHeap.insert(10);

    // Print the elements extracted from the heap (sorted in ascending order).
    while (!minHeap.empty()) {
        int top = minHeap.extract();
        std::cout << top << " ";
    }

    std::cout << std::endl;

    return 0;
}
