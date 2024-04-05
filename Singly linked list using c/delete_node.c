#include<stdio.h>
#include<stdlib.h>
struct Node{
    int data ;
    struct Node* next ;
};

void insert_node_head(struct Node**head , int new_data) {
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    if(new_node==NULL) {
        printf("memory allocation failed\n");
        return ;
    }
    new_node->data = new_data;
    new_node->next = *head ;
    *head = new_node;
    printf("%d is inserted at head\n" , new_data);
}

void delete_node(struct Node** head , int key) {
    struct Node * current = * head ;
    struct Node * prev = NULL ;

    if(current!=NULL && current->data ==key) {
        *head = current->next;
        free(current);
        return ;
    }

    while(current!=NULL && current->data!=key) {
        prev = current ;
        current=current->next ;
    }

    if(current==NULL) {
        printf("key not found\n");
    }

    prev->next = current->next;
}

void display(struct Node* head) {
    struct Node* current = head ;
    while(current!=NULL) {
        printf("%d-> " , current->data);
        current = current->next ;
    }
    printf("NULL\n");
}

int main() {
    struct Node* head = NULL ;
    for(int i = 0 ; i<=7 ; i++) {
        insert_node_head(&head , i);
    }
    display(head);
    delete_node(&head , 3);
    display(head);
    return 0 ;
}