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
int arr[1001][1001];
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
	/*
				1
			  /	  \
		   	2		3
		  /  \	  /   \
		4	  5  6		7
	   /
	  8
	*/
	cin >> N >> M;
	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= M; j++)
			cin >> arr[i][j];

	dfs(1, 1);
	return 0;
}