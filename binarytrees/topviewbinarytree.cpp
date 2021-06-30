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

//better approach
vector<vector<int> > verticalOrderTraversal(TreeNode* A)
{
	map<int, vector<int>> mp;

	int hd = 0;
	//vertical(A, hd, mp);

	vector<vector<int>> v;

	if (!A)
		return vector<vector<int>>();

	queue<pair<TreeNode*, int> > que;
	que.push(make_pair(A, hd));

	while (!que.empty())
	{
		pair<TreeNode *, int> temp = que.front();
		que.pop();
		hd = temp.second;
		TreeNode* node = temp.first;

		mp[hd].push_back(node->val);

		if (node->left)
			que.push(make_pair(node->left, hd - 1));
		if (node->right)
			que.push(make_pair(node->right, hd + 1));
	}

	for (auto it : mp)
	{
		v.push_back(it.second);
	}

	return v;
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







