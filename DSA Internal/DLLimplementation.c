#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *prev;
    struct node *next;
};
struct node *head = NULL;
void insertAtFirst(int value){
    struct node *newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = value;
    newNode->prev = NULL;
    newNode->next = head;
    if(head != NULL){
        head->prev = newNode;
    }
    head = newNode;
    printf("Inserted %d at beginning\n", value);
}

void insertAtLast(int value){
    struct node *newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = value;
    newNode->next = NULL;
    if(head == NULL){
        newNode->prev = NULL;
        head = newNode;
        printf("Inserted %d at end\n", value);
        return;
    }
    struct node *temp = head;
    while(temp->next != NULL){
        temp = temp->next;
    }
    temp->next = newNode;
    newNode->prev = temp;
    printf("Inserted %d at end\n", value);
}

void delAtFirst(){
    if(head == NULL){
        printf("List is empty.\n");
        return;
    }
    struct node *temp = head;
    head = head->next;
    if(head != NULL){
        head->prev = NULL;
    }
    free(temp);
    printf("Deleted element from beginning.\n");
}

void delLastNode(){
    if(head == NULL){
        printf("List is empty.\n");
        return;
    }
    struct node *temp = head;
    while(temp->next != NULL){
        temp = temp->next;
    }
    if(temp == head){
        head = NULL;
    }
    else{
        temp->prev->next = NULL;
    }
    free(temp);
    printf("Deleted element from end.\n");
}

void display(){
    struct node *temp = head;
    printf("List: ");
    while(temp != NULL){
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
            insertAtFirst(data);
            break;
        case 2:
            printf("\nEnter the data to be inserted : ");
            scanf("%d",&data);
            insertAtLast(data);
            break;
        case 3:
            delAtFirst();
            break;
        case 4:
            delLastNode();
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
