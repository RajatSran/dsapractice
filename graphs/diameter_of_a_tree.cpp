#include<bits/stdc++.h>
using namespace std;

// vector<vector<int>> arr(100001);//nodes
#define mod 1000000007
vector<int> arr[100001];
int vis[100001];
int cc_size;
int distance;

int maxD, maxNode;
void dfs(int node, int d) {
	vis[node] = 1;
	if (d > maxD) maxD = d, maxNode = node;

	for (int child : arr[node])
	{
		if (!vis[child]) {
			dfs(child, d + 1);
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
	for (int i = 1; i <= n ; ++i)
	{
		vis[i] = 0;
	}
	maxD = -1;
	dfs(maxNode, 0);
	cout << maxD;





}

