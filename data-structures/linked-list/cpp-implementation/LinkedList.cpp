#include <iostream>

template<typename T>
class SinglyLinkedList {
    typedef T valType;
private:
    class Node {
    public:
        valType data;
        Node *next;

        /**
         * @brief Constructor for Node class, used to create node objects.
         * @param val The value to be stored in the node.
         */
        explicit Node(const valType &val) : data(val), next(nullptr) {}
    };

    Node *head;
    int size;

public:
    /**
     * @brief Constructor for SinglyLinkedLIst class, initializes the head pointer and size.
     */
    SinglyLinkedList() : head(nullptr), size(0) {}

    /**
     * @brief Inserts a new element at the front of the linked list.
     * @param val The value to be inserted.
     */
    void pushFront(const valType &val) {
        Node *newNode = new Node(val);

        newNode->next = head;
        head = newNode;
        ++size;
    }

    /**
     * @brief Removes an element from the front of the linked list.
     */
    void popFront() {
        if (!head) { return; }

        Node *del = head;
        head = head->next;
        delete del;
        --size;
    }

    /**
     * @brief Inserts a new element at the back of the linked list.
     * @param val The value to be inserted.
     */
    void pushBack(const valType &val) {
        Node *newNode = new Node(val);

        Node *cur;
        cur = head;
        if (!cur) {
            head = newNode;
        } else {
            while (cur->next) {
                cur = cur->next;
            }
        }

        cur->next = newNode;
        ++size;
    }

    /**
     * @brief Removes an element from the back of the linked list.
     */
    void popBack() {
        if (!head) { return; }

        Node *cur = head;
        if (!cur->next) {
            delete cur;
            head = nullptr;
        } else {
            while (cur->next->next) {
                cur = cur->next;
            }
            delete cur->next;
            cur->next = nullptr; // Set the next of the new last node to nullptr
        }
        --size;
    }


    /**
     * @brief Removes an element with the specified value from the linked list.
     * @param val The value to be removed.
     */
    void remove(const valType &val) {
        if (!head) { return; }

        if (head->data == val) {
            Node *del = head;
            head = head->next;
            delete del;
            --size;
            return;
        }

        Node *cur = head;
        while (cur->next) {
            if (cur->next->data == val) {
                Node *del = cur->next;
                cur->next = del->next;
                delete del;
                --size;
                return;
            }
            cur = cur->next;
        }
    }

    /**
     * @brief Prints the elements of the linked list.
     */
    void print() {
        Node *cur = head;
        while (cur) {
            std::cout << cur->data << " ";
            cur = cur->next;
        }
        std::cout << std::endl;
    }

    /**
     * @brief Returns the size of the linked list.
     * @return The number of elements in the linked list.
     */
    [[nodiscard]] int getSize() const { return size; }

    /**
     * @brief Destructor for the SinglyLinkedLIst class, clears the linked list.
     */
    ~SinglyLinkedList() {
        clear();
    }

    /**
     * @brief Finds the first node with the specified value in the linked list.
     * @param val The value to search for in the linked list.
     * @return A pointer to the first node with the specified value if found, or NULL if not found.
     */
    Node *find(const valType &val) {
        Node *cur = head;
        while (cur) {
            if (cur->data == val) { return cur; }
            cur = cur->next;
        }

        return nullptr;
    }

    /**
     * @brief Inserts an element with the specified value at the given position in the linked list.
     * @param val The value to be inserted.
     * @param position The position at which to insert the value.
     * @return True if the insertion was successful, or false if the position is invalid.
     */
    bool insertAt(const valType &val, int position) {
        if (position < 0 || position > size) { return false; }

        if (position == 0) {
            pushFront(val);
        } else if (position == size - 1) {
            pushBack(val);
        } else {
            Node *newNode = new Node(val);
            Node *cur = head;

            for (int i = 0; i < position - 1; i++) {
                cur = cur->next;
            }
            newNode->next = cur->next;
            cur->next = newNode;
        }

        ++size;
        return true;
    }

    /**
     * @brief Removes an element at the specified position in the linked list.
     * @param position The position of the element to be removed.
     * @return True if the removal was successful, or false if the position is invalid.
     */
    bool removeAt(int position) {
        if (position < 0 || position >= size) {
            return false;
        }

        if (position == 0) {
            popFront();
        } else {
            Node *current = head;
            for (int i = 0; i < position - 1; i++) {
                current = current->next;
            }

            Node *temp = current->next;
            current->next = temp->next;
            delete temp;
            size--;
        }

        return true;
    }

    /**
     * @brief Clears the linked list and releases memory.
     */
    void clear() {
        while (head) {
            Node *temp = head;
            head = head->next;
            delete temp;
        }
        size = 0;
        head = nullptr;
    }

    /**
     * @brief Reverses the order of elements in the linked list.
     */
    void reverse() {
        if (size <= 1) {
            return;
        }

        Node *prev = nullptr;
        Node *cur = head;
        Node *nextNode = nullptr;

        while (cur) {
            nextNode = cur->next;
            cur->next = prev;
            prev = cur;
            cur = nextNode;
        }

        head = prev;
    }
};

#include <iostream>

int main() {
    SinglyLinkedList<int> myList;

    // Test pushFront
    myList.pushFront(3);
    myList.pushFront(2);
    myList.pushFront(1);

    // Test pushBack
    myList.pushBack(4);
    myList.pushBack(5);

    // Print the elements in the list
    std::cout << "Elements in the list: ";
    myList.print();

    // Test popFront
    myList.popFront();
    std::cout << "After popping the front: ";
    myList.print();

    // Test popBack
    myList.popBack();
    std::cout << "After popping the back: ";
    myList.print();

    // Test remove
    myList.remove(3);
    std::cout << "After removing 3: ";
    myList.print();

    // Test getSize
    std::cout << "Size of the list: " << myList.getSize() << std::endl;

    // Test insertAt
    myList.insertAt(6, 2);
    std::cout << "After inserting 6 at position 2: ";
    myList.print();

    // Test removeAt
    myList.removeAt(1);
    std::cout << "After removing the element at position 1: ";
    myList.print();

    // Test reverse
    myList.reverse();
    std::cout << "After reversing the list: ";
    myList.print();

    // Test clear
    myList.clear();
    std::cout << "After clearing the list: ";
    myList.print();

    // Additional Tests
    myList.pushFront(10);
    myList.pushBack(20);
    myList.pushBack(30);
    myList.insertAt(15, 2);
    std::cout << "After additional operations: ";
    myList.print();

//    // Test find
//    int valueToFind = 20;
//    SinglyLinkedList<int>::Node* foundNode = myList.find(valueToFind);
//    if (foundNode) {
//        std::cout << "Found " << valueToFind << " in the list." << std::endl;
//    } else {
//        std. cout << valueToFind << " not found in the list." << std::endl;
//    }

    return 0;
}
