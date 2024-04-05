#include<iostream>
using namespace std ;

class Node {
    public :
	int data ;
	Node* next ;

	Node(int new_data) : data(new_data) , next(nullptr) {} 
};

void insert_node_tail(Node*& head) {
    for(int i = 0; i <= 7; i++) {
        Node* new_node = new Node(i);

        if(head == nullptr) {
            head = new_node;
        } else {
            Node* current = head;
            while(current->next != nullptr) {
                current = current->next;
            }
            current->next = new_node;
        }
    }
}

void insert_node_head(Node*& head) {
	for(int i = 0 ; i<=7 ;i++) {
	Node* new_node = new Node(i);

	if(head==nullptr) {
		head=new_node;
	}else{
		new_node->next = head ;
		head = new_node ;
	}
  }
}

void delete_node(Node*&head) {
	if(head==nullptr) {
		cout<<"List is empty"<<endl ;
	}

	Node* current = head ;
	Node* prev = nullptr ;
	int key ;

	cout<<"Provide key to delete:";
	cin>>key ;

	if(current!=nullptr && current->data == key) {

		head = current->next ;
		delete current ;
		return ;
	}

	while(current!=nullptr && current->data != key) {
		prev = current ;
		current = current->next ;
	}

	if(current==nullptr) {
		cout<<"key not found"<<endl;
		return ;
	}

	prev->next = current->next ;
	delete current ;
}

void delete_all_node(Node*& head) {
    if(head == nullptr){
        cout << "List is empty" << endl;
        return;
    }

    Node* current = head;
    while(current != nullptr) {
        Node* nextNode = current->next;
        delete current;
        current = nextNode;
    }

    head = nullptr; // Reset head
    cout << "All nodes are deleted" << endl;
}

int find_min(Node*&head) {
	if(head==nullptr) {
		cout<<"list is empty";
		return -1 ;
	}

	Node* current = head->next ;
	int min_val = head->data ;

	while(current!=nullptr) {
		if(current->data < min_val) {
			min_val = current->data ;
		}

		current = current->next ;
	}

	cout<<"The minimum value is :" <<min_val<<endl;

	return min_val ;
}

int find_max(Node*&head) {
	if(head==nullptr) {
		cout<<"list is empty";
		return -1 ;
	}

	Node* current = head->next ;
	int max_val = head->data ;

	while(current!=nullptr) {
		if(current->data > max_val) {
			max_val = current->data ;
		}

		current = current->next ;
	}

	cout<<"The maximum value is :" <<max_val<<endl;

	return max_val ;
}


void display(Node*& head) {
	Node*current = head ;

	while(current!=nullptr) {
		cout<<current->data<<"->";
		current = current->next ;
	}

	cout<<"NULL" <<endl ;
}


int main() {
	
	Node* head = nullptr ;
	int a ;

	do{
    cout << "\n\t\tSingly linked list\n";
    cout << "\t\t______________________\n";
    cout << "\t\t1.Insert Node at head\n";
    cout << "\t\t2.Insert Node at tail\n";
    cout << "\t\t3.Delete Node\n";
    cout << "\t\t4.Find maximum value\n";
    cout << "\t\t5.Find minimum value\n";
    cout << "\t\t6.Delete all nodes\n";
    cout << "\t\t7.Exit\n\n";

    cout<<"Make a choice:";
    cin>>a;

    switch(a) {

    	case 1: 
    		insert_node_head(head);
    		display(head);
    		break ;
    	case 2 :
    		insert_node_tail(head);
    		display(head);
    		break ;
    	case 3:
    		delete_node(head);
            display(head);
    		break ;
    	case 4 : 
    		find_max(head);
    		break ;
    	case 5 :
    		find_min(head);
    		break ;
    	case 6: 
			delete_all_node(head);
			break ;
		case 7 : 
		    printf("Thanks for using the program\n\n");
		    break ;
    	default :
    		cout<<"Invalid choice"<<endl ;
    		break ;
    }

	}while(a!=7);

	return 0 ;
}