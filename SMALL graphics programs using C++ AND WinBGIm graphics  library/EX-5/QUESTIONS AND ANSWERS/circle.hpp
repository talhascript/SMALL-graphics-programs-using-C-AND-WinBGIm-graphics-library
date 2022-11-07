#ifndef CIRCLE_H
#define CIRCLE_H

#include "shape.hpp"
#include "rect.hpp"

class Circle : public Shape
{
private:
    Rect *r;
protected:
    int radius;

public:
    Circle(int _x = 0, int _y = 0, int _radius = 0,int _color=0);
    void draw() const;
    void undraw() const;
    void resize(double scale);

    bool isMouseClicked(const Circle &c) const;
    bool isMouseClicked( const Rect *) const;

};


#endif