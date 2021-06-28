#include<bits/stdc++.h>
using namespace std;

#define mod 1000000007
vector<int> arr[100001];
int vis[100001];
int dist[100001];
int level[100001];
vector<int> result;
void bfs(int src, int req_dist) {
	queue<int> q;
	q.push(src);
	vis[src] = 1;
	while (!q.empty()) {
		int curr = q.front();
		q.pop();
		for (int child : arr[curr]) {
			if (!vis[child]) {
				q.push(child);
				vis[child] = 1;
				dist[child] = dist[curr] + 1;
				level[dist[child]]++;
			}
		}
		if (dist[curr] == req_dist) {
			result.push_back(curr);
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
	int src, q, d;
	//---now taking input----//
	cin >> n >> m;
	for (int i = 1; i <= m; ++i)
	{
		cin >> a >> b;
		arr[a].push_back(b);
		arr[b].push_back(a);
	}
	cin >> q;
	while (q--) {
		cin >> src >> d;
		for (int i = 0; i <= n; i++) {
			level[i] = 0, vis[i] = 0;
		}
		bfs(src, d);
		cout << level[d] << endl;
	}
//---------------------------------
	bfs(1, 3);
	for (int x : result) {
		cout << x << " ";
	}





}

