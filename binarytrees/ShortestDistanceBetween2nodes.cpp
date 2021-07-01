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


Node* LCA(Node* root, int n1, int n2) {
	if (root == NULL) {
		return NULL;
	}
	if (root->val == n1 || root->val == n2) {
		return root;
	}
	Node* l = LCA(root->left, n1, n2);
	Node* r = LCA(root->right, n1, n2);

	if (l && r) {
		return root;
	}
	if (l != NULL) {
		return l;
	}
	return r;
}

//find this distance in terms of level
int findDist(Node* root, int k, int dist) {
	if (root == NULL)
		return -1;
	if (root->val == k) {
		return dist;
	}
	int left = findDist(root->left, k, dist + 1);
	int right = findDist(root->right, k, dist + 1);

	if (left != -1)
		return left;
	return right;


}

int DistBtwTwoNodes(Node* root, int n1, int n2) {
	Node* lca = LCA(root, n1, n2);
	int d1 = findDist(lca, n1, 0);
	int d2 = findDist(lca, n2, 0);
	return d1 + d2;
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
	cout << DistBtwTwoNodes(root, 4, 7);
	return 0;
}