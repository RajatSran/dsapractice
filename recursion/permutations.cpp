#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> ans;
void generate(vector<int>& arr, int index) {
	if (index == arr.size() - 1) {
		ans.push_back(arr);
		return;
	}
	for (int i = index; i < arr.size(); ++i)
	{
		swap(arr[i], arr[index]);
		generate(arr, index + 1);
		swap(arr[i], arr[index]);
	}
	return;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	vector <int>arr = { 1, 2, 3, 4, 3 };
	generate(arr, 0);
	for (auto &i : ans) {
		for (auto &v : i)
		{
			cout << v << " ";
		}
		cout << endl;
	}

}