#include<iostream>
using namespace std;

template <typename T, typename V>
class Pair {
	T x;
	V y;
public:
	void setX(T x) {
		this->x = x;
	}

	void setY(V y) {
		this->y = y;
	}

	T getx() {
		return x;
	}
	V gety() {
		return y;
	}
};

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	Pair<int, char> i;
	i.setX(1);
	i.setY('a');
	cout << i.getx() << " " << i.gety() << endl;
	Pair<double, double> d;
	d.setX(1.2);
	d.setY(2.02);
	cout << d.getx() << " " << d.gety() << endl;
	Pair<char, char> c;
	c.setX('a');
	c.setY('b');
	cout << c.getx() << " " << c.gety() << endl;

}