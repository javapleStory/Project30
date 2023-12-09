#include <iostream>
using namespace std;

class Circle
{
	int radius;
public:
	Circle(int radius = 1) {}
	~Circle() { cout << radius << " 객체 소멸중..." << endl; }
	void setRadius(int r) {radius = r; }
	double getRadius() { return radius * radius * 3.14; }
};

void msg(int a, string word, Circle b = Circle(1)) {}

class CircleVector
{
	int size;
	Circle* p;
public:
	CircleVector(int n = 5)
	{
		p = new Circle[n];
		size = n;
		for (int i = 0; i < size; i++)
		{
			p[i].setRadius(i + 1);
			cout << "반지름 " << i + 1 << "로 변경중...  면적은 " << p[i].getRadius() << endl;
		}
	}
	~CircleVector() { delete[]p; }

};

class Person
{
	int id;
	double weight;
	string name;
public:
	Person(int id = 1, string name = "Grace", double weight = 20.5) { this->id = id, this->weight = weight; this->name = name; }
	~Person() {}
	void show() { cout << id << " " << weight << " " << name << endl; }

};

class ArrayUtility
{
public:
	static void iTod(int s[], double d[], int size)
	{
		for (int i = 0; i < size; i++)
		{
			d[i] = (double)s[i];
		}
	}

	static void dToi(double d[], int s[], int size)
	{
		for (int i = 0; i < size; i++)
		{
			s[i] = (int)d[i];
		}
	}
};

int main()
{
	CircleVector* c1, * c2;
	c1 = new CircleVector();
	cout << endl;
	c2 = new CircleVector(10);
	cout << endl;
	delete c1;
	cout << endl;
	delete c2;
	cout << endl;

	Person grace, ashley(2, "Ashley"), helen(3, "Helen", 32.5);
	grace.show();
	ashley.show();
	helen.show();
	cout << endl;

	int x[] = { 1,2,3,4,5 };
	double y[5];
	double z[] = { 9.9,8.8,7.7,6.6,5.5 };
	ArrayUtility::iTod(x, y, 5);
	for (int i = 0; i < 5; i++) cout << y[i] << " ";
	cout << endl;
	ArrayUtility::dToi(z, x, 5);
	for (int i = 0; i < 5; i++) cout << x[i] << " ";
	cout << endl;
}