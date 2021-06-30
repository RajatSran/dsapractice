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

vector<vector<int>> levelOrder(Node* root) {
	if (root == NULL)
		return {};
	vector<vector<int>> ans;
	queue<Node*> q;
	q.push(root);
	Node *temp;
	int len;
	while (!q.empty()) {
		len = q.size();// ?
		vector<int> v;
		for (int i = 0; i < len; i++) {
			temp = q.front();
			q.pop();
			v.push_back(temp->val);

			if (temp->left) q.push(temp->left);
			if (temp->right) q.push(temp->right);
		}
		ans.push_back(v);
	}
	return ans;
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
	vector<vector<int>> result = levelOrder(root);
	for (auto x : result) {
		for (int y : x) {
			cout << y << " ";
		}
		cout << endl;
	}
	return 0;
}