// ? Exercise 5: Polymorphism

// Programming Technique II
// Semester 1, 2021/2022

// Date: _________
// Section: _________
// Member 1's Name: _____________    Location: ____________ (i.e. where are you currently located)
// Member 2's Name: _____________    Location: ____________

#include <graphics.h>
#include <cmath>
#include <stdlib.h>
#include <time.h>
#include "iostream"
#include "shape.hpp"
#include "circle.hpp"
#include "rect.hpp"

using namespace std;

// ? Notes: Choose the debug mode "Multi-File Graphic Project" to run this program.

// You may change the max size of the list
#define COUNT 5
#define C_COUNT 2
#define R_COUNT 3

int main()
{
	int width = getmaxwidth();
	int height = getmaxheight();
	initwindow(width, height, "Exercise 5");

	/* initialize random seed: */
	srand(time(NULL));
	Shape *s[COUNT];
	Circle c[COUNT];
	Rect r[COUNT];

int random, randomX, randomY, randomRad, randomWid, randomHeight;




	for(int i =0; i<COUNT ; i++){
		random = rand() % 2;
		randomX =  100+ rand() % (width-300);
		randomY =  100+ rand() % (height-300);
		randomRad = 20 + rand() % 70;

		randomWid = 20 + rand() % 70;
		randomHeight = 20 + rand() % 70;


		

		if(random == 0){ 
		c[i] = Circle (randomX , randomY, randomRad,WHITE);
		s[i] = &c[i];
		continue;
		}

		else if(random == 1){
		r[i]= Rect (randomX , randomY, randomWid, randomHeight,WHITE);
		s[i] = &r[i];
		continue;
		}
	}

	
	for(int i =0 ; i<COUNT; i++){
		c[i].draw();
		r[i].draw();
	}


	char ch = 0;

	const int DISTANCE = 5;
    const double ENLARGE_SCALE = 1.5;
    const double SHRINK_SCALE = 0.75;

	while (ch != 27)  // 27 is ESC key
	{
	
		if (kbhit())
		{
			ch = getch();
			switch (toupper(ch))
			{
			case '=': // '+'
			for(int i =0; i<COUNT; i++){
				if((s[i]->getSelected())==true){
					s[i]->resize(ENLARGE_SCALE);
				}
			}
				break;

			case '-':
			for(int i =0; i<COUNT; i++){
				if((s[i]->getSelected())==true){
					s[i]->resize(SHRINK_SCALE);
				}
			}
				break;

			case KEY_LEFT:
			for(int i =0; i<COUNT; i++){
				if((s[i]->getSelected())==true){
					s[i]->move(-DISTANCE, 0);
				}
			}
				break;

			case KEY_RIGHT:
			for(int i =0; i<COUNT; i++){
				if((s[i]->getSelected())==true){
					s[i]->move(DISTANCE, 0);
				}
			}
				break;

			case KEY_UP:
			for(int i =0; i<COUNT; i++){
				if((s[i]->getSelected())==true){
					s[i]->move(0, -DISTANCE);
				}
			}
				break;

			case KEY_DOWN:
			for(int i =0; i<COUNT; i++){
				if((s[i]->getSelected())==true){
					s[i]->move(0, DISTANCE);
				}
			}
				break;
			}
		}

		if (ismouseclick(WM_LBUTTONDOWN))
		{
			int mx, my;
			getmouseclick(WM_LBUTTONDOWN, mx, my);
			Circle mouse(mx,my,0);
			
			bool selected = false;
			int selectedIndex;

			for(int i = 0; i<COUNT; i++){
				if(mouse.isMouseClicked(c[i])){
					s[i]->changeColor(YELLOW);
					selected = true;
					s[i]->setSelected(selected);
					selectedIndex = i;

					for(int i=0; i<COUNT; i++){
						if(i != selectedIndex){
							selected = false;
							s[i]->setSelected(selected);
							s[i]->changeColor(WHITE);
						}
					}
					
					
				}else if (mouse.isMouseClicked(&r[i])){
					s[i]->changeColor(YELLOW);
					selected = true;
					s[i]->setSelected(selected);
					selectedIndex = i;

					for(int i=0; i<COUNT; i++){
						if(i != selectedIndex){
							selected = false;
							s[i]->setSelected(selected);
							s[i]->changeColor(WHITE);

						}
					}
				}
			}

		}
	}
	return 0;
}