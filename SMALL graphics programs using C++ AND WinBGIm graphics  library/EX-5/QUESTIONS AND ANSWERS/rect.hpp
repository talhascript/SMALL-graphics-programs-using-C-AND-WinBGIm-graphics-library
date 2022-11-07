#ifndef RECT_H
#define RECT_H
#include "shape.hpp"
class Rect : public Shape
{
protected:
    int width, height;

public:
    Rect(int _x = 0, int _y = 0, int _width = 0, int _height=0, int _color=0) ;
    void draw() const;
    void undraw() const;
    void resize(double scale);

    int getW() const;
    int getH() const;

   
};

#endif