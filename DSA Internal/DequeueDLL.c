#include <stdio.h>
#include <stdlib.h>
struct node {
   int data;
   struct node* next;
   struct node* prev;
};

struct node* front = NULL;
struct node* rear = NULL;

void insertFront(int value) {
   struct node* newNode = (struct node*)malloc(sizeof(struct node));
   newNode->data = value;
   newNode->prev = NULL;
   newNode->next = front;
   if (front == NULL)
      rear = newNode;
   else
      front->prev = newNode;
   front = newNode;
   printf("%d inserted at front successfully\n", value);
}

void insertRear(int value) {
   struct node* newNode = (struct node*)malloc(sizeof(struct node));
   newNode->data = value;
   newNode->next = NULL;
   newNode->prev = rear;
   if (rear == NULL)
      front = newNode;
   else
      rear->next = newNode;
   rear = newNode;
   printf("%d inserted at rear successfully\n", value);
}

void deleteFront() {
   if (front == NULL) {
      printf("Deque is empty.\n");
      return;
   }
   struct node* temp = front;
   front = front->next;
   if (front == NULL)
      rear = NULL;
   else
      front->prev = NULL;
   free(temp);
   printf("Deleted element from front.\n");
}

void deleteRear() {
   if (rear == NULL) {
      printf("Deque is empty.\n");
      return;
   }
   struct node* temp = rear;
   rear = rear->prev;
   if (rear == NULL)
      front = NULL;
   else
      rear->next = NULL;
   free(temp);
   printf("Deleted element from rear.\n");
}

void display() {
   if (front == NULL) {
      printf("Deque is empty.\n");
      return;
   }
   struct node* temp = front;
   printf("Deque: ");
   while (temp != NULL) {
      printf("%d ", temp->data);
      temp = temp->next;
   }
   printf("\n");
}

int main()
{
    struct node* head = NULL;
    int choice, data;
    while (1)
    {
        printf("\n1 : Insert at first\n");
        printf("2 : Insert at end\n");
        printf("3 : Delete at first\n");
        printf("4 : Delete at end\n");
        printf("5 : Display\n");
        printf("6 : EXIT\n");

        printf("Enter your choice : ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("\nEnter the data to be inserted: ");
            scanf("%d",&data);
            insertFront(data);
            break;
        case 2:
            printf("\nEnter the data to be inserted : ");
            scanf("%d",&data);
            insertRear(data);
            break;
        case 3:
            deleteFront();
            break;
        case 4:
            deleteRear();
            break;
        case 5:
            display();
            break;
        case 6:
            printf("...EXITING...");
            exit(0);
        default:
            printf("\nInvalid choice");
        }
    }
}