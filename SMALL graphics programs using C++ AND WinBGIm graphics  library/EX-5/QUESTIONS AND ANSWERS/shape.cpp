#include <graphics.h>
#include "shape.hpp"

Shape::Shape(int _x, int _y, int _color) : x(_x), y(_y), color(_color),selected(false) {}

void Shape::setLocation(int _x, int _y)
{
	x = _x;
	y = _y;
}



void Shape::move(int dx, int dy)
    {
        undraw(); 
        x += dx;
        y += dy;
        draw();
    }

void Shape :: changeColor(int c){
    undraw(); 
    setCol(c);
    draw();
}




void Shape::setSelected(bool _selected) {selected = _selected;}

bool Shape:: getSelected() const{return selected;}

int Shape:: getX() const { return x; }
int Shape:: getY() const { return y; }

int Shape::getCol() const{ return color;}


void Shape::setCol(int c){
    color = c;
}


