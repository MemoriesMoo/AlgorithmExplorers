#include "LinkedList.h"
#include <stdio.h>

int main() {
    List myList;
    create_list(&myList);  // Create an empty list

    // Test list_push_back and list_length functions
    list_push_back(&myList, 10);
    int length = list_length(&myList);
    printf("Length of the list: %d\n", length);  // Expected output: 1

    list_push_back(&myList, 20);
    list_push_back(&myList, 30);

    length = list_length(&myList);
    printf("Length of the list: %d\n", length);  // Expected output: 3

    // Test list_print function
    printf("List elements: ");
    list_print(&myList);  // Expected output: 10 -> 20 -> 30

    // Test list_push_front function
    list_push_front(&myList, 5);
    list_push_front(&myList, 0);

    printf("List after pushing to the front: ");
    list_print(&myList);  // Expected output: 0 -> 5 -> 10 -> 20 -> 30

    // Test list_pop_front function
    list_pop_front(&myList);
    printf("List after popping from the front: ");
    list_print(&myList);  // Expected output: 5 -> 10 -> 20 -> 30

    // Test list_pop_back function
    list_pop_back(&myList);
    printf("List after popping from the back: ");
    list_print(&myList);  // Expected output: 5 -> 10 -> 20

    // Test list_remove function
    valType value_to_remove = 10;
    list_remove(&myList, value_to_remove);

    printf("List after removing %d: ", value_to_remove);
    list_print(&myList);  // Expected output: 5 -> 20

    // Test list_insert function
    valType value_to_insert = 15;
    int insert_position = 1;
    list_insert(&myList, value_to_insert, insert_position);

    printf("List after inserting %d at position %d: ", value_to_insert, insert_position);
    list_print(&myList);  // Expected output: 5 -> 15 -> 20

    // Test list_find function
    valType value_to_find = 20;
    ListNode *found_node = list_find(&myList, value_to_find);
    if (found_node) {
        printf("Found %d at position %d\n", value_to_find, list_length(&myList) - list_length(found_node));  // Expected output: Found 20 at position 1
    } else {
        printf("%d not found in the list\n", value_to_find);
    }

    list_destroy(&myList);  // Destroy the list and free memory

    return 0;
}
