#include <iostream>
using namespace std;

struct Node {
	int value;
	Node *next;
};
Node *head = NULL;

void MainMenu() {
	cout << "\n==========Linked List==========\n";
	cout << "1. Append\n";
	cout << "2. Traverse\n";
	cout << "3. Insert\n";
	cout << "4. Delete\n";
	cout << "5. Destroy\n";
	cout << "6. Exit\n";
	cout << "Enter your choice: ";	
}

void appendNode(int val) {
	Node *n = new Node;
	n -> value = val;
	n -> next = NULL;
	//empty
	if (head == NULL) {
		head = n;
		return;
	}//not empty
	Node *cur = head;
	while (cur -> next != NULL) {
		cur = cur -> next;
	}
	cur -> next = n;
}

void traverseList() {
	if (head == NULL){
		cout << "The list is empty. \n";
		return;
	}
	Node *cur = head;
	while (cur != NULL){
		cout << "[" << cur -> value << "]"; 
		cur = cur -> next;
	}
}

void insertAt(int pos, int val){
	//empty
	if(head == NULL){
		Node *n = new Node;
		n -> value = val;
		n -> next = head;
		head = n;
		return;
	}
	//not empty
	Node *cur = head;
	int i = 1; //pos
	while(i < pos - 1 && cur -> next != NULL){
		cur = cur -> next;
		i++;
	}
	Node *n = new Node;
	n -> value = val;
	n -> next = cur -> next;
	cur -> next = n;
}

void deleteAt(int pos){
	if(head == NULL){
		cout << "The list is empty. \n";
		return;
	}
	if(pos <= 1){ //1st node
		Node *temp = head;
		head = head -> next;
		delete temp;
		return;
	}
	Node *cur = head;
	int i = 1; //pos
	while(i < pos - 1 && cur -> next != NULL){
		cur = cur -> next;
		i++;
	}
	Node *toDelete = cur -> next;
	cur -> next = toDelete -> next;
	delete toDelete;
}

void destroyList(){
	Node *cur = head;
	while(cur != NULL){
		Node *nextnode = cur -> next;
		delete cur;
		cur = nextnode;
	}
	head = NULL;
}

int main() {
	int choice;
	do {
		MainMenu();
		cin >> choice;
		if(choice == 1){
			int val;
			cout << "enter the number you want to append ";
			cin >> val;
			appendNode(val);
		}
		else if (choice == 2){
			cout << "Here are the contents of the list: ";
			traverseList();
		}
		else if (choice == 3){
			int pos, val;
			cout << "Insert position: ";
			cin >> pos;
			cout << "Enter value: ";
			cin >> val;
			insertAt(pos, val);
		}
		else if (choice == 4){
			int pos;
			cout << "Delete which position: ";
			cin >> pos;
			deleteAt(pos);
			cout << "Deleted";
		}
		else if (choice == 5){
			destroyList();
		}
		else if (choice == 6){
		}
		else {
			cout << "you entered an invalid choice \n";
		}
	} while (choice != 6);
		destroyList();
	return 0;
}
