
// Note that by default C++ creates a max-heap
// for priority queue
#include <iostream>
#include <queue>

using namespace std;

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int arr[] = { 12, 3, 5, 7, 19 };
	int n = sizeof(arr) / sizeof(arr[0]), k = 4;

	priority_queue<int> maxp;
	for (int i = 0; i < n - 1 ; ++i)
	{
		maxp.push(arr[i]);
		if (maxp.size() > k)
		{
			maxp.pop();
		}
	}
	cout << maxp.top();

	return 0;
}

