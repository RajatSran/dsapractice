//insert , remove min, get min
//create isempty ,getsize, getmin
#include<vector>
class priorityqueue
{
	vector<int> pq;

public:
	priorityqueue();
	~priorityqueue();
	bool isempty() {
		return pq.size() == 0;
	}

	int getsize() {
		return pq.size();
	}

	int getmin() {
		if (isempty())
		{
			return 0;
		}
		return pq[0];
	}

	void insert(int val) {
		pq.push_back(val);
		int childindex = pq.size() - 1;

		while (childindex > 0)
		{
			parentindex = (childindex - 1) / 2;

			if (pq[parentindex] > pq[childindex])
			{
				int temp = pq[parentindex];
				pq[parentindex] = pq[childindex];
				pq[childindex] = temp;
			}
			childindex = parentindex;
		}
	}

	void removemin() {
		int childindex = pq.size() - 1;
		pq[0] = pq[childindex];
		pq.pop_back();

		int i = 0;

		int min = -1;
		while (i < pq.size() - 2) {
			int leftchild = pq[2 * i + 1];
			int rightchild = pq[2 * i + 2];
			if (leftchild > pq.size() - 2 || rightchild > pq.size() - 2)
			{
				return;
			}
			if (pq[leftchild] > pq[rightchild])
			{
				min = rightchild;
			}
			else {
				min = leftchild;
			}
			if (pq[i] > min)
			{
				int temp = pq[min];
				pq[min] = pq[i];
				pq[i] = temp;
				i = min;
			} else {
				break;
			}
		}
	}
};




