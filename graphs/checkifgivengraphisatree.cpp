#include<bits/stdc++.h>
using namespace std;

/*properties to be a tree :
1. only one connected component --> calculate cc and check if it is one
2. if no cycle present --> number of edges = total nodes - 1

*/

//vector<vector<int>> arr(100001);//nodes
vector<int> arr[1001];
int vis[1001];

void dfs(int node) {
	vis[node] = 1;
	for (int child : arr[node]) {
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
	int n, m;
	cin >> n >> m;
	int a, b;
	for (int i = 0; i < m; ++i)
	{
		cin >> a;
		cin >> b;
		arr[a].push_back(b);
		arr[b].push_back(a);
	}

	int cc = 0;
	for (int i = 1; i <= n; ++i)
	{
		if (!vis[i]) {
			dfs(i);
			cc++;
		}
	}

	if (cc == 1 && m == n - 1) {
		cout << "its a tree";
	} else {
		cout << "its not a tree";
	}


}
