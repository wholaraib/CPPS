#include <stdio.h>
#include <stdlib.h>
 
struct node {
    int data;
    struct node *next;
};
 
struct node *find_middle_node(struct node *head) {
    if (head == NULL) {
        return NULL;
    }
 
    struct node *slow_ptr = head;
    struct node *fast_ptr = head;
 
    while (fast_ptr != NULL && fast_ptr->next != NULL) {
        slow_ptr = slow_ptr->next;
        fast_ptr = fast_ptr->next->next;
    }
 
    return slow_ptr;
}
 
int main() {
    // create a sample linked list
    struct node *head = (struct node *) malloc(sizeof(struct node));
    head->data = 1;
 
    struct node *node2 = (struct node *) malloc(sizeof(struct node));
    node2->data = 2;
 
    struct node *node3 = (struct node *) malloc(sizeof(struct node));
    node3->data = 3;
 
    struct node *node4 = (struct node *) malloc(sizeof(struct node));
    node4->data = 4;
 
    head->next = node2;
    node2->next = node3;
    node3->next = node4;
    node4->next = NULL;
 
    // find the middle node of the linked list
    struct node *middle_node = find_middle_node(head);
 
    if (middle_node == NULL) {
        printf("The linked list is empty.\n");
    } else {
        printf("The middle node of the linked list is: %d\n", middle_node->data);
    }
 
    return 0;
}
