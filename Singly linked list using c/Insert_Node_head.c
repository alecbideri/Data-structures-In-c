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
    return 0 ;
}