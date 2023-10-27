#include "LinkedList.h"

// Function to create a new list node with the given value
ListNode *create_node(valType val) {
    // Allocate memory for a new list node
    ListNode *temp_cell = (ListNode *) malloc(sizeof(ListNode));

    // Check if memory allocation was successful
    if (temp_cell) {
        temp_cell->data = val;   // Set the data of the node
        temp_cell->next = NULL;  // Initialize the next pointer
    } else {
        // Memory allocation failed
        fprintf(stderr, "Malloc fail! Memory allocation failed in create_node function.\n");
        exit(-1); // Exit the program
    }

    return temp_cell;
}

// Function to create an empty list
void create_list(List *list) {
    assert(list);  // Ensure that the provided list pointer is not NULL
    list->head = NULL; // Initialize the list by setting the head pointer to NULL
}

// Function to print the elements in the list
void list_print(const List *list) {
    assert(list);  // Ensure that the provided list pointer is not NULL
    if (list->head) {
        // If the list is not empty
        ListNode *cur = list->head;

        while (cur) {
            if (cur->next == NULL)
                printf("%d\n", cur->data);  // Print the data of the current node
            else
                printf("%d -> ", cur->data);  // Print the data followed by an arrow
            cur = cur->next;  // Move to the next node
        }
    } else {
        printf("Empty list!\n");  // If the list is empty, print a message
    }
}

// Function to add an element to the end of the list
void list_push_back(List *list, valType val) {
    assert(list);  // Ensure that the provided list pointer is not NULL
    ListNode *new_node;

    new_node = create_node(val);  // Create a new node with the provided value
    if (list->head == NULL) {
        // If the list is empty, set the head pointer to the new node
        list->head = new_node;
    } else {
        ListNode *cur = list->head;

        // Traverse to the end of the list to find the last node
        while (cur->next != NULL) {
            cur = cur->next;
        }

        cur->next = new_node;  // Set the next pointer of the last node to the new node
    }
}

// Function to add an element to the front of the list
void list_push_front(List *list, valType val) {
    assert(list);  // Ensure that the provided list pointer is not NULL
    ListNode *new_node;

    new_node = create_node(val);  // Create a new node with the provided value
    if (list->head == NULL) {
        // If the list is empty, set the head pointer to the new node
        list->head = new_node;
    } else {
        ListNode *front_node = list->head;
        list->head = new_node;  // Set the head pointer to the new node
        new_node->next = front_node;  // Link the new node to the previous head
    }
}

// Function to remove an element from the front of the list
void list_pop_front(List *list) {
    assert(list);

    if (list->head != NULL) {
        ListNode *front_node = list->head;
        ListNode *second_node = front_node->next;
        list->head = second_node;  // Set the head pointer to the second node
        free(front_node);  // Free the memory of the removed node
    }
}

// Function to remove an element from the end of the list
void list_pop_back(List *list) {
    assert(list);

    if (list->head != NULL) {
        ListNode *cur = list->head;

        if (cur->next == NULL) {
            // If there is only one node in the list, set the head pointer to NULL
            list->head = NULL;
            return;
        }

        while (cur->next->next != NULL) {
            cur = cur->next;
        }

        ListNode *last_node = cur->next;
        cur->next = NULL;  // Remove the link to the last node
        free(last_node);  // Free the memory of the removed node
    }
}

// Function to destroy the list and free the memory
void list_destroy(List *list) {
    assert(list);

    if (list->head != NULL) {
        ListNode *cur = list->head;
        ListNode *del = NULL;

        while (cur) {
            del = cur;
            cur = cur->next;
            free(del);  // Free the memory of each node in the list
        }

        list->head = NULL;  // Set the head pointer to NULL to indicate an empty list
    }
}

// Function to get the length of the list
int list_length(List *list) {
    assert(list);  // Ensure that the provided list pointer is not NULL
    int count = 0;

    if (list->head != NULL) {
        ListNode *cur = list->head;

        while (cur) {
            ++count;  // Increment the count for each node in the list
            cur = cur->next;
        }
    }

    return count;  // Return the total number of elements in the list
}

// Function to find a node with a specific value in the list
ListNode *list_find(List *list, valType value) {
    assert(list);  // Ensure that the provided list pointer is not NULL

    ListNode *cur = list->head;  // Start from the head of the list

    while (cur) {
        if (cur->data == value) {
            return cur;  // Return the node when the value is found
        }
        cur = cur->next;  // Move to the next node
    }

    return NULL;  // Return NULL if the value is not found in the list
}

// Function to insert a new node with the given value at the specified position in the list.
int list_insert(List *list, valType value, int position) {
    assert(list);  // Ensure that the provided list pointer is not NULL

    if (position < 0) {
        return 0;  // Invalid position, return 0
    }

    ListNode *new_node = create_node(value);  // Create a new node with the specified value
    if (position == 0) {
        // Insert at the beginning
        new_node->next = list->head;
        list->head = new_node;
    } else {
        ListNode *cur = list->head;
        int current_position = 0;

        while (cur) {
            if (current_position == position - 1) {
                // Insert after the previous node
                new_node->next = cur->next;
                cur->next = new_node;
                return 1;  // Insertion successful
            }
            cur = cur->next;
            current_position++;
        }

        return 0;  // Specified position is out of bounds
    }

    return 1;  // Insertion successful
}

// Function to remove nodes with a specific value from the list.
void list_remove(List *list, valType value) {
    assert(list);  // Ensure that the provided list pointer is not NULL

    ListNode *cur = list->head;
    ListNode *prev = NULL;  // Keep track of the previous node

    while (cur) {
        if (cur->data == value) {
            // Node with the specified value found
            if (prev) {
                // Update the next pointer of the previous node
                prev->next = cur->next;
            } else {
                // If the head node has the specified value
                list->head = cur->next;
            }

            // Free the memory of the removed node
            free(cur);
            cur = prev ? prev->next : list->head;  // Move to the next node
        } else {
            prev = cur;
            cur = cur->next;  // Move to the next node
        }
    }
}
