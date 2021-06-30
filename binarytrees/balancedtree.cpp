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

bool flag = true;
int balancedtree(Node* root) {
	if (root == NULL)
		return	0;
	int l = balancedtree(root->left);
	int r = balancedtree(root->right);
	if (abs(l - r) > 1)
		flag = false;
	return max(l, r) + 1;
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
	balancedtree(root);
	if (flag)
		cout << "tree is balanced";
	else
		cout << "tree is not balanced";
	return 0;
}