#include<bits/stdc++.h>
using namespace std;

struct Node {
	int data;
	struct Node* left;
	struct Node* right;
	Node(int val) {
		data = val;
		left = NULL;
		right = NULL;
	}
};

void preorder(struct Node* root) {
	if (root == NULL)
		return;
	cout << root->data << " ";
	preorder(root->left);
	preorder(root->right);
}

void inorder(struct Node* root) {
	if (root == NULL)
		return;
	preorder(root->left);
	cout << root->data << " ";
	preorder(root->right);
}

void postorder(struct Node* root) {
	if (root == NULL)
		return;
	preorder(root->left);
	preorder(root->right);
	cout << root->data << " ";
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	struct Node* root = new Node(1);
	root->left = new Node(2);
	root->right = new Node(3);
	preorder(root);
	cout << endl;
	inorder(root);
	cout << endl;
	postorder(root);
}