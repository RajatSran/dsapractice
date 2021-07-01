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

bool getpath(Node *root, int key, vector<int> &path) {
	if (root == NULL)
		return false;

	path.push_back(root->val);
	if (root->val == key)
		return true;

	if (getpath(root->left, key, path) || getpath(root->right, key, path))
		return true;

	path.pop_back();
	return false;
}

int lca(Node* root, int n1, int n2) {
	vector<int> path1, path2; //root to nodes
	if (!getpath(root, n1, path1) || !getpath(root, n2, path2)) {
		return -1;
	}

	int pc;//path change
	for (pc = 0; pc < path1.size() && pc < path2.size(); pc++) {
		if (path1[pc] != path2[pc])
			break;
	}
	return path1[pc - 1];
}

Node* lca2(Node* root, int n1, int n2) {
	if (root == NULL)
		return NULL;
	if (root->val == n1 || root->val == n2)
		return root;
	Node* leftlca = lca2(root->left, n1, n2);
	Node* rightlca = lca2(root->right, n1, n2);
	if (leftlca && rightlca) {
		return root;
	}
	if (leftlca != NULL) {
		return leftlca;
	}
	return rightlca;

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
	cout << lca2(root, 6, 7)->val;
	return 0;
}