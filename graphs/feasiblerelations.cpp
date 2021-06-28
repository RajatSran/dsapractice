#include<bits/stdc++.h>
using namespace std;
/*
---input----
2
2 2
1 = 2
1 != 2
3 2
1 = 2
2 != 3

---output---
NO
YES
*/
vector<int> arr[10001];
int vis[10001];
int cc[10001];
int curr_cc;


void dfs(int node) {
	vis[node] = 1;
	cc[node] = curr_cc;
	for (int child : arr[node]) {
		if (!vis[child])
			dfs(child);
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
	string op;
	cin >> t;

	while (t--) {
		cin >> n >> m;
		curr_cc = 0;
		vector<pair<int, int>> edgelist;
		for (int i = 1; i <= n; i++) {
			arr[i].clear(), vis[i] = 0;
		}
		for (int i = 1; i <= m; ++i)
		{
			cin >> a >> op >> b;
			if (op == "=") {
				arr[a].push_back(b), arr[b].push_back(a);
			} else {
				edgelist.push_back({a, b});
			}

		}

		for (int i = 1; i <= n; i++) {
			if (!vis[i]) {
				curr_cc++;
				dfs(i);
			}
		}
		bool flag = true;
		for (int i = 0; i < edgelist.size(); ++i)
		{
			a = edgelist[i].first;
			b = edgelist[i].second;
			if (cc[a] == cc[b]) {
				flag = false;
				break;
			}
		}
		if (flag) {
			cout << "YES" << endl;
		} else {
			cout << "NO" << endl;
		}

	}

}