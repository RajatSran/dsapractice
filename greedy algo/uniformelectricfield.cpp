#include<iostream>
#include<cmath>
#include <fstream>
using namespace std;
ofstream output("out.dat");
class em
{
	float initial_t, final_t, d, E, B, q, m, x, y, Velocity_x, Velocity_y, ax, ay;
	int i, n;
public:
	void get();
	void cal();
};

void em::get()
{
	cout << "enter initial time, final time, step size, EF, MF, charge, mass" << endl;
	cin >> initial_t >> final_t >> d >> E >> B >> q >> m;
	n = (final_t - initial_t) / d;
	x = 0;
	y = 0;
	Velocity_x = 1;
	Velocity_y = 1;
}
void em::cal()
{
	for (i = 1; i <= n; i++)
	{
		ax = (q * Velocity_y * B) / m;
		ay = q * (E - Velocity_x * B) / m;
		Velocity_x = Velocity_x + (ax * d);
		Velocity_y = Velocity_y + (ay * d);
		x = x + Velocity_x * d;
		y = y + Velocity_y * d;
		output << x << " : " << y << endl;
	}
}

int main()
{
	em field;
	field.get();
	field.cal();
	return 0;
}

