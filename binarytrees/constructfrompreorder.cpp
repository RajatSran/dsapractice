/*
construct from preorder and inorder

we can build a unique tree by using these two.
preorder -- root left right
inorder -- left root right

*/
#include<iostream>
#include<queue>
#include "binarytreenode.h"
using namespace std;

Node<int>* takeinputlevelwise() {
	int rootdata;
	cin >> rootdata;
	if (rootdata == -1)
	{
		return NULL;
	}
	Node<int>* root = new Node<int>(rootdata);
	queue<Node<int>*> pendingnodes;
	pendingnodes.push(root);
	while (pendingnodes.size() != 0) {
		Node<int>* front = pendingnodes.front();
		pendingnodes.pop();
		int leftchilddata;
		cin >> leftchilddata;
		if (leftchilddata != -1)
		{
			Node<int>* child = new Node<int>(leftchilddata);
			front->left = child;
			pendingnodes.push(child);
		}
		int rightchilddata;
		cin >> rightchilddata;
		if (rightchilddata != -1)
		{
			Node<int>* child = new Node<int>(rightchilddata);
			front->right = child;
			pendingnodes.push(child);
		}
	}
	return root;
}

void printLevelOrder(Node<int> *root)
{
	// Base Case
	if (root == NULL) return;

	// Create an empty queue for level order traversal
	queue<Node<int>*> q;

	// Enqueue Root and initialize height
	q.push(root);

	while (q.empty() == false)
	{
		// Print front of queue and remove it from queue
		Node<int> *node = q.front();
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

void inorder(Node<int>* root) {
	if (root == NULL)
	{
		return;
	}
	inorder(root->left);
	cout << root->data << " ";
	inorder(root->right);
}

void preorder(Node<int>* root) {
	if (root == NULL)
	{
		return;
	}
	cout << root->data << " ";
	preorder(root->left);
	preorder(root->right);
}

void postorder(Node<int>* root) {
	if (root == NULL)
	{
		return;
	}
	postorder(root->left);
	postorder(root->right);
	cout << root->data << " ";
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	Node<int>* root = takeinputlevelwise();
	printLevelOrder(root);
	cout << endl;
	inorder(root);
	cout << endl;
	preorder(root);
	cout << endl;
	postorder(root);


	delete root;

}


