#include<bits/stdc++.h>
#include<iostream>
using namespace std;

void reverse(string s) {
	stack<string> st;
	for (int i = 0; i < s.size(); ++i)
	{
		string word = "";
		while (s[i] != ' ' && i < s.length()) {
			word += s[i];
			i++;
		}
		st.push(word);
	}

	while (!st.empty()) {
		cout << st.top() << " ";
		st.pop();
	}
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	string s = "hey i am using stack";
	reverse(s);
}