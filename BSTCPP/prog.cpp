#include <iostream>
#include <cstdlib>
using namespace std;

class dice
{
 public:
	dice()			{ sides = 6; }
	dice( int S )	{ sides = S; }
	int roll()		{ return rand() % sides + 1; }
 private:
	int sides;
};


class box
{
 public:
	box();
	box( int height, int width );
	void show();
	void show( char sym );
 private:
	void printbox( char disp );
	int H;
	int W;
};


box::box()
{
	H = 5;
	W = 5;
}

box::box(int height, int width)
{
	H = height;
	W = width;
}


void box::show()
{
	printbox( '@' );
}

void box::show(char sym)
{
	printbox( sym );
}


void box::printbox( char disp )
{
	int r, c;
	for (r = 1; r <= H; ++r)
	{
		for (c = 1; c <= W; ++c)
		{
			cout << disp << " ";
		}
		cout << endl;
	}
}





int main()
{
	int i;
	 dice d1, d2(20);
	box b(5,8), square;

	srand( time(NULL) );

	for (i = 1; i <= 3; ++i)
	{
	cout << "Roll " << d1.roll() << " -- " << d2.roll() << endl;
	}

	b.show();
	cout << endl;
	b.show('#');
	cout << endl;
	square.show();
	return 0;
}
