#include<bits/stdc++.h>
#include<iostream>
using namespace std;


int mergeksortedarray(int array1[], int array2[], int array3[]) {
	priority_queue<int, vector<int>, greater<int>> pq;


}

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int array1[6] = {1, 2, 4, 7, 13, 14};
	int array2[7] = {3, 5, 9, 18, 19, 22, 24};
	int array3[5] = {5, 6, 7, 15, 32};
	int n = sizeof(array1) / sizeof(array1[0]) + sizeof(array2) / sizeof(array2[0]) + sizeof(array3) / sizeof(array3[0]);
	cout << n;

	int final[n] = mergeksortedarray(array1, array2, array3);


}