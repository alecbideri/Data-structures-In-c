#include<stdio.h>
#include<stdlib.h>

struct Node{
	
	int data ;
	struct Node* next ;
	struct Node* prev	;
};

void insert_tail(struct Node** head , int new_data) {
	struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));

	if(new_node==NULL) {
		printf("memory allocation failed\n");
		return ;
	}

	new_node->data = new_data ;
	new_node->next = NULL ;

	if(*head == NULL) {
		new_node->prev = NULL ;
		*head = new_node ;
		return ;
	}else{
		struct Node* current = * head ;
		while(current->next!=NULL) {
			current = current->next ;
		}

		current->next = new_node ;
		new_node->prev = current ;
	}
	
}

void insert_head(struct Node** head , int new_data) {
	struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
	
	if(new_node==NULL) {
		printf("memory allocation failed\n");
		return ;
	}

	new_node->data = new_data ;
	new_node->prev = NULL ;
	new_node->next = *head ;

	if(*head!=NULL) {
		new_node->prev = new_node ;
	}

	*head= new_node ;

}
void display(struct Node*head) {
	struct Node* current = head ;
	while(current!=NULL) {
		printf("<-%d-> " , current->data);
		current = current->next ;
	}

	printf("NULL\n");
}

int main() {
		
	struct Node* head = NULL ;
	
	for(int i = 0 ; i<=7 ; i++) {
		insert_head(&head , i);
	}	

    display(head);
	
	return 0 ;
}