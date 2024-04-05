#include<iostream>
using namespace std ;

class Node{
	
	public:

	int data ;
	Node* next ;
	Node* prev ;

	Node(int new_data) : data(new_data) , next(nullptr)  , prev(nullptr) {}	
};

void insert_tail(Node*&head , int new_data) {
	Node* new_node = new Node(new_data);

	new_node->data = new_data ;
	new_node->next = nullptr ;

	if(head==nullptr){
		new_node->prev = nullptr;
		head = new_node ;
	}else{
		Node* current = head ;

		while(current->next!=nullptr) {
			current = current ->next ;
		}

		current ->next = new_node ;
		new_node->prev = current ;
	}
}

void insert_node_head(Node *& head , int new_data) {
	Node* new_node = new Node(new_data);

	new_node->data = new_data ;
	new_node->prev = nullptr ;
	new_node->next = head;

	if(head!=nullptr) {
		new_node->prev = new_node ;
	} 

	head = new_node ;
}

void display(Node*&head) {
	Node* current = head ;
	while(current!=nullptr) {
		cout<<current->data<<"->";
		current = current->next ;
	}

	cout<<"NULL"<<endl ;
}

int main() {
	
	Node* head = nullptr;

	for(int i = 0 ; i<=7 ; i++) {
		insert_node_head(head ,i);
	}

	display(head);

	return 0 ;
}