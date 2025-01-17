#include<iostream>
using namespace std;

//Node class represent the node in a Linked List
class Node{
    public:
        int data; //data stored
        Node* next; //pointer to the next node

        //construtor with both data and next node as a parameters
        Node(int data1, Node* next1){
            data = data1;
            next = next1;
        }
    //constructor with only data as a parameter, sets next to nullptr
        Node(int data1){
            data = data1;
            next = nullptr;
        }
};

Node* reverseLinkedList(Node* head){
    Node* temp = head;
    stack<int> st;
    while(temp!= nullptr){
        st.push(temp->data);
        temp = temp->next;
    }

    temp = head;
    while(temp!= nullptr) {
        temp-> data = st.top();
        st.pop();
        temp= temp->next;
    }
    return head;
}

//Function to print the linked list
void printLinkedList(Node* head){
    Node* temp = head;
    while(temp!=nullptr) {
        cout<<temp->data <<" ";
        temp = temp->next;
    }
    cout<< endl;
}
int main() {
    //create a linked list with values 1,2,3,4
Node* head = new Node(1);
head->next = new Node(3);
head->next->next = new Node(2);
head->next->next->next = new Node(4);

//print the original linked list
cout<<"original Linked List";
printLinkedList(head);

//reverse the linked list
head = reverseLinkedList(head);
//print linked list
cout<<"rEVERSED LINKED LIST:";
printLinkedList(head);
return 0;
}