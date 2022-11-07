#ifndef SHAPE_H
#define SHAPE_H

class Shape
{
protected:
	int x, y;       // for location
	bool selected;  // to indicate whether the shape is selected or not
	int color;
	
public:
	Shape(int _x = 0, int _y = 0, int _color =0);
	void setLocation(int _x, int _y);
	void setSelected(bool _selected);

	bool getSelected() const;

	virtual void undraw() const = 0;
	virtual void draw() const = 0;
	virtual void resize(double scale)= 0;
	

	void move(int dx, int dy);
	void changeColor(int);

	int getX() const;
	int getY() const;
	int getCol() const;

	void setCol(int c);


};

#endif