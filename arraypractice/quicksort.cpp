#include <bits/stdc++.h>
#include <iostream>
using namespace std;

void swap(int array[], int a, int b) {
	int temp = array[a];
	array[a] = array[b];
	array[b] = temp;
}

int partition(int array[], int l, int r) {
	int pivot = array[r];
	int i = l - 1;
	for (int j = l; j < r; ++j)
	{
		if (array[j] < pivot) {
			i++;
			swap(array, i, j);
		}
	}
	swap(array, i + 1, r);
	return i + 1;
}

void QuickSort(int array[] , int l, int r) {
	int mid;
	if (l < r) {
		int pi = partition(array, l, r);
		QuickSort(array, l, pi - 1);
		QuickSort(array, pi + 1, r);
	}
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	int n;
	cin >> n;
	int array[n];
	for (int i = 0; i < n; ++i)
	{
		cin >> array[i];
	}

	QuickSort(array, 0, n);

	for (int i = 0; i < n; ++i)
	{
		cout << array[i] << " ";
	}

}