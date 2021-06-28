#include<bits/stdc++.h>
using namespace std;


//vector<vector<int>> arr(100001);//nodes
vector<int> arr[1001];
int vis[1001];
int col[1001];

bool dfs(int node, int c) {
	vis[node] = 1;
	col[node] = c;
	for (int child : arr[node]) {
		if (!vis[child]) {
			if (dfs(child, c ^ 1) == false) {//if
				return false;
			}
		} else {
			if (col[child] == col[node])//if child and parent both have same color
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
