#include <iostream>
using namespace std;
 
struct Node{
    int data;
    Node *next;
};
Node *front = NULL;
Node *rear = NULL;
 
bool isEmpty(){
    if (front==NULL){
        return true;
    } else{
        return false;
    }
}
void enqueue(int value){
    Node *newNode = new Node;
    newNode -> data = value;
    newNode -> next = NULL;
 
    if (front == NULL && rear == NULL){
        front = rear = newNode;
    }else{
        rear -> next = newNode;
        rear = newNode;
    }
    cout << value << " enqueued.\n";
}
 
void dequeue(){
    if (isEmpty()){
        cout << "Queue is empty!\n";
        return;
    }
    Node *temp = front;
    cout << temp -> data << " dequeued.\n";
    front = front -> next;
    if (front == NULL){
        rear = NULL;
    }
    delete temp;
}
 
void display(){
    if (isEmpty()){
        cout << "Queue is empty\n";
    }
    else {
        Node *current = front;
        cout << "Queue: ";
        while (current != NULL){
            cout << current->data << " ";
            current = current->next;
        }
        cout << "\n";
    }
}
int main() {
    enqueue(5);
    enqueue(7);
    enqueue(9);
    display();
    dequeue();
    display();
    dequeue();
    display();
    dequeue();
    display();
    return 0;
}
