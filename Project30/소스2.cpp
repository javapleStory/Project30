#include <iostream>
using namespace std;

class Power
{
	int kick;
	int punch;
public:
	Power(int k = 0, int p = 0) { kick = k; punch = p; }
	~Power() {}
	void show() { cout << "Kick : " << kick << ", Punch : " << punch << endl;}

	Power operator+(Power p)
	{
		Power temp;
		temp.kick = this->kick + p.kick;
		temp.punch = this->punch + p.punch;
		return temp;
	}

	bool operator==(Power p)
	{
		if (this->kick == p.kick && this->punch == p.punch) return true;
		else return false;
	}

	Power& operator +=(Power p)
	{
		this->kick += p.kick;
		this->punch += p.punch;
		return *this;
	}

	Power operator+(int a)
	{
		Power temp;
		temp.kick = this->kick + a;
		temp.punch = this->punch + a;
		return temp;
	}

	/*Power& operator ++()
	{
		++this->kick;
		++this->punch;
		return *this;
	}
	
	Power& operator++(int x)
	{
		this->kick++;
		this->punch++;
		return *this;
	}
	*/

	bool operator!()
	{
		if (this->kick == 0 && this->punch == 0) return true;
		else return false;
	}

	friend Power operator+(int a, Power p);
	friend Power& operator++(Power& p);
	friend Power& operator++(Power& p, int x);
};

Power operator+(int a, Power p)
{
	Power temp;
	temp.kick = 2 + p.kick;
	temp.punch = 2 + p.punch;
	return temp;
}

Power& operator ++(Power& p)
{
	++p.kick;
	++p.punch;
	return p;
}

Power& operator++(Power& p, int x)
{
	Power& temp = p;
	p.kick++;
	p.punch++;
	return temp;
}

int main()
{
	Power a(3, 5), b(4, 6), c;
	c = ++a;
	c = a++;
	c = 2 + b;

	a.show();
	b.show();
	c.show();

	if (a == b) cout << "a == b" << endl;
	else cout << "a != b" << endl;

	if (!a) cout << "a = 0" << endl;
	else cout << "a != 0" << endl;
}