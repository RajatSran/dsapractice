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

int N, M;
bool vis[1001][1001];

bool isValid(int x, int y) {
	if (x < 1 || x > N || y < 1 || y > M)
		return false;
	if (vis[x][y])
		return false;
	return true;
}

int dx[] = { -1, 0, 1, 0};
int dy[] = { 0, 1, 0, -1};
void dfs1(int x, int y) {
	vis[x][y] = 1;
	cout << x << " " << y << endl;
	for (int i = 0; i < 4; i++)
		if (isValid(x + dx[i], y + dy[i]))
			dfs1(x + dx[i], y + dy[i]);
}

void dfs(int x, int y) {
	vis[x][y] = 1;
	cout << x << " " << y << endl;
	if (isValid(x - 1, y))
		dfs(x - 1, y);
	if (isValid(x, y - 1))
		dfs(x, y - 1);
	if (isValid(x + 1, y))
		dfs(x + 1, y);
	if (isValid(x, y + 1))
		dfs(x, y + 1);
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
	dfs(1, 1);
	return 0;
}