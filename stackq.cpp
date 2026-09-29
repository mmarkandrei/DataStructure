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
        cout << "The stack is empty. \n";
    } else{
        Node *temp = top;
        top = top -> next;
        delete temp;
    }
}

void display (){
    if (isEmpty()){
        cout << "Stack is empty\n";
    }
    else {
        cout << "Stack elements: ";
        Node *current = top;
        while (current != NULL){
            cout << current -> data << " ";
            current = current -> next;
        }
    }
}

int main() {
    int choice;
    int value;
    do {
        cout << "\n====STACK MENU====\n";
        cout << "1. Push\n";
        cout << "2. Pop\n";
        cout << "3. Check if Empty\n";
        cout << "4. Display Stack\n";
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
        else if (choice == 4){
            display();
        }
                
        
    }while (choice != 6);
    
    return 0;
}
