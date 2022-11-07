#include <graphics.h>
#include<cmath>

#include "circle.hpp"
#include "shape.hpp"

Circle::Circle(int _x, int _y, int _radius,int _color): Shape(_x, _y, _color) ,radius(_radius) {}

void Circle::draw() const
    {
        setcolor(color);
        circle(x, y, radius);
    }

void Circle::undraw() const
    {
        setcolor(BLACK);
        circle(x, y, radius);
    }

void Circle::resize(double scale)
    {
        undraw();
        radius = radius * scale;
        draw();
    }


bool Circle ::isMouseClicked( const Circle &c) const{ 
	bool val;
	int dist = sqrt(pow((c.x - x), 2) + pow((c.y - y), 2));
	int sumRadius= c.radius + radius;

	if(dist<=sumRadius){
		val = true;
	}else if(dist>sumRadius){
		val = false;
	}

	return val;
}

bool Circle ::isMouseClicked( const Rect *r) const{
    bool val;

    if( (r->getX() <= x) && (x<= (r->getX()+ r->getW()))  &&     (r->getY() <= y) &&  (y<= (r->getY() + r->getH())) ) {
        val = true;

    }else{val = false;}

    return val;

}




