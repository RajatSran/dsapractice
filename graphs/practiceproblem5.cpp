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
	int t;//test cases
	int n;//total number of nodes
	int m;//total number of edges
	int a, b;
	cin >> t;

	//---now taking input----//
	while (t--) {
		cin >> n >> m;
		for (int i = 1; i <= n; i++) {
			vis[i] = 0;
			arr[i].clear();
		}
		for (int i = 1; i <= m; ++i)
		{
			cin >> a >> b;
			arr[a].push_back(b);
			arr[b].push_back(a);
		}
		int cc_size = 0;
		int cc = 0;
		int result = 1;
		for (int i = 1; i <= n; ++i)
		{
			if (!vis[i]) {
				cc_size = 0;
				dfs(i), cc++;
				result = (result * cc_size) % mod;
			}
		}
		cout << cc << " " << result << endl;
	}




}

