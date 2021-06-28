#include<bits/stdc++.h>
using namespace std;

// vector<vector<int>> arr(100001);//nodes
#define mod 1000000007
vector<int> arr[100001];
int vis[100001];
int cc_size;

void dfs(int node) {
	vis[node] = 1;
	cc_size++;
	for (int child : arr[node])
	{
		if (!vis[child]) {
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

	//---now taking input----//
	cin >> n >> m;
	for (int i = 1; i <= m; ++i)
	{
		cin >> a >> b;
		arr[a].push_back(b);
		arr[b].push_back(a);
	}






}

