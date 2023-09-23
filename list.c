// list/list.c
// 
// Implementation for linked list.
//
// <Author>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "list.h"

list_t *list_alloc() {
    list_t *new_list = (list_t *)malloc(sizeof(list_t));
    if (new_list) {
        new_list->head = NULL;
    }
}

// Function to free the memory allocated for the list and its nodes.
void list_free(list_t *l) {
    if (!l) return; // Check if the list is NULL

    // Free each node in the list
    while (l->head != NULL) {
        node_t *temp = l->head;
        l->head = l->head->next;
        free(temp);
    }
}

void list_print(list_t *l) {
    if (!l) return; // Check if the list is NULL

    node_t *current = l->head;
    while (current != NULL) {
        printf("%d ", current->value);
        current = current->next;
    }
    printf("\n");
}


char * listToString(list_t *l) {
  char* buf = (char *) malloc(sizeof(char) * 1024);
  char tbuf[20];

	node_t* curr = l->head;
  while (curr != NULL) {
    sprintf(tbuf, "%d->", curr->value);
    curr = curr->next;
    strcat(buf, tbuf);
  }
  strcat(buf, "NULL");
  return buf;
}

int list_length(list_t *l) {
    if (!l) return 0; // Check if the list is NULL

    int length = 0;
    node_t *current = l->head;
    while (current != NULL) {
        length++;
        current = current->next;
    }
    return length;
}

void list_add_to_back(list_t *l, elem value) {
    if (!l) return; // Check if the list is NULL

    node_t *new_node = (node_t *)malloc(sizeof(node_t));
    if (new_node) {
        new_node->value = value;
        new_node->next = NULL;
        if (l->head == NULL) {
            l->head = new_node;
        } else {
            node_t *current = l->head;
            while (current->next != NULL) {
                current = current->next;
            }
            current->next = new_node;
        }
    } else {
        perror("Memory allocation failed");
        exit(EXIT_FAILURE);
    }
}

void list_add_to_front(list_t *l, elem value) {
    if (!l) return; // Check if the list is NULL

    node_t *new_node = (node_t *)malloc(sizeof(node_t));
    if (new_node) {
        new_node->value = value;
        new_node->next = l->head;
        l->head = new_node;
    } else {
        perror("Memory allocation failed");
        exit(EXIT_FAILURE);
    }
}

void list_add_at_index(list_t *l, elem value, int index) {
    if (!l) return; // Check if the list is NULL

    if (index < 1) {
        fprintf(stderr, "Invalid index\n");
        return;
    }

    node_t *new_node = (node_t *)malloc(sizeof(node_t));
    if (new_node) {
        new_node->value = value;

        if (index == 1) {
            new_node->next = l->head;
            l->head = new_node;
        } else {
            node_t *current = l->head;
            int i;
            for (i = 1; i < index - 1 && current != NULL; i++) {
                current = current->next;
            }
            if (current != NULL) {
                new_node->next = current->next;
                current->next = new_node;
            } else {
                fprintf(stderr, "Index out of bounds\n");
                free(new_node);
            }
        }
    } else {
        perror("Memory allocation failed");
        exit(EXIT_FAILURE);
    }
}

elem list_remove_from_back(list_t *l) {
    if (!l || !l->head) return -1; // Check if the list is NULL or empty

    if (l->head->next == NULL) {
        // Only one element in the list
        elem value = l->head->value;
        free(l->head);
        l->head = NULL;
        return value;
    }

    node_t *current = l->head;
    while (current->next->next != NULL) {
        current = current->next;
    }
    elem value = current->next->value;
    free(current->next);
    current->next = NULL;
    return value;
}

elem list_remove_from_front(list_t *l) {
    if (!l || !l->head) return -1; // Check if the list is NULL or empty

    node_t *temp = l->head;
    elem value = temp->value;
    l->head = temp->next;
    free(temp);
    return value;
}

elem list_remove_at_index(list_t *l, int index) {
    if (!l || !l->head || index < 1) return -1; // Check if the list is NULL, empty, or index is invalid

    if (index == 1) {
        return list_remove_from_front(l);
    }

    node_t *current = l->head;
    int i;
    for (i = 1; i < index - 1 && current != NULL; i++) {
        current = current->next;
    }
    if (current != NULL && current->next != NULL) {
        node_t *temp = current->next;
        elem value = temp->value;
        current->next = temp->next;
        free(temp);
        return value;
    } else {
        fprintf(stderr, "Index out of bounds\n");
        return -1;
    }
}


bool list_is_in(list_t *l, elem value) {
    if (!l) return false; // Check if the list is NULL

    node_t *current = l->head;
    while (current != NULL) {
        if (current->value == value) {
            return true;
        }
        current = current->next;
    }
    return false;
}

elem list_get_elem_at(list_t *l, int index) {
    if (!l || !l->head || index < 1) return -1; // Check if the list is NULL, empty, or index is invalid

    node_t *current = l->head;
    int i;
    for (i = 1; i < index && current != NULL; i++) {
        current = current->next;
    }
    if (current != NULL) {
        return current->value;
    } else {
        fprintf(stderr, "Index out of bounds\n");
        return -1;
    }
}

int list_get_index_of(list_t *l, elem value) {
    if (!l) return -1; // Check if the list is NULL

    node_t *current = l->head;
    int index = 1;
    while (current != NULL) {
        if (current->value == value) {
            return index;
        }
        current = current->next;
        index++;
    }
    return -1; // Element not found
}

