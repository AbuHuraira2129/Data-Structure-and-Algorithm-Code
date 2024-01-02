// Tree - Binary Search Tree
// Insertion in BST
// Searching in BST
// InOrder Display in BST
// PreOrder Display in BST
// PostOrder Display in BST

#include<iostream>
#include<string>
using namespace std;

struct node{
    int data;
    node* left;
    node* right;
};

// Insertion in BST
node* insertion(node* root, int item){
    if (!root){
        node* newnode = new node;
        newnode->data = item;
        newnode->left = NULL;
        newnode->right = NULL;
        return newnode;
    }

    if (item < root->data){
        root->left = insertion(root->left, item);
    }
    else{
        root->right = insertion(root->right, item);
    }

    return root;
}

// Searching in BST
bool search(node *root, int data){
	if(root == NULL){
		return false;
	}
	if(root->data == data){
		return true;
	}
	else if(root->data > data){
		return search(root->left, data); 
	}
	else{
		return search(root->right, data);
	}
}

// InOrder Display in BST
void InorderDisplay(node* root) {
    if (root != NULL) {
        InorderDisplay(root->left);
        cout << root->data << "->";
        InorderDisplay(root->right);
    }
}

// PreOrder Display in BST
void preOrderDisplay(node* root) {
    if (root != NULL) {
        cout << root->data << "->";
        preOrderDisplay(root->left);
        preOrderDisplay(root->right);
    }
}

// PostOrder Display in BST
void postOrderDisplay(node* root) {
    if (root != NULL) {
        postOrderDisplay(root->left);
        postOrderDisplay(root->right);
        cout << root->data << "->";
    }
}

// Main function
int main() {
	node *root = NULL;
	root = insertion(root ,2);
	insertion(root , 5);
    insertion(root , 1);

    cout << "In Order Display" << endl;
    InorderDisplay(root);
    cout << endl;
    cout << "Pre Order Display" << endl;
    preOrderDisplay(root);
    cout << endl;
    cout << "Post Order Display" << endl;
    postOrderDisplay(root);
    cout << endl;
    cout << endl;

	bool found = search(root, 3);
	
	if(found){
		cout << "Value Found!";
	}
	else{
		cout << "Value Not Found!";
	}

    cout << endl;

}