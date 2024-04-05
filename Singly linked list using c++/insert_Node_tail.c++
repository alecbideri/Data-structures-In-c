#include<iostream>
using namespace std;
class Node{
    public:
    int data ;
    Node* next ;

    Node(int new_data) : data(new_data) , next(nullptr) {}
};

void insert_node_tail(Node*& head , int new_data) {
    Node* new_node = new Node(new_data);

    if(head==nullptr) {
        head=new_node;
    }else{
        Node* current= head;
        while(current->next!=nullptr) {
            current = current->next ;
        }
        current->next = new_node ;
    }
}

void display(Node* head){
    Node* current = head ; 
    while(current!=NULL) {
        cout<<current->data<<"->";
        current = current->next ;
    }

    cout<<"NULL"<<endl;
}

int WinMain() {

    Node* head = nullptr ;
    for(int i = 0 ; i<=7 ; i++) {
        insert_node_tail(head , i);
    }

    display(head);

    return 0 ;
}