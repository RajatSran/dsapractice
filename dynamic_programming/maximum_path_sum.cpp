#include<bits/stdc++.h>
using namespace std;

struct Node {
	int val;
	struct Node* left;
	struct Node* right;
	Node(int data) {
		val = data;
		left = right = NULL;
	}
};

int maxpathsum(Node* root, int& result) {
	//base condition
	if (root == NULL)	return 0;
	//hypothesis
	int l = maxpathsum(root->left, result);
	int r = maxpathsum(root->right, result);

	//induction
	int temp = max(root->val, max(l, r) + root->val); //here when we are not considering root
	int ans = max(temp, l + r + root->val);
	//int ans = l+r+1 could be written directly
	result = max(result, ans);
	return temp;
}


int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	struct Node* root = new Node(1);
	root->left = new Node(2);
	root->right = new Node(3);
	root->left->left = new Node(-4);
	root->left->right = new Node(-5);
	root->right->left = new Node(6);
	root->right->right = new Node(7);

	int result = INT_MIN;
	maxpathsum(root, result);
	cout << result;
	return 0;
}