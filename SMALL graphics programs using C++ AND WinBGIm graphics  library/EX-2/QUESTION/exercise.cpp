// ? Exercise 2: Class and Object Manipulation

// Programming Technique II
// Semester 1, 2021/2022

// Date: 4 December 2021
// Section: _________
// Member 1's Name: _____________    Location: ____________ (i.e. where are you currently located)
// Member 2's Name: _____________    Location: ____________

// Log the time(s) your pair programming sessions
//  Date         Time (From)   To             Duration (in minutes)
//  _________    ___________   ___________    ________
//  _________    ___________   ___________    ________
//  _________    ___________   ___________    ________

#include <graphics.h>
#include <cmath>
#include <stdlib.h> /* srand, rand */
#include <time.h>

using namespace std;

// ?   - Choose the debug mode "Graphic Program" to run this program.

class Circle
{
private:
	int x, y;	// for location
	int radius; // for size
	int dx, dy; // for movement.  The value represents the speed, and the sign (i.e, - or +) represents direction.

public:
	Circle(int _x, int _y, int _radius, int _dx, int _dy);
	Circle();
	void setLocation(int _x, int _y);
	void setMovement(int _dx, int _dy);
	void draw() const;
	void undraw() const;
	void move();
};

#define CIRCLE_COUNT 5

int main()
{
	int width = getmaxwidth();
	int height = getmaxheight();
	char ch = 0; // The key pressed by the user. Used in the while() loop below

	// To initialize WinBGI and open a new window for graphic display
	initwindow(width, height, "Exercise 2");

	/* initialize random seed: */
	srand(time(NULL));

	// ! Task 3: Create an array of circles and display them on the screen

	while (ch != 27) // ASCII code 27 is the ESC key.
	{

		if (kbhit())
		{
			ch = getch();
			switch (toupper(ch))
			{

			// ! Task 4(a): re-position circles to random location.
			case 'R':
				break;

			// ! Task 4(b): move circles at random speed and direction
			case 'M':
				break;

			// ! Task 4(c): stop circles from moving
			case ' ':
				break;
			}
		}

		if (ismouseclick(WM_LBUTTONDOWN))
		{
			int mx, my;
			getmouseclick(WM_LBUTTONDOWN, mx, my);

			// ! Task 5: move or stop circles with mouse
		}

		//! Task 6: Simulate bouncing effects
		for (int i = 0; i < CIRCLE_COUNT; i++)
		{
		}

		delay(100);
	}
	return 0;
}

//? ---------------------------------------------------------------------------------------------
Circle::Circle(int _x, int _y, int _radius,
			   int _dx, int _dy)
	: x(_x), y(_y), radius(_radius),
	  dx(_dx), dy(_dy) {}

Circle::Circle() : Circle(0, 0, 0, 0, 0) {}

void Circle::setLocation(int _x, int _y)
{
	x = _x;
	y = _y;
}

void Circle::setMovement(int _dx, int _dy)
{
	dx = _dx;
	dy = _dy;
}

void Circle::draw() const
{
	setcolor(WHITE);
	circle(x, y, radius);
}

void Circle::undraw() const
{
	setcolor(BLACK);
	circle(x, y, radius);
}

void Circle::move()
{
	x += dx;
	y += dy;
}
//? ---------------------------------------------------------------------------------------------

