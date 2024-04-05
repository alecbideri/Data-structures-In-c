#include<stdio.h>
#include<stdlib.h>

struct Node{
	int data ;
	struct Node* next; 
};

void insert_node_tail(struct Node** head ) {
	for (int i = 0 ; i<=7 ; i++) {

	struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));

	if(new_node==NULL){
		printf("memory allocation failed\n");
		return ;
	}

	new_node->data = i ;
	new_node->next = NULL ;

	if(*head==NULL) {
		*head=new_node ;
	}else{
		struct Node* current = * head ;
		while(current->next!=NULL){
			current = current->next ;
		}

		current->next = new_node ;
	}
  }
}

void insert_node_head(struct Node** head) {
	for(int i = 0 ; i<=7 ; i++) {

	struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
	if(new_node==NULL) {
		printf("memory allocation failed\n");
		return ;
	}

	new_node->data = i ;
	new_node->next = *head ;
	*head = new_node ;
	}
}

void delete_node(struct Node**head ) {
	if(*head==NULL) {
		printf("Linked list is empty\n");
		return ;
	}

	struct Node* current = *head ;
	struct Node* prev = NULL ;

    int key ;

    printf("Enter the key to be deleted:");
    scanf("%d" , &key);

	if(current!=NULL && current->data == key) {
		*head = current->next ;
		free(current);
        return;  // return after deleting the node at the head
	}

	while(current!=NULL && current->data != key) {
		prev = current;
		current = current->next ;
	}	

	if(current==NULL) {
		printf("Key not found\n");
        return;  // return if the key is not found
	}

    if(prev!=NULL) {
        prev->next = current->next ;
    }else{
        *head = current->next ;
    }
}

void delete_all_nodes(struct Node**head){
	if(*head==NULL) {
		printf("List is empty\n");
		return ;
	}

	struct Node* current = *head ;
	while(current!=NULL) {
		struct Node* next_node = current->next ;
		free(current);
		current = next_node;
	}

	*head = NULL ;
	printf("All nodes are deleted\n");
}


int find_min(struct Node* head) {
	if(head==NULL) {
		printf("Linkde list is empty\n");
		return -1 ;
	}

	struct Node* current = head->next ;
	int min_val = head->data ;

	while(current!=NULL) {
		if(current->data < min_val) {
			min_val = current->data ;
		}

		current = current->next ;
	}

	printf("The minimum value is :%d" , min_val) ;

	return min_val ;
}


int find_max(struct Node* head) {
	if(head==NULL) {
		printf("Linked list is empty\n");
		return -1 ;
	}

	struct Node* current = head->next ;
	int max_val = head->data ;

	while(current!=NULL) {
		if(current->data > max_val) {
			max_val = current->data ;
		}

		current = current->next ;
	}


	printf("The maximum value is:%d"  , max_val);

	return max_val ;
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
	
	struct Node* head = NULL;
	int a ;
	do {

	printf("\n\t\tSingly linked list\n");
	printf("\t\t______________________\n");
	printf("\t\t1.Insert Node at head\n");
	printf("\t\t2.Insert Node at tail\n");
	printf("\t\t3.Delete Node\n");
	printf("\t\t4.Find maximum value\n");
	printf("\t\t5. Find minimum value\n");
	printf("\t\t6. Delete all nodes\n");
	printf("\t\t7. Exit\n\n");

	printf("Choose option:");
	scanf("%d", &a);


	switch (a) {

		case 1 : 
		    insert_node_head(&head);
		    display(head);
		    break ;
		case 2: 
		    insert_node_tail(&head);
		    display(head);
		    break ;
		case 3: 
		    delete_node(&head);
		    display(head);
		    break ;
		case 4: 
		    find_max(head);
		    break ;
		case 5 :
		    find_min(head);
		    break ;
		case 6 :
		    delete_all_nodes(&head);
		    break ;
		case 7 : 
		    printf("Thanks for using the program\n\n");
		    break ;
		default :
		    printf("Wrong choice\n");


	}

	}while(a!=7);

	return 0 ;
}
