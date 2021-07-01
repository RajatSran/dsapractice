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

void diagonaltraversal(Node *root, int level, map<int, vector<int>> &m) {
	//root->left level=+1
	//root->right,root level=same;
	if (root == NULL) return;
	m[level].push_back(root->val);
	diagonaltraversal(root->right, level, m);
	diagonaltraversal(root->left, level + 1, m);
}

void printdiagonal(Node* root) {
	map<int, vector<int>> m;
	diagonaltraversal(root, 0, m);
	for (auto it : m) {
		for (auto x : it.second)
			cout << x << " ";
		cout << endl;
	}
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
	root->left->left->left = new Node(8);
	/*
				1
			  /	  \
		   	2		3
		  /  \	  /   \
		4	  5  6		7
	   /
	  8
	*/
	printdiagonal(root);
	return 0;
}