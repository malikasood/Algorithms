// C++ implementation to convert the given
// BST to Min Heap
#include <bits/stdc++.h>
using namespace std;
 
// structure of a node of BST
typedef struct Node
{
    int data;
    Node *left, *right;
}node;
 
/* Helper function that allocates a new node
   with the given data and NULL left and right
   pointers. */
node* getNode(int data)
{
    node *newNode = new node;
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}
 
// function prototype for preorder traversal
// of the given tree
void preorderTraversal(node*);
 
// function for the inorder traversal of the tree
// so as to store the node values in 'arr' in
// sorted order
void inorderTraversal(Node *root, vector<int>& arr)
{
    if (root == NULL)
        return;
 
    // first recur on left subtree
    inorderTraversal(root->left, arr);
 
    // then copy the data of the node
    arr.push_back(root->data);
 
    // now recur for right subtree
    inorderTraversal(root->right, arr);
}
 
// function to convert the given BST to MIN HEAP
// performs preorder traversal of the tree
void BSTToMinHeap(Node *root, vector<int> arr, int *i)
{
    if (root == NULL)
        return;
 
    // first copy data at index 'i' of 'arr' to
    // the node
    root->data = arr[++*i];
 
    // then recur on left subtree
    BSTToMinHeap(root->left, arr, i);
 
    // now recur on right subtree
    BSTToMinHeap(root->right, arr, i);
}
 
// utility function to convert the given BST to
// MIN HEAP
void convertToMinHeapUtil(Node *root)
{
    // vector to store the data of all the
    // nodes of the BST
    vector<int> arr;
    int i = -1;
 
    // inorder traversal to populate 'arr'
    inorderTraversal(root, arr);
 
    // BST to MIN HEAP conversion
    BSTToMinHeap(root, arr, &i);
}
 
// function for the preorder traversal of the tree
void preorderTraversal(Node *root)
{
    if (!root)
        return;
 
    cout << root->data << " ";
    preorderTraversal(root->left);
    preorderTraversal(root->right);
}
 
// Driver program
int main()
{
    // BST formation
    struct Node *root = getNode(8);
    root->left = getNode(2);
    root->right = getNode(9);
    root->left->left = getNode(1);
    root->left->right = getNode(5);
    root->right->left = getNode(6);
    root->right->right = getNode(7);
 
    convertToMinHeapUtil(root);
    cout << "Preorder Traversal:" << endl;
    preorderTraversal(root);
 
    return 0;
}