#include<bits/stdc++.h>
using namespace std;

int N, M;
int arr[1001][1001];
bool vis[1001][1001];
bool isValid(int x, int y) {
	if (x < 1 || x > N || y < 1 || y > M) {
		return false;
	}
	if (vis[x][y] || arr[x][y] == '#') {
		return false;
	}
	return true;
}

int dx[] = { -1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};
void dfs(int x, int y) {
	vis[x][y] = true;
	for (int i = 0; i < 4; i++) {
		if (isValid(x + dx[i], y + dy[i]))
			dfs(x + dx[i], y + dy[i]);
	}
}



int main() {
	cin >> N >> M;
	for (int i = 1; i <= N; ++i)
	{
		for (int j = 1; i <= M; ++j)
			cin >> arr[i][j];
	}
	int cnt = 0;
	for (int i = 1; i <= N; ++i)
	{
		for (int j = 1; i <= M; ++j)
			if (arr[i][j] == '.' && vis[i][j] == false)
				dfs(i, j), cnt++;
	}
	cout << cnt;
}








