#ifndef C_IMPLEMENTATION_LINKEDLIST_H
#define C_IMPLEMENTATION_LINKEDLIST_H

#include <stdio.h>
#include <stdlib.h> // Use <stdlib.h> for memory allocation functions
#include <assert.h>

typedef int valType;

// Structure to represent a node in the linked list
struct ListNode {
    valType data;          // Data held by the node
    struct ListNode *next; // Pointer to the next node
};

typedef struct ListNode ListNode;

// Structure to represent a linked list
struct List {
    ListNode *head; // Pointer to the head (first node) of the list
};

typedef struct List List;

/**
 * Function to create a new list node with the given value.
 *
 * @param val The value to be stored in the new node.
 * @return A pointer to the newly created node on success, or NULL if memory allocation fails.
 */
ListNode *create_node(valType val);

/**
 * Function to create an empty list.
 *
 * @param list A pointer to the List structure to be initialized as an empty list.
 */
void create_list(List *list);

/**
 * Function to print the elements in the list.
 *
 * @param list A pointer to the List structure to be printed.
 */
void list_print(const List *list);

/**
 * Function to add an element to the end of the list.
 *
 * @param list A pointer to the List structure to which the element is added.
 * @param val The value to be added to the list.
 */
void list_push_back(List *list, valType val);

/**
 * Function to add an element to the front of the list.
 *
 * @param list A pointer to the List structure to which the element is added.
 * @param val The value to be added to the list.
 */
void list_push_front(List *list, valType val);

/**
 * Function to remove an element from the front of the list.
 *
 * @param list A pointer to the List structure from which the element is removed.
 */
void list_pop_front(List *list);

/**
 * Function to remove an element from the end of the list.
 *
 * @param list A pointer to the List structure from which the element is removed.
 */
void list_pop_back(List *list);

/**
 * Function to destroy the list and free the memory.
 *
 * @param list A pointer to the List structure to be destroyed.
 */
void list_destroy(List *list);

/**
 * Function to get the length of the list.
 *
 * @param list A pointer to the List structure.
 * @return The number of elements in the list.
 */
int list_length(List *list);

/**
 * Function to find a node with a specific value in the list.
 *
 * @param list A pointer to the List structure.
 * @param value The value to search for in the list.
 * @return A pointer to the first node with the specified value if found, or NULL if not found.
 */
ListNode *list_find(List *list, valType value);

/**
 * Function to insert a new node with the given value at the specified position in the list.
 *
 * @param list A pointer to the List structure.
 * @param value The value to be inserted into the list.
 * @param position The position at which the value should be inserted (0-based index).
 * @return 1 if the insertion is successful, 0 if the specified position is out of bounds.
 */
int list_insert(List *list, valType value, int position);

/**
 * Function to remove nodes with a specific value from the list.
 *
 * @param list A pointer to the List structure from which nodes should be removed.
 * @param value The value to be removed from the list.
 */
void list_remove(List *list, valType value);

#endif // C_IMPLEMENTATION_LINKEDLIST_H
