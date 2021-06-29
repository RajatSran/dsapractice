#include<bits/stdc++.h>
using namespace std;

#define mod 1000000007
vector<int> arr[100];
int vis[100], in[100], low[100];
int timer;

void dfs(int node, int par) {
	vis[node] = 1;
	in[node] = low[node] = timer;
	timer++;
	for (int child : arr[node]) {
		if (child == par) continue;

		if (vis[child] == 1) {
			//child is a back edge
			low[node] = min(low[node], in[child]);
		} else {
			//child is a forward edge
			dfs(child, node);
			if (low[child] > in[node]) {
				cout << node << "-" << child << " is a bridge\n";
			}
			low[node] = min(low[node], low[child]);
		}
	}
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	// setTextSize();
	int n;//total number of nodes
	int m;//total number of edges
	int a, b;

	//---now taking input----//
	cin >> n >> m;
	while (m--) {
		cin >> a >> b;
		arr[a].push_back(b);
		arr[b].push_back(a);
	}
	dfs(1, -1);
}

