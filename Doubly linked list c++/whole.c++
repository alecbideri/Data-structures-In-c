#include<iostream>
using namespace std ;

class Node{
	
    public :
	int data ;
	Node* next ;
	Node * prev ;

	Node(int new_data) : data(new_data) , next(nullptr)  ,prev(nullptr) {}
};

void insert_node_tail(Node*&head , int new_data) {
	Node* new_node = new Node(new_data);

	if(head==nullptr) {
		head = new_node ;
	}else{
		Node* current = head ;
		while(current->next!=nullptr) {
			current = current->next ;
		}

		new_node->prev = current ;
		new_node->next = nullptr ;
		current->next = new_node ;
	}
}

void insert_node_head(Node*&head , int new_data) {
	Node* new_node = new Node(new_data) ;
	new_node->prev = nullptr;
    new_node->next = head ;

	if(head!=nullptr) {
		head->prev = new_node ;
	}

	head = new_node ;
}

void display(Node* head) {
	Node* current = head ;
	while(current!=nullptr) {
		cout<<current->data<<"->";
		current = current->next ;
	}

    cout<<"NULL"<<endl;
}

void delete_node(Node*&head){
	if(head==nullptr) {
		cout<<"Linked list is empty"<<endl;
		return ;
	}

	Node* current = head ;
	Node* prev = nullptr ;
	int key ;

	cout<<"Provide key delete"<<endl ;
	cin>>key ;

	if(current!=nullptr && current->data == key) {
		head = current->next ;
		if(head!=nullptr) {
			(head)->prev = nullptr;
		}
		delete current ;
		return ;
	} 

	while(current!=nullptr && current->data != key) {
		prev = current ;
		current = current->next ;
	}

	if(current==nullptr) {
		cout<<"No matching keys"<<endl ;
		return ;
	}

	if(current->prev!=nullptr) {
		current->prev->next = current->next ;
	}
	if(current->next !=nullptr) {
		current->next->prev = current->prev ;
	}

	delete current ;

}


void delete_all_node(Node*&head) {
	if(head=nullptr) {
		cout<<"Linked list is empty"<<endl ;
		return ;
	}

	Node* current = head ;
	while(current!=nullptr) {
		Node* next_node = current->next ;
		delete(current) ;
		current = next_node ;
	}
    head = nullptr;
	cout<<"All nodes are deleted"<<endl ;
}

int find_min(Node* head) {
    if(head==nullptr) {
        cout<<"lINKED LIST IS EMPTY"<<endl ;
        return -1 ;
    }

    Node* current = head ;
    int min = current->data ;
    while(current!=nullptr) {
        if(current->data < min) {
            min = current->data ;
        }
        current = current->next ;
    }
}

int find_max(Node* head) {
    if(head==nullptr) {
        cout<<"lINKED LIST IS EMPTY"<<endl ;
        return -1 ;
    }

    Node* current = head ;
    int max = current->data ;
    while(current!=nullptr) {
        if(current->data > max) {
            max = current->data ;
        }
        current = current->next ;
    }
}

int main() {
		
	Node* head = nullptr ;

	for(int i = 0 ; i<=7 ; i++) {
		insert_node_head(head , i);
	}

	display(head);

	return 0 ;
}