#include<bits/stdc++.h>
using namespace std;

vector<int> nextLargestElement(vector<int> arr) {
	vector<int> v;
	stack<int> s;
	//traverse right to left;
	for (int i = arr.size() - 1; i >= 0; --i)
	{
		if (s.size() == 0) {
			v.push_back(-1);
		} else if (s.top() > arr[i]) {
			v.push_back(s.top());
		} else if (s.top() < arr[i]) {
			while (s.size() > 0 && s.top() <= arr[i]) {
				s.pop();
			}
			if (s.size() == 0)
				v.push_back(-1);
			else
				v.push_back(s.top());
		}
		s.push(arr[i]);//atlast pushing the element
	}
	reverse(v.begin(), v.end());
	return v;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	vector <int> v = { 1, 3, 2, 4 };
	vector<int> output = nextLargestElement(v);
	for (auto x : output)
	{
		cout << x << endl;
	}

}