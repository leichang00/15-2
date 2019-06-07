#ifndef GEOMETRICOBJECT_H
#define GEOMETRICOBJECT_H
#include <string>
using namespace std;

class GeometricObject
{
public:
	GeometricObject();
	GeometricObject(const string& color);
	string getColor() const;
	void setColor(const string& color);
	string toString() const;
	virtual double getArea() const=0;
	virtual double getVolume() const=0;

private:
	string color;
}; // Must place semicolon here

#endif 

#ifndef BALL_H
#define BALL_H
//#include "GeometricObject.h"

class Ball : public GeometricObject
{
public:
	Ball();
	Ball(double radius);
	Ball(double radius,const string& color);
	double getRadius() const;
	void setRadius(double);
	double getArea() const;
	double getVolume() const;
	virtual string toString() const;

private:
	double radius;
}; // Must place semicolon here

#endif


#ifndef CUBE_H
#define CUBE_H
//#include "GeometricObject.h"
class Cube : public GeometricObject
{
public:
	Cube();
	Cube(double length);
	Cube(double length,const string& color);
	double getLength() const;
	void setLength(double);
	double getArea() const;
	double getVolume() const;
	string toString() const;

private:
	double length;
};  // Must place semicolon here

#endif


//#include "GeometricObject.h" 
GeometricObject::GeometricObject()
{
	color = "white";
}

GeometricObject::GeometricObject(const string& color)
{
	this->color = color;
}

string GeometricObject::getColor() const
{
	return color;
}

void GeometricObject::setColor(const string& color)
{
	this->color = color;
}

string GeometricObject::toString() const
{
	return "Geometric Object";
}

//#include "Ball.h"
#include <string>
// Construct a default Ball object
Ball::Ball()
{
	radius = 1;
}

// Construct a Ball object with specified radius
Ball::Ball(double radius)
{
	setRadius(radius);
}

Ball::Ball(double radius,const string& color)
{
	this->radius=radius;
	setColor(color);
}

// Return the radius of this Ball
double Ball::getRadius() const
{
	return radius;
}

// Set a new radius
void Ball::setRadius(double radius)
{
	this->radius = (radius >= 0) ? radius : 0;
}


// Return the area of this Ball
double Ball::getArea() const
{
	return radius * radius * 3.14159 * 4;
}

double Ball::getVolume() const
{
	return radius *radius *radius * 4/3 *3.14159;
}


// Redefine the toString function
string Ball::toString() const
{
	return "Ball";
}


//#include "Cube.h" 
// Construct a default Cube object
Cube::Cube()
{
	length = 1;
}

// Construct a Cube object with specified length and height
Cube::Cube(double length)
{
	setLength(length);

}

Cube::Cube(
	double length, const string& color)
{
	setLength(length);

	setColor(color);
}

// Return the length of this Cube
double Cube::getLength() const
{
	return length;
}

// Set a new length
void Cube::setLength(double length)
{
	this->length = (length >= 0) ? length : 0;
}


// Return the area of this Cube
double Cube::getArea() const
{
	return 6 * length * length;
}

// Return the perimeter of this Cube
double Cube::getVolume() const
{
	return length*length*length;
}

// Redefine the toString function, to be covered in Section 15.5
string Cube::toString() const
{
	return "Cube";
}


//#include "GeometricObject.h"
//#include "Ball.h"
//#include "Cube.h"
#include <iostream>
#include <iomanip>
using namespace std;

void display(Ball& b,Cube& c)
{
    cout << fixed << setprecision(1);
	cout << b.toString() << endl
		<< "radius:" << b.getRadius()
		<< ",area:" << b.getArea()
		<< ",volume:" << b.getVolume()
		<< ",color:" << b.getColor() << endl;


	cout << c.toString() << endl
		<< "length:" << c.getLength()
		<< ",area:" << c.getArea()
		<< ",volume:" << c.getVolume()
		<< ",color:" << c.getColor()<<endl;
}
int main()
{
	int a, b;
	string c1, c2;
	cin >> a >> c1 >> b >> c2;

	Ball Ball(a);
	Ball.setColor(c1);
	Cube Cube(b);
	Cube.setColor(c2);
    
    display(Ball,Cube);

}
