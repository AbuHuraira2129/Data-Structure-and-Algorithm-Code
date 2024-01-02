// Singly Linked List
// -------------------------
// 1. Insert at Beginning
// 2. Insert in Middle
// 3. Insert at End
// 4. Delete at Beginning
// 5. Delete at End
// 6. Searching
// 7. Value Updating
// 8. Display

#include <iostream>
#include <string>
using namespace std;

struct node
{
	int data;
	node *link;
};

node *head = NULL;
node *current = NULL;

// 1. Insert at Beginning

void insertBeg(int item)
{
	node *newnode = new node;
	newnode->data = item;
	newnode->link = head;
	head = newnode;
}

// 2. Insert in Middle

void insertMiddle(int item)
{

	node *newnode = new node;
	newnode->data = item;
	newnode->link = NULL;
	int mid;
	int c = 0;
	current = head;
	while (current != NULL)
	{
		current = current->link;
		c++;
	}

	mid = c / 2;

	current = head;

	for (int i = 1; i < mid; i++)
	{
		current = current->link;
	}

	node *add;
	add = current->link;
	current->link = newnode;
	newnode->link = add;
}

// 3. Insert at End

void insertEnd(int item)
{

	node *newnode = new node;
	newnode->data = item;
	newnode->link = NULL;

	if (head == NULL)
	{
		head = newnode;
	}
	else
	{
		current = head;
		while (current->link != NULL)
		{
			current = current->link;
		}
		current->link = newnode;
	}
}

// 4. Delete at Beginning

void deleteBeg()
{
	if (head == NULL)
	{
		cout << "List is Empty!" << endl;
	}
	else
	{
		node *temp;
		temp = head;
		head = head->link;
		delete temp;
	}
}

// 5. Delete at End

void deleteEnd()
{

	if (head == NULL)
	{
		cout << "List is Empty!" << endl;
	}
	else
	{
		node *temp;
		current = head;
		while (current->link != NULL)
		{
			temp = current;
			current = current->link;
		}
		temp->link = NULL;
		delete current;
	}
}

// 6. Searching

void search(int item)
{
	current = head;
	bool found = false;

	while (current != NULL)
	{
		if (current->data == item)
		{
			found = true;
			break;
		}
		else
		{
			current = current->link;
		}
	}

	if (found)
	{
		cout << "Value Found!" << endl;
	}
	else
	{
		cout << "Value not Found!" << endl;
	}
}

// 7. Value Updating

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
			current = current->link;
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

// 8. Display

void display()
{
	if (head == NULL)
	{
		cout << "List is Empty!" << endl;
	}
	else
	{
		current = head;
		while (current != NULL)
		{
			cout << current->data << "->";
			current = current->link;
		}
	}

	cout << endl;
}

// Main Function

int main()
{
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
	valueUpdate(7, 8);
	display();
}
