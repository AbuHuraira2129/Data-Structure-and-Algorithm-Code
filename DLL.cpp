// Doubly Link List
// -------------------------
// 1. Insert at Beginning
// 2. Insert at End
// 3. Insert in Middle
// 4. Delete at Beginning
// 5. Delete at End
// 6. Searching
// 7. Value Updating
// 8. Simple Display
// 9. Reverse Display

#include<iostream>
#include<string>
using namespace std;

struct node{
	int data;
	node* next;
	node* prev;
};

node* head = NULL;
node* current = NULL;
node* tail = NULL;

// Insert at begining

void insertBeg(int item){
	node* newnode = new node;
	newnode->data = item;
	newnode->next = head;
	newnode->prev = NULL;
	
	if(head!=NULL){
		head->prev = newnode;
	}
	
	head = newnode;
	
	if (tail == NULL)
    {
        tail = newnode;
    }
}

// Insert at End

void insertEnd(int item) {
    node* newnode = new node;
    newnode->data = item;
    newnode->next = NULL;
    newnode->prev = NULL;

    if (head == NULL) {
        head = newnode;
        tail = newnode;
    } else {
        current = head;
        while (current->next != NULL) {
            current = current->next;
        }

        current->next = newnode;
        newnode->prev = current;
        tail = newnode;
    }
}

// Insert in midddle

void insertMiddle(int item) {
    node* newnode = new node;
    newnode->data = item;
    newnode->next = NULL;
    newnode->prev = NULL;

    if (head == NULL) {
        head = newnode;
        tail = newnode;
        return;
    }

    int mid;
    int c = 0;
    current = head;

    while (current != NULL) {
        current = current->next;
        c++;
    }

    mid = c / 2;

    current = head;

    for (int i = 1; i < mid; i++) {
        current = current->next;
    }

    newnode->next = current->next;
    newnode->prev = current;
    if (current->next != NULL) {
        current->next->prev = newnode;
    }
    current->next = newnode;

    if (newnode->next == NULL) {
        tail = newnode;
    }
}

// Delete at begining

void deleteBeg() {
    if (head == NULL) {
        
        cout << "List is Empty! Can't Delete!" << endl;
    }

    node* temp = head;

    if (head->next != NULL) {
        head->next->prev = NULL;
    }

    head = head->next;

    delete temp;
}

// Delete at end

void deleteEnd() {
    if (head == NULL) {
        cout << "List is Empty! Can't Delete!" << endl;
    }

    if (head->next == NULL) {
        delete head;
        head = tail = NULL;
        return;
    }

    node* temp = tail->prev;
    
    tail = temp;
    temp->next = NULL;
    
    delete current;
}

// Value Updating

void valueUpdate(int item, int newValue)
{
	current = head;
	bool updated = false;

	while (current != NULL)
	{
		if (current->data == item)
		{
			current->data = newValue;
			updated = true;
			break;
		}
		else
		{
			current = current->next;
		}
	}

	if (updated)
	{
		cout << "Value Updated!" << endl;
	}
	else
	{
		cout << "Value not found to be updated!" << endl;
	}
}

// Simple display

void display(){
	current = head;
	if(current==NULL){
		cout << "List is Empty!" << endl;
	}
	else{
		while(current!=NULL){
			cout << current->data << "->";
			current = current->next;
		}
	}
	cout << endl;
}

// Reverse display

void reverseDisplay(){
	if(head==NULL){
		cout << "List is Empty!" << endl;
	}
	else{
		current = tail;
		while(current!=NULL){
			cout << current->data << "<-";
			current = current->prev;
		}
	}
	
	cout << endl;
}

// Searching

void search(int item){
	current = head;
	bool found = false;
	while(current!=NULL){
		if(item == current->data){
			found = true;
			break;
		}else{
			current = current->next;
		}
	}
	
	if(found){
		cout << "Value Founded!" << endl;
	}else{
		cout << "Value not found!" << endl;
	}
}

// Main Function

int main(){
	insertBeg(1);
	insertBeg(2);
	insertBeg(3);
	insertBeg(4);
	insertBeg(5);
	insertEnd(7);
	insertMiddle(8);
	display();
	
	deleteBeg();
	deleteEnd();
	
	display();
	reverseDisplay();
	
	cout << endl;
	search(9);
}





