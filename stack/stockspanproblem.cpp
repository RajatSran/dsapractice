#include<bits/stdc++.h>
using namespace std;

vector<int> nextLargestElement(vector<int> arr) {
	vector<int> v;
	stack<pair<int, int>> s;
	//traverse left to right;
	for (int i = 0; i <= arr.size() - 1 ; ++i)
	{
		if (s.size() == 0) {
			v.push_back(-1);
		} else if (s.top().first > arr[i]) {
			v.push_back(s.top().second);
		} else if (s.top().first < arr[i]) {
			while (s.size() > 0 && s.top().first <= arr[i]) {
				s.pop();
			}
			if (s.size() == 0)
				v.push_back(-1);
			else
				v.push_back(s.top().second);
		}
		s.push({arr[i], i});
		//atlast pushing the element
	}
	//NGL index in v vector
	return v;
}


int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	vector <int> v = { 100, 80, 60, 70, 60, 75, 85 };
	vector<int> output = nextLargestElement(v);
	for (int i = 0; i < output.size(); i++)
	{
		output[i] = i - output[i];
		cout << output[i] << endl;
	}

}