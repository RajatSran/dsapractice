#include<bits/stdc++.h>
using namespace std;

/*properties to be a tree :
1. only one connected component --> calculate cc and check if it is one
2. if no cycle present --> number of edges = total nodes - 1

*/

//vector<vector<int>> arr(100001);//nodes
vector<int> arr[1001];
int vis[1001];
int col[1001];

bool dfs(int node, int c) {
	vis[node] = 1;
	col[node] = c;
	for (int child : arr[node]) {
		if (!vis[child]) {
			if (dfs(child, c ^ 1) == false) {
				return false;
			}
		} else {
			if (col[child] == col[node])
				return false;
		}
	}
	return true;
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
	cout << dfs(0, 1);



}
