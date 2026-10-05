#include <iostream>
using namespace std;
 
struct Node{
    int data;
    Node *next;
};
Node *front = NULL;
Node *rear = NULL;
 
 void QueueMenu() {
	cout << "\n==========Customer Queue Menu==========\n";
	cout << "1. New Customer\n";
	cout << "2. Serve Customer\n";
	cout << "3. View the next Customer that will be served\n";
	cout << "4. Display all Customer\n";
	cout << "5. Exit\n";
	cout << "Enter your choice: ";	
}
 
bool isEmpty(){
    if (front == NULL){
        return true;
    } 
				else {
        return false;
    }
}
void enqueue(int value){
    Node *newNode = new Node;
    newNode -> data = value;
    newNode -> next = NULL;
 
    if (front == NULL && rear == NULL){
        front = rear = newNode;
    } else {
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
 
void next(){
    if (isEmpty()){
        cout << "Queue is empty\n";
    }
    else {
        Node *current = front;
        cout << "Queue: ";
        cout << current -> data << " ";
    }
}
 
void display(){
    if (isEmpty()){
        cout << "Queue is empty\n";
    }
    else {
        Node *current = front;
        cout << "Queue: ";
        while (current != NULL){
            cout << current -> data << " ";
            current = current -> next;
        }
        cout << "\n";
    }
}
int main() {
    
    int choice;
	do {
		QueueMenu();
		cin >> choice;
		if(choice == 1){
			int value;
			cout << "Enter a value: ";
			cin >> value;
			enqueue(value);
		}
		else if (choice == 2){
			dequeue();
		}
		else if (choice == 3){
			next();
		}
		else if (choice == 4){
			display();
		}
	} while (choice != 5);
    
    return 0;
}
