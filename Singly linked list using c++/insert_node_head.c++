#include<iostream>
using namespace std ;

class Node{
    public:
    int data ;
    Node* next ;

    Node(int new_data) : data(new_data) , next (nullptr) {}
};

void insert_node_head(Node*&head , int new_data) {
    Node* new_node = new Node( new_data) ;

    if(head==nullptr) {
        head=new_node;
    }else{
        new_node->next = head ;
           head = new_node ;
    }
}

int find_min(Node* head) {
    if(head==nullptr) {
        cout<<"lIST IS EMPTY"<<endl;
        return -1 ;
    }

    int min_val = head->data ;
    Node* current = head ;
    while(current!=nullptr) {
        if(current->data < min_val) {
            min_val = current->data ;
        }
        current = current->next ;
    }

    cout<<"MINIMUM VALUE IS : "<<min_val<<endl;
    return min_val ;
}

int find_max(Node* head) {
	if(head==nullptr) {
		cout<<"the list is empty\n";
	}

	int max_val = head->data ;
	Node* current = head->next ;

	while(current!=NULL) {
		if(current->data > max_val) {
		 	max_val = current->data ;
		}

		current = current->next; 
	}

	cout<<"Maximum value is:" <<max_val<<endl;

	return max_val ;
}

void display(Node* head) {
    Node* current = head ;
    while(current!=nullptr) {
        cout<<current->data<<"->";
        current = current->next ;
    }
    cout<<"NULL"<<endl;
}

int WinMain() {
    Node* head = nullptr ;  
    for(int i = 0 ; i<=7 ; i++) {
        insert_node_head(head , i);
    }
    display(head);
    find_min(head);  
    find_max(head); 

    return 0 ;
}