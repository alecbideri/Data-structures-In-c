#include<iostream>
using namespace std;

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
void delete_node(Node*& head , int key) {
    Node* current = head;
    Node* prev = nullptr;

    // If head node itself holds the key
    if(current != nullptr && current->data == key) {
        head = current->next;
        delete current;
        return;
    }

    // Search for the key to be deleted
    while(current != nullptr && current->data != key) {
        prev = current;
        current = current->next;
    }

    // If key was not present in linked list
    if(current == nullptr) {
        cout << "key not found" << endl;
        return;
    }

    // Unlink the node from linked list
    prev->next = current->next;

    // Free memory
    delete current;
}

void display(Node* head) {
    Node* current = head ;
    while(current!=nullptr) {
        cout<<current->data<<"->";
        current = current->next ;
    }
    cout<<"NULL"<<endl;
}

int main() {
    Node* head = nullptr ;  
    for(int i = 0 ; i<=7 ; i++) {
        insert_node_head(head , i);
    }
    display(head);
    delete_node(head , 3);
    display(head);

    return 0 ;
}