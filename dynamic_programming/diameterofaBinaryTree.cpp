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

int diameter(Node* root, int& result) {
	//base condition
	if (root == NULL)	return 0;
	//hypothesis
	int l = diameter(root->left, result);
	int r = diameter(root->right, result);

	//induction
	int temp = max(l, r) + 1;//here when we are not considering root
	int ans = max(temp, l + r + 1);
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
	root->left->left = new Node(4);
	root->left->right = new Node(5);
	root->right->left = new Node(6);
	root->right->right = new Node(7);

	int result = INT_MIN;
	diameter(root, result);
	cout << result;
	return 0;

}