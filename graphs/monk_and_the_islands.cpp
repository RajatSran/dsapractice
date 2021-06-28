#include<bits/stdc++.h>
using namespace std;

vector<int> arr[10001];
int vis[10001];
int dist[10001];


void bfs(int src) {
	queue<int> q;
	q.push(src);
	vis[src] = 1;
	dist[src] = 0;
	while (!q.empty()) {
		int curr = q.front();
		q.pop();
		for (int child : arr[curr]) {
			if (!vis[child])
			{
				q.push(child);
				dist[child] = dist[curr] + 1;
				vis[child] = 1;
			}
		}
	}

}
int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int t;
	int n;//total number of nodes
	int m;//total number of edges
	int a, b;
	cin >> t;

	while (t--) {
		cin >> n >> m;
		for (int i = 1; i <= n; i++) arr[i].clear(), vis[i] = 0;
		for (int i = 1; i <= m; ++i)
		{
			cin >> a >> b;
			arr[a].push_back(b);
			arr[b].push_back(a);
		}

		bfs(1);
		cout << dist[n] << endl;
	}





}