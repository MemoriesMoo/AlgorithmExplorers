#pragma one

#include <iostream>
#include <vector>

/**
 * @brief A template class for a generic heap data structure.
 *
 * @tparam T The data type of elements in the heap.
 */
template<typename T>
class Heap {
private:
    T* elements_;      /**< An array to store heap elements */
    size_t capacity_;  /**< The capacity of the heap */
    size_t size_;      /**< The current number of elements in the heap */

    /**
     * @brief Swaps the values of two elements.
     *
     * @param x Reference to the first element.
     * @param y Reference to the second element.
     */
    void swap(T& x, T& y) {
        T temp = x;
        x = y;
        y = temp;
    }

    /**
     * @brief Adjusts the heap upwards to maintain the heap property.
     *
     * @param index The index to start the heapify process from.
     */
    void heapifyUp(size_t index) {
        size_t parent = (index - 1) / 2;

        while (index > 0 && elements_[index] < elements_[parent]) {
            swap(elements_[index], elements_[parent]);
            index = parent;
            parent = (index - 1) / 2;
        }
    }

    /**
     * @brief Adjusts the heap downwards to maintain the heap property.
     *
     * @param index The index to start the heapify process from.
     */
    void heapifyDown(size_t index) {
        while (true) {
            size_t leftChild = (index * 2) + 1;
            size_t rightChild = leftChild + 1;
            size_t smallest = index;

            if (leftChild < size_ && elements_[leftChild] < elements_[smallest]) { smallest = leftChild; }

            if (rightChild < size_ && elements_[rightChild] < elements_[smallest]) { smallest = rightChild; }

            if (smallest != index) {
                swap(elements_[smallest], elements_[index]);
                index = smallest;
            } else {
                break;
            }
        }
    }

public:
    /**
     * @brief Constructor for the Heap class.
     *
     * @param capacity The maximum capacity of the heap.
     */
    explicit Heap(size_t capacity) : capacity_(capacity), size_(0) {
        elements_ = new T[capacity];
    }

    /**
     * @brief Inserts a value into the heap.
     *
     * @param val The value to be inserted.
     */
    void insert(const T& val) {
        if (size_ >= capacity_) {
            throw std::runtime_error("Heap is full");
        }

        elements_[size_] = val;
        heapifyUp(size_);
        ++size_;
    }

    /**
     * @brief Extracts the top element from the heap.
     *
     * @return The top element from the heap.
     */
    T extract() {
        if (size_ == 0) {
            throw std::runtime_error("Heap is empty");
        }

        T top = elements_[0];
        elements_[0] = elements_[size_ - 1];
        --size_;
        heapifyDown(0);
        return top;
    }

    /**
     * @brief Returns the top element from the heap without removing it.
     *
     * @return The top element from the heap.
     */
    T peek() const {
        if (size_ == 0) {
            throw std::runtime_error("Heap is empty");
        }

        return elements_[0];
    }

    /**
     * @brief Checks if the heap is empty.
     *
     * @return True if the heap is empty, otherwise false.
     */
    [[nodiscard]] bool empty() const { return size_ == 0; }

    /**
     * @brief Gets the current number of elements in the heap.
     *
     * @return The size of the heap.
     */
    [[nodiscard]] size_t size() const { return size_; }
};
