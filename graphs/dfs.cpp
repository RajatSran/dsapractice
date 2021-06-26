#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> arr(100001);//nodes
int vis[100001];

void dfs(int node) {
	vis[node] = 1;
	for (int child : arr[node])
	{
		if (!vis[child])
		{
			dfs(child);
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
	cin >> n >> m;
	for (int i = 1; i <= m; ++i)
	{
		cin >> a >> b;
		arr[a].push_back(b);
		arr[b].push_back(a);
	}
	int cc = 0; //connected component count
	for (int i = 1; i <= n; ++i)
	{
		if (!vis[i]) {
			dfs(i) ;
			cc++;
		}
	}
	cout << cc;

}
