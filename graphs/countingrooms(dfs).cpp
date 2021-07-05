#include<bits/stdc++.h>
using namespace std;


int arr[1001][1001];
bool vis[1001][1001];
int N, M;
int cnt = 0;
bool isValid(int x, int y) {
	if (x < 1 || x > N || y < 1 || y > M) {
		return false;
	}
	if (vis[x][y] || arr[x][y] == '#') {
		return false;
	}
	return true;
}

int dx[4] = {0, 0, -1, 1};
int dy[4] = { -1, 1, 0, 0};
void dfs(int x, int y) {
	vis[x][y] = true;
	for (int i = 0; i < 4; i++) {
		if (isValid(x + dx[i], y + dy[i])) {
			dfs(x + dx[i], y + dy[i]);
		}
	}
}


int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	cin >> N >> M;
	for (int i = 1; i <= N; ++i)
	{
		for (int j = 1; i <= M; ++j) {
			cin >> arr[i][j];
			vis[i][j] = false;
		}
	}

	for (int i = 1; i <= N; ++i)
	{
		for (int j = 1; i <= M; ++j) {
			if (arr[i][j] == '.' && vis[i][j] == false) {
				dfs(i, j), cnt++;
			}
		}
	}
	cout << cnt;
	return 0;
}

// #include <bits/stdc++.h>
// using namespace std;

// int neighborX[4] = {0, 0, 1, -1};
// int neighborY[4] = {1, -1, 0, 0};

// int n, m, answer = 0;
// int vis[1010][1010];
// char grid[1010][1010];

// bool isValid (int y, int x) {
// 	if (y < 0) return false;
// 	if (x < 0) return false;
// 	if (y >= n) return false;
// 	if (x >= m) return false;
// 	if (grid[y][x] == '#') return false;
// 	return true;
// }

// void DFS (int y, int x) {
// 	vis[y][x] = 1;
// 	for (int i = 0 ; i < 4 ; i++) {
// 		int newX = x + neighborX[i];
// 		int newY = y + neighborY[i];
// 		if (isValid(newY, newX)) {
// 			if (!vis[newY][newX]) {
// 				DFS(newY, newX);
// 			}
// 		}
// 	}
// }

// int main() {
// #ifndef ONLINE_JUDGE
// 	freopen("input.txt", "r", stdin);
// 	freopen("output.txt", "w", stdout);
// #endif
// 	cin >> n >> m;
// 	for (int i = 0 ; i < n ; i++) {
// 		for (int j = 0 ; j < m ; j++) {
// 			cin >> grid[i][j];
// 			vis[i][j] = 0;
// 		}
// 	}
// 	for (int i = 0 ; i < n ; i++) {
// 		for (int j = 0 ; j < m ; j++) {
// 			if (grid[i][j] == '.' && !vis[i][j]) {
// 				DFS(i, j);
// 				answer++;
// 			}
// 		}
// 	}
// 	cout << answer << endl;
// 	return 0;
// }






