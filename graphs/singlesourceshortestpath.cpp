#include<bits/stdc++.h>
using namespace std;

// vector<vector<int>> arr(100001);//nodes
vector<int> arr[1001];
int vis[1001];
int dist[1001];

//single source shortest path
void dfs(int node, int d) {
	vis[node] = 1;
	dist[node] = d;
	for (int child : arr[node])
	{
		if (!vis[child])
		{
			dfs(child, dist[node] + 1);
		}
	}
}


int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int n;//total number of nodes
	int m;//total number of edges
	int a, b;

	//---now taking input----//
	cin >> n >> m;
	for (int i = 1; i <= m; ++i)
	{
		cin >> a >> b;
		arr[a].push_back(b);
		arr[b].push_back(a);
	}

	dfs(1, 0);

	int q;
	cin >> q; //number of girls
	int ans = -1, min_dist = INT_MAX;
	while (q--) {
		int girl_city;
		cin >> girl_city;
		if (dist[girl_city] < min_dist)
		{
			min_dist = dist[girl_city];
			ans = girl_city;
		}
		if (dist[girl_city] == min_dist && girl_city < ans) {
			ans = girl_city;
		}
	}
	cout << ans;



}

