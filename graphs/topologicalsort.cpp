#include<bits/stdc++.h>
using namespace std;

#define mod 1000000007
vector<int> arr[1001];
vector<int> res;
int in[100];

// O(N+E)
void khan(int n) {
	queue<int> q;
	//priority_queue<int, vector<int>, greater<int>>
	//q; ->> use this min heap if you want to print in lexographical order
	for (int i = 1; i <= n; ++i) {
		if (in[i] == 0) {
			q.push(i);
		}
	}

	while (!q.empty()) {
		int curr = q.front();
		res.push_back(curr);
		q.pop();
		for (auto node : arr[curr]) {
			in[node]--;
			if (in[node] == 0) {
				q.push(node);
			}
		}
	}
	cout << "Top sort : ";
	for (int node : res)
		cout << node << " ";
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int n, m, x, y;
	cin >> n >> m;
	for (int i = 0; i < m; ++i)
	{
		cin >> x >> y;
		arr[x].push_back(y);//it's a directed edge
		in[y]++;
	}
	khan(n);
}

