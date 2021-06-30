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

void topview(Node* root, map<int, vector<int>> &m, int hd) {
	if (root == NULL)
		return;
	m[hd].push_back(root->val);
	topview(root->left, m, hd - 1);
	topview(root->right, m, hd + 1);
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
	map<int, vector<int>> m;
	int hd = 0;
	topview(root, m, hd);

	for (auto x : m) {
		cout << x.second[0] << " ";
	}
	cout << endl;
}







