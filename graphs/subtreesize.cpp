#include<bits/stdc++.h>
using namespace std;

// vector<vector<int>> arr(100001);//nodes
#define mod 1000000007
vector<int> arr[100001];
int vis[100001];
int subtreesize[100001];

int dfs(int node) {
	int currentsize = 1;
	vis[node] = 1;
	for (int child : arr[node]) {
		if (!vis[child]) {
			currentsize += dfs(child);
		}
	}
	subtreesize[node] = currentsize;
	return currentsize;
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
	memset(vis, 0, 100001);
	memset(subtreesize, 0, 100001);
	//----here enter the node for which we need to find subtree--//
	cout << dfs(1);



}

