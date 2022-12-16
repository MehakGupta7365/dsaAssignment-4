#include <iostream>
#include <bits/stdc++.h>
using namespace std;
#include <queue>

class Node{
public:
  int data;
  Node *next;

  // Constructor for creating a node.
  Node(int data){// 1. Take an array of numbers.
// 2. Use it to construct a Binary Search Tree (BST).
// 3. Write separate functions to insert a node in BST.
// 4. Write separate functions to delete a node from BST.


// SID_19105098
template <typename T>
	class BinaryTreeNode {
    	public : 
    	T data;
    	BinaryTreeNode<T> *left;
    	BinaryTreeNode<T> *right;

    	BinaryTreeNode(T data) {
        	this -> data = data;
        	left = NULL;
        	right = NULL;
    	}
	};

BinaryTreeNode<int>* constructTree(int *input, int n) {
    if(n<=0){return NULL;}
    int m=((n-1)/2);
    BinaryTreeNode<int>*root=new BinaryTreeNode<int>(input[m]);
    root->left=constructTree(input, m);
    root->right=constructTree(input+m+1, n-1-m);
    return root;
}

BinaryTreeNode<int>* insertNode(BinaryTreeNode<int>* node, int key)
{
    BinaryTreeNode<int>* newNode = new BinaryTreeNode<int>(key);
    if (node == NULL)
        return newNode;
 
    if (key < node->data)
        node->left = insertNode(node->left, key);
    else
        node->right = insertNode(node->right, key);
 
    return node;
}
 
BinaryTreeNode<int>* minValueNode(BinaryTreeNode<int>* node)
{
    BinaryTreeNode<int>* current = node;

    while (current && current->left != NULL)
        current = current->left;
 
    return current;
}

BinaryTreeNode<int>* deleteNode(BinaryTreeNode<int>* root, int key)
{
    // base case
    if (root == NULL)
        return root;

    if (key < root->data)
        root->left = deleteNode(root->left, key);

    else if (key > root->data)
        root->right = deleteNode(root->right, key);
 
    else {
        if (root->left == NULL and root->right == NULL)
            return NULL;
 
        else if (root->left == NULL) {
            BinaryTreeNode<int>* temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL) {
            BinaryTreeNode<int>* temp = root->left;
            free(root);
            return temp;
        }
 
        BinaryTreeNode<int>* temp = minValueNode(root->right);
 
        root->data = temp->data;
 
        root->right = deleteNode(root->right, temp->data);
    }
    return root;
}
 
using namespace std;
int main() {
    int size;
    cin >> size;
    int* input = new int[size];
    // 1, 2, 3, 4, 6

    //assuming here that the array is sorted, else the following one line is added
    // sort(input, input+size);
    for (int i = 0; i < size; i++) cin >> input[i];

    BinaryTreeNode<int>* root = constructTree(input, size);
    BinaryTreeNode<int>* newNode = insertNode(root, 5);
    BinaryTreeNode<int>* deletingNode = deleteNode(root, 5);
    delete[] input;
}
    this->data = data;
    this->next = NULL;
  }
};

class LinkedList{
public:
  Node *head;
  
  // Linked List constructor // initialising head pointer
  LinkedList(Node *head){
    this->head = head;
  }
  
    /* The first function, insertAfterValue, takes a value and looks for the value in the linked list, and then inserts the new node after the node which contains this given value.
    */
  void insertAfterValue(int value, int data){
    Node *temp = head;

    // Temp pointing to value after which element is to be inserted
    while (temp != NULL && temp->data != value){
      temp = temp->next;
    }

    // Creating new node and inserting in the list
    Node *newnode = new Node(data);
    newnode->next = temp->next;
    temp->next = newnode;
  }
  
  
    /* The Second function insertAtIndex takes the number of nodes after which the insertion is to be made
    */
  void insertAtIndex(int index, int data){

    // Element to be inserted at zero index 
    // Update head of LL by pointing to new node
    if (index == 0){
      Node *newnode = new Node(data);
      newnode->next = head;
      head = newnode;
      return;
    }
    
    // initialising new node with head
    Node *temp = head;
    
    // For loop to travel to the point of insertion
    for (int i = 0; i < index - 1; i++){
      if (temp->next != NULL)
        temp = temp->next;
    }

    // Creating new node and inserting in the list
    Node *newNode = new Node(data);
    newNode->next = temp->next;
    temp->next = newNode;
  }

  void printList()
  {
    Node *temp = head;
    while (temp != NULL)
    {
      cout << temp->data << " ";
      temp = temp->next;
    }
    cout << endl;
  }
};


int main()

{
  // Dummy linked list
  Node *n1 = new Node(7);
  Node *n2 = new Node(1);
  Node *n3 = new Node(0);
  Node *n4 = new Node(2);

  n1->next = n2;
  n2->next = n3;
  n3->next = n4;

  LinkedList l(n1);

  cout << "Initial linked list : " << endl;
  l.printList();

  cout << endl;
  int input1;
  cout << "Enter value of node after which new element is to be inserted" << endl;
  cin >> input1;

  int input2;
  cout << "Enter data for new node: " << endl;
  cin >> input2;

  l.insertAfterValue(input1, input2);

  cout << endl;
  cout << "Updated linked list : " << endl;
  l.printList();
  cout << endl;

  int input3;
  cout << "Enter index at which element is to be inserted: " << endl;
  cin >> input3;

  int input4;
  cout << "Enter data for new node: " << endl;
  cin >> input4;

  l.insertAtIndex(input3, input4);

  cout << endl;
  cout << "Updated linked list : " << endl;
  l.printList();
}
