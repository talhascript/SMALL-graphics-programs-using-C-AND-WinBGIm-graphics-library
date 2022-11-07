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
	Circle(int _x, int _y, int _radius =100); //1a
	Circle(const Circle &c);   //1b

	int distanceBetween(const Circle &c) const;  //2a
	int operator-(const Circle &c) const;   //2b
	friend int distance(const Circle &a, const Circle &b); //2c

	bool isMouseClicked(const Circle &c) const;  //5
	bool isMoving() const;//5

	int getdx() const ; //4b
	int getdy() const ; 

	bool operator==(const Circle &c) const; //6

	int getRad() const; //4a
	int getDiameter() const;//4a

	void setRandomMotion();
	void reverseX(); //6
	void reverseY();
	void reverse();
	int right() const;
	int left() const;
	int top() const;
	int bottom() const;
	


};

int distance(const Circle &a, const Circle&b){  //2a
	return sqrt(pow((b.x - a.x), 2) + pow((b.y - a.y), 2));
} 

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

	Circle list[CIRCLE_COUNT]={
		Circle(width/2,height/2), //correct centre
		Circle(width-100,height-100), //correct //bottom right
		Circle(width-width+100,height-height+100), //correct //top left
		Circle(width-100,height-height+100), //correct top right
		Circle(width-width+100,height-100) //correct bottom left
	};

	for(int i=0; i<CIRCLE_COUNT; i++){
		list[i].draw();
	}
	ch = getch();
	while (ch != 27) // ASCII code 27 is the ESC key.
	{
		for(int i=0; i<CIRCLE_COUNT; i++){
		list[i].undraw();
	}


		if (kbhit())
		{
			ch = getch();
			switch (toupper(ch))
			{

			// ! Task 4(a): re-position circles to random location.
			case 'R': 
				for(int i = 0; i<CIRCLE_COUNT; i++){
					list[i].setLocation(list[i].getRad()+ rand()%(width-list[i].getDiameter()),list[i].getRad()+ rand()% (height-list[i].getDiameter()));
				}

				break;

			// ! Task 4(b): move circles at random speed and direction
			case 'M':
				for(int i=0; i<CIRCLE_COUNT; i++){
					list[i].setRandomMotion();
					}
				break;

			// ! Task 4(c): stop circles from moving
			case ' ':
			for(int i = 0; i<CIRCLE_COUNT; i++) list[i].setMovement(0,0);
				break;
			}
		}

		if (ismouseclick(WM_LBUTTONDOWN))
		{
			int mx, my;
			getmouseclick(WM_LBUTTONDOWN, mx, my);
			Circle mouse(mx,my,0);

			// ! Task 5: move or stop circles with mouse

			for(int i=0; i<CIRCLE_COUNT; i++){
				if((mouse.isMouseClicked(list[i])) && ((list[i].isMoving())==false)){
					list[i].setRandomMotion(); //5a
				}else if((mouse.isMouseClicked(list[i])) && ((list[i].isMoving())==true)){
					list[i].setMovement(0,0); 
				}
			}

		}

		//! Task 6: Simulate bouncing effects
		//6a
		for (int i = 0; i < CIRCLE_COUNT; i++){
			if((list[i].left()<0) || (list[i].right()>width)){
					list[i].reverseX();
			}else if((list[i].top()<0) || (list[i].bottom()>height)){
					list[i].reverseY();
			}}
		
		//6b
		for(int i=0 ; i<CIRCLE_COUNT; i++){
			for(int j=i + 1 ; j<CIRCLE_COUNT; j++){
				if(list[i] == list[j]){
					list[i].reverse();
					list[j].reverse();
				}
			}}

			
		



	for(int i=0; i<CIRCLE_COUNT; i++){
		list[i].draw();
		list[i].undraw();
		list[i].move(); // starts speed (dx dy)
		list[i].draw();	
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

Circle::Circle(int _x, int _y, int _radius /*= 100*/){ //1a
	x=_x;
	y=_y;
	radius = _radius;
	dx=0;
	dy=0;
}

Circle :: Circle(const Circle &c){ //1b
	x=c.x;
	y=c.y;
	radius =c.radius;
	dx=0;
	dy=0;
}


int Circle::distanceBetween(const Circle &c) const{  //2a
	return sqrt(pow((c.x - x), 2) + pow((c.y - y), 2));
} 

int Circle::operator-(const Circle &c) const{  //2a
	return sqrt(pow((c.x - x), 2) + pow((c.y - y), 2));
} 

bool Circle ::isMouseClicked(const Circle &c) const{ //5
	bool val;
	int dist = *this - c;
	int sumRadius= c.radius + radius;

	if(dist<=sumRadius){
		val = true;
	}else if(dist>sumRadius){
		val = false;
	}

	return val;
}


bool Circle ::operator==(const Circle &c) const{ //6 // detects circle hitting with each other
	bool val;
	int dist = *this - c;
	int sumRadius= c.radius + radius;

	if(dist<=sumRadius){
		val = true;
	}else if(dist>sumRadius){
		val = false;
	}

	return val;
}

bool Circle ::isMoving() const{
	bool val;
	if((dx!=0) || (dy!=0)){
		val = true;
	}else{ val= false;}

	return val;
}




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

void Circle:: setRandomMotion(){
	int dirX =  rand() % 2 ? -1 : 1; 
	int dirY =  rand() % 2 ? -1: 1;
	
	setMovement(dirX* (rand() % 40), dirY*(rand() % 40));

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

int Circle:: getdx() const{
	return dx;}//4b


int Circle:: getdy() const{
	return dy;}//4b
	

int Circle :: getRad() const{
	return radius;
}

int Circle :: getDiameter() const{
	return 2*radius;
}

void Circle :: reverseX(){ //6
	dx=-dx;
	
}

void Circle :: reverseY(){ //6
	dy=-dy;
	
}

void Circle :: reverse(){ //6
	dx=-dx;	
	dy=-dy;
	
}

//6a

int Circle :: right() const{
	return x+radius;
}

int Circle :: left() const{
	return x-radius;
}

int Circle :: top() const{
	return y-radius;
}

int Circle :: bottom() const{
	return y+radius;
}


	
//? ---------------------------------------------------------------------------------------------

