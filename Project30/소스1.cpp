#include <iostream>
using namespace std;

class Rect;

class RectManager
{
public:
	bool equal(Rect a, Rect b);
};

class Rect
{
	int width, height;
public:
	Rect(int w = 1, int h = 1) { width = w; height = h; }
	~Rect(){}
	friend bool equals(Rect a, Rect b);
	friend RectManager;
};

bool RectManager::equal(Rect a, Rect b)
{
	if (a.width == b.width && a.height == b.height)
		return true;
	else return false;
}

bool equals(Rect a, Rect b)
{
	if (a.width == b.width && a.height == b.height)
		return true;
	else return false;
}

int main()
{
	Rect a(3, 4), b(4, 5);
	RectManager man;
	if (man.equal(a, b)) cout << "a == b" << endl;
	else cout << "a != b" << endl;
}