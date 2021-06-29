#include<bits/stdc++.h>
using namespace std;

struct Node {
	int data;
	struct Node* left;
	struct Node* right;
	Node(int val) {
		data = val;
		left = NULL;
		right = NULL;
	}
};



int search(int inorder[], int start, int end, int curr) {
	for (int i = start; i <= end; i++) {
		if (inorder[i] == curr)
			return i;
	}
	return -1;
}

Node* build(int preorder[], int inorder[], int start, int end, int &index) {
	if (start > end)
		return NULL;
	int curr = preorder[idx];
	idx--;
	Node* node = new Node(curr);
	if (start == end)
		return node;
	int pos = search(inorder, start, end, curr);
	node->right = build(preorder, inorder, pos + 1, end, index);
	node->left = build(preorder, inorder, start, pos - 1, index);
	return node;
}

void inorderPrint(Node* root) {
	if (root == NULL) return;
	inorderPrint(root->left);
	cout << root->data << " ";
	inorderPrint(root->right);
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int preorder[] = {1, 2, 4, 3, 5};
	int inorder[] = {4, 2, 1, 5, 3};
	int idx = 4;
	Node* root = build(preorder, inorder, 0, 4, idx);
	inorderPrint(root);
	return 0;
}