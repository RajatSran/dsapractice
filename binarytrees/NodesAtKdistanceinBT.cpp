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
//Case 1
void printSubtreeNodes(Node* root, int k) {
	if (root == NULL || k < 0) return;

	if (k == 0) {
		cout << root->val << " ";
		return;
	}
	printSubtreeNodes(root->left, k - 1);
	printSubtreeNodes(root->right, k - 1);
}

//Case 2 ---> int type as we want to return distance to it's ancesters
int printNodesAtK(Node *root, Node *target, int k) {
	if (root == NULL)
		return -1;
	if (root == target) {
		printSubtreeNodes(root, k);
		return 0;
	}

	int dl = printNodesAtK(root->left, target, k);
	if (dl != -1) {
		if (dl + 1 == k) {
			cout << root->val << " ";
		} else {
			printSubtreeNodes(root->right, k - dl - 2); //-2 as we are taking additional dis 2
		}
		return 1 + dl;
	}

	int dr = printNodesAtK(root->right, target, k);
	if (dr != -1) {
		if (dr + 1 == k) {
			cout << root->val << " ";
		} else {
			printSubtreeNodes(root->left, k - dr - 2); //-2 as we are taking additional dis 2
		}
		return 1 + dr;
	}

	return -1;
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
	printNodesAtK(root, root->left, 2);
	return 0;
}