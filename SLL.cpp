// Singly Link List

#include<iostream>
#include<string>
using namespace std;

struct node{
	int data;
	node* link;
};

node* head = NULL;
node* current = NULL;

void insertBeg(int item){
	node* newnode = new node;
	newnode->data = item;
	newnode->link = head;
	head = newnode;
}

void insertMiddle(int item){
	
	node* newnode = new node;
	newnode->data = item;
	newnode->link = NULL;
	int mid;
	int c = 0;
	current = head;
	while(current!=NULL){
		current = current->link;
		c++;
	}
	
	mid = c/2;
	
	current = head;
	
	for(int i=1; i < mid; i++){
		current = current->link;
	}
	
	node* add;
	add = current->link;
	current->link = newnode;
	newnode->link = add;
	
}

void insertEnd(int item){
	
	node* newnode = new node;
	newnode->data = item;
	newnode->link = NULL;
	
	if(head==NULL){
		head = newnode;
	}
	else{
		current = head;
		while(current->link!=NULL){
			current = current->link;
		}
		current->link = newnode;
	}
}

void deleteBeg(){
	if(head==NULL){
		cout << "List is Empty!" << endl;
	}
	else{
		node *temp;
		temp = head;
		head = head->link;
		delete temp;
	}	
}

void deleteEnd(){

	if(head==NULL){
		cout << "List is Empty!" << endl;
	}
	else{
		node* temp;	
		current = head;
		while(current->link!=NULL){
			temp = current;
			current = current->link;
		}
		temp->link = NULL;
		delete current;
	}
	

}

void search(int item) {
    current = head;
    bool found = false; 

    while (current != NULL) {
        if (current->data == item) {
            found = true;
            break;
        } else {
            current = current->link;
        }
    }

    if (found) {
        cout << "Value Found!" << endl;
    } else {
        cout << "Value not Found!" << endl;
    }
}

void display(){
	
	current = head;
	while(current!=NULL){
		cout << current->data << "->";
		current = current->link;
	}
	
	cout << endl;
}

int main(){
	insertBeg(1);
	insertBeg(2);
	insertBeg(3);
	insertBeg(4);
	insertBeg(5);
	insertEnd(6);
	insertMiddle(7);
	display();
	
	deleteBeg();
	deleteEnd();
	display();
	
	search(1);
}
