#include <graphics.h>

#include "shape.hpp"
#include "rect.hpp"

Rect::Rect(int _x, int _y,  int _width, int _height, int _color) : Shape(_x, _y, _color), width(_width), height(_height) {}

void Rect::draw() const
    {
        setcolor(color);
        rectangle(x, y, x + width, y + height);
    }

void Rect::undraw() const
    {
        setcolor(BLACK);
        rectangle(x, y, x + width, y + height);
    }

void Rect::resize(double scale)
    {
        undraw();
        width = width * scale;
        height = height * scale;
        draw();
    }

int Rect::getW() const{return width;}
int Rect::getH() const{return height;}


