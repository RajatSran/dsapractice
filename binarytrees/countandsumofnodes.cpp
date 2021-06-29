#include<bits/stdc++.h>
using namespace std;

struct Node {
	int val;
	struct Node* left;
	struct Node* right;
	Node(int data) {
		val = data;
		left = NULL;
		right = NULL;
	}
};

int count(Node* root) {
	if (root == NULL)
		return 0;
	return count(root->left) + count(root->right) + 1;
}

int sum(Node* root) {
	if (root == NULL)
		return 0;
	return sum(root->left) + sum(root->right) + root->val;
}
int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	struct Node* root = new Node(1);
	root->left = new Node(2);
	root->right = new Node(3);
	root->left->left = new Node(4);
	root->left->right = new Node(5);
	root->right->left = new Node(6);
	root->right->right = new Node(7);
	cout << count(root) << endl;
	cout << sum(root) << endl;
	return 0;
}