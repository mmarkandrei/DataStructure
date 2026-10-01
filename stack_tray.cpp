#include <iostream>
using namespace std;

struct Node {
    int data;
    Node *next;
};
Node *top = NULL;

bool isEmpty(){
    if(top == NULL){
        return true;
    } else {
        return false;
    }
}

void push(int value){
    Node *newNode = new Node;
    newNode -> data = value;
    newNode -> next = top;
    top = newNode;
    cout << value << " push onto the stack.\n";
}

void pop(){
    if (isEmpty()){
        cout << "The Tray is empty. \n";
    } else{
        Node *temp = top;
        top = top -> next;
        delete temp;
    }
}

void check(){
	if (isEmpty()){
        cout << "Tray is empty\n";
    }
    else {
        cout << "next Tray: ";
        Node *current = top;
        cout << "["<< current -> data << "]";
        }
    }

void display (){
    if (isEmpty()){
        cout << "Tray is empty\n";
    }
    else {
        cout << "Tray available: ";
        Node *current = top;
        while (current != NULL){
            cout << "["<< current -> data << "]";
            current = current -> next;
        }
    }
}

int main() {
    int choice;
    int value;
    do {
        cout << "\n====TRAY====\n";
        cout << "1. Add Tray\n";
        cout << "2. Take Tray\n";
        cout << "3. Check what Tray is next\n";
        cout << "4. Check Tray\n";
        cout << "5. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;
        
        if (choice == 1){
            cout << "Enter a value to push: ";
            cin >> value;
            push(value);
        }
        else if (choice == 2){
            pop();
        }
        else if (choice == 3){
        	check();	
		}
        else if (choice == 4){
            display();
    	}
    }while (choice != 5);
   		
    return 0;
}
