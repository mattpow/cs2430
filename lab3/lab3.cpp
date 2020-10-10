// Matthew Powell
// lab3.cpp
// October 8, 2020
//
// Purpose: traverse a BST using preorder, inorder, and postorder methods
//
// Input: none
//
// Processing: construction of BST using random values between 1 and 100.
// Recursive traversal using each othe three specified methods
//
// Outputs: results of tree traversal methods

#include <iostream>

using namespace std;

struct TreeNode {
	int key;
	TreeNode* left;
	TreeNode* right;
};

void traverseInorder(TreeNode*& root);

void transversePreorder(TreeNode*& root);

void traversePostorder(TreeNode*& root);

void insert(TreeNode*& root, int value);

void deleteAll(TreeNode*& root);

void constructTree(TreeNode*& root);

TreeNode* root;

int main()
{
	constructTree(root);
	
	cout << endl << "Traversing the tree inorder:" << endl;
	traverseInorder(root);
	
	cout << endl << "Traversing the tree preorder:" << endl;
	transversePreorder(root);
	
	cout << endl << "Traversing the tree postorder:" << endl;
	traversePostorder(root);
	
	deleteAll(root);
	
	return 0;
}

void deleteAll(TreeNode*& root)
{
	if (root != nullptr) {
		deleteAll(root->left);
		deleteAll(root->right);
		delete root;
		root = nullptr;
	}
}

void traverseInorder(TreeNode*& root)
{
	if (root != nullptr) {
		traverseInorder(root->left);
		cout << root->key << endl;
		traverseInorder(root->right);
	}
}

void transversePreorder(TreeNode*& root)
{
	if (root != nullptr) {
		cout << root->key << endl;
		transversePreorder(root->left);
		transversePreorder(root->right);
	}
}

void traversePostorder(TreeNode*& root)
{
	if (root != nullptr) {
		traversePostorder(root->left);
		traversePostorder(root->right);
		cout << root->key << endl;
	}
}

void insert(TreeNode*& root, int value)
{
	if (root == nullptr) {
		root = new TreeNode;
		root->key = value;
		root->left = nullptr;
		root->right = nullptr;
	} else if (root->key < value) {
		insert(root->right, value);
	} else if (root->key > value) {
		insert(root->left, value);
	}
}

void constructTree(TreeNode*& root)
{
	for (int i = 0; i < 15; i++) {
		insert(root, rand() % 100 + 1);
	}
}