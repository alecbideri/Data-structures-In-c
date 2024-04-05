#include<stdio.h>
#include<stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

void insert_node_tail(struct Node** head , int new_data) {
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    if(new_node==NULL) {
        printf("Mempory Error");
        return ;
    }

    new_node->data = new_data;
    new_node->next = NULL ;

    if(*head==NULL){
        *head = new_node;
        return ;
    }
    else {
        struct Node* current = *head ;
        while(current->next!=NULL){
            current = current->next ;
        }
        current->next = new_node ;
    }
}

void display(struct Node* head){
    struct Node* current = head;
    while(current!=NULL){
        printf("%d->" , current->data);
        current =current->next ;
    }

    printf("NULL\n");
}

int main() {

    struct Node* head = NULL ;

    for (int i = 0; i < 10; i++)
    {
        insert_node_tail(&head , i);
    }

    display(head);
    return 0 ;
}

