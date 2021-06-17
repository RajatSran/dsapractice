#include<bits/stdc++.h>
using namespace std;

bool palindrome(string s, int i, int j) {
	while (i <= j) {
		if (s[i] != s[j]) {
			return false;
		}
		i++;
		j--;
	}
	return true;
}

int palindromepartition(string s, int i, int j) {
	//start and end
	if (i >= j) {
		return 0;
	}
	if (palindrome(s, i, j)) {
		return 0;
	}
	int mini = INT_MAX;
	int temp;

	for (int k = i; k <= j - 1; ++k)
	{
		temp = palindromepartition(s, i, k) + palindromepartition(s, k + 1, j) + 1;
		if (temp < mini)
		{
			mini = temp;
		}
	}
	return mini;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	string s = "niti";
	cout << palindromepartition(s, 0, s.size() - 1);

}