#include<iostream>
#include<queue>
#include "binarytreenode.h"
using namespace std;

binarytreenode<int>* takeinputlevelwise() {
	int rootdata;
	cin >> rootdata;
	if (rootdata == -1)
	{
		return NULL;
	}
	binarytreenode<int>* root = new binarytreenode<int>(rootdata);
	queue<binarytreenode<int>*> pendingnodes;
	pendingnodes.push(root);
	while (pendingnodes.size() != 0) {
		binarytreenode<int>* front = pendingnodes.front();
		pendingnodes.pop();
		int leftchilddata;
		cin >> leftchilddata;
		if (leftchilddata != -1)
		{
			binarytreenode<int>* child = new binarytreenode<int>(leftchilddata);
			front->left = child;
			pendingnodes.push(child);
		}
		int rightchilddata;
		cin >> rightchilddata;
		if (rightchilddata != -1)
		{
			binarytreenode<int>* child = new binarytreenode<int>(rightchilddata);
			front->right = child;
			pendingnodes.push(child);
		}
	}
	return root;
}

void printLevelOrder(binarytreenode<int> *root)
{
	// Base Case
	if (root == NULL) return;

	// Create an empty queue for level order traversal
	queue<binarytreenode<int>*> q;

	// Enqueue Root and initialize height
	q.push(root);

	while (q.empty() == false)
	{
		// Print front of queue and remove it from queue
		binarytreenode<int> *node = q.front();
		cout << node->data << " ";

		q.pop();


		/* Enqueue left child */
		if (node->left != NULL)
			q.push(node->left);

		/*Enqueue right child */
		if (node->right != NULL)
			q.push(node->right);
	}
}

bool findnode(binarytreenode<int>* root, int value) {
	if (root == NULL)
	{
		return false;
	}
	if (root->data == value)
	{
		return true;
	}
	return findnode(root->left, value) || findnode(root->right, value);
}

int height(binarytreenode<int>* root) {
	if (root == NULL)
	{
		return 0;
	} else
	{
		return 1 + max(height(root->left), height(root->right));
	}
}

void mirror(binarytreenode<int>* root) {
	if (root == NULL)
	{
		return;
	}
	binarytreenode<int>* l = root->left;
	binarytreenode<int>* r = root->right;
	root->left = r;
	root->right = l;
	mirror(root->left);
	mirror(root->right);
}



void printtree(binarytreenode<int>* root) {
	//we write a base case in this unlike genetric tree
	if (root == NULL)
	{
		return;
	}
	cout << root->data << ":";
	if (root->left != NULL)
	{
		cout << "L" << root->left->data;
	}
	if (root->right != NULL)
	{
		cout << "R" << root->right->data;
	}
	cout << endl;
	printtree(root->left);
	printtree(root->right);
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	// binarytreenode<int>* root = new binarytreenode<int>(1);
	// binarytreenode<int>* node1 = new binarytreenode<int>(2);
	// binarytreenode<int>* node2 = new binarytreenode<int>(3);
	// root->left = node1;
	// root->right = node2;
	binarytreenode<int>* root = takeinputlevelwise();
	printLevelOrder(root);
	cout << endl;
	cout << findnode(root, 8);
	cout << endl;
	cout << height(root);
	mirror(root);
	cout << endl;
	printLevelOrder(root);

	delete root;

}


