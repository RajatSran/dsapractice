#include<bits/stdc++.h>
using namespace std;

// vector<vector<int>> arr(100001);//nodes
vector<int> arr[100001];
int vis[100001];

bool dfs(int node, int parent) {
	vis[node] = 1;
	for (int child : arr[node]) {
		if (vis[child] == 0) {
			if (dfs(child, node) == true)
				return true;
		} else {
			if (child != parent)
				return true;
		}
	}
	return false;
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
	bool cycle = false;
	cout << dfs(1, 2);
	// cout << cycle;

}

