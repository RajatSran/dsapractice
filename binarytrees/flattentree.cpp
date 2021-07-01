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

void flatten(Node* root) {
	if (root == NULL || (root->left == NULL && root->right == NULL)) {
		return;
	}
	if (root->left != NULL) {
		flatten(root->left);
		Node* temp = root->right;
		root->right = root->left;
		root->left = NULL;

		Node* tail = root->right;
		while (tail->right != NULL) {
			tail = tail->right;
		}
		tail->right = temp;
	}
	flatten(root->right);

}

void preorder(Node* root) {
	if (root == NULL)
		return;
	cout << root->val << " ";
	preorder(root->left);
	preorder(root->right);
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	struct Node* root = new Node(1);
	root->left = new Node(2);
	root->right = new Node(3);
	root->right->left = new Node(4);
	flatten(root);
	preorder(root);
	return 0;
}