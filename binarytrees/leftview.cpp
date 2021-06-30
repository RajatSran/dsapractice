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

void rightview(Node* root, vector<int>& ans) {
	if (root == NULL)
		return;
	queue<Node*> q;
	q.push(root);
	while (!q.empty()) {
		int n = q.size();
		for (int i = 0; i < n; ++i)
		{
			Node* curr = q.front();
			q.pop();
			if (i == 0) {
				ans.push_back(curr->val);
			}
			if (curr->left != NULL)
				q.push(curr->left);
			if (curr->right != NULL)
				q.push(curr->right);
		}
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
	root->right->left = new Node(5);
	root->right->right = new Node(6);
	root->right->left->left = new Node(7);
	vector<int> ans;
	rightview(root, ans);
	for (auto x : ans) {
		cout << x << endl;
	}
}