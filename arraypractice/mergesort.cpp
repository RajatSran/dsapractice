#include <bits/stdc++.h>
#include <iostream>
using namespace std;

// T(n)=2T(n/2)+n

void Merge(int array[], int l, int mid, int r) {
	int n1 = mid - l + 1;
	int n2 = r - mid;

	//temp arrays
	int a[n1];
	int b[n2];

	for (int i = 0; i < n1; ++i)
	{
		a[i] = array[l + i];
	}

	for (int i = 0; i < n2; ++i)
	{
		b[i] = array[mid + 1 + i];
	}

	int i = 0;
	int j = 0;
	int k = l;
	while (i < n1 && j < n2) {
		if (a[i] < b[j]) {
			array[k] = a[i];
			k++; i++;
		} else {
			array[k] = b[j];
			k++; j++;
		}
	}

	while (i < n1) {
		array[k] = a[i];
		k++; i++;
	}
	while (j < n2) {
		array[k] = b[j];
		k++; j++;
	}
}

void MergeSort(int array[] , int l, int r) {
	int mid;
	if (l < r) {
		mid = (l + r) / 2;
		MergeSort(array, l, mid);
		MergeSort(array, mid + 1, r);
		Merge(array, l, mid, r);
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

	MergeSort(array, 0, n);

	for (int i = 0; i < n; ++i)
	{
		cout << array[i] << " ";
	}

}