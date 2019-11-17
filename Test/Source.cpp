#include <iostream>

using namespace std;
// Class definition of Point
class Point {
public:
	Point(float x0 = 0.0, float y0 = 0.0);
	void read();
	void print();
private:
	float x;
	float y;
};

// Class definition of Circle
class Circle {
public:
	Circle(float x0 = 0.0, float y0 = 0.0,
		float r0 = 0.0);
	Circle(const Point& cp0, float r0 = 0.0);
	void read();
	void print();
private:
	float radius;
	Point centerPoint;
};

//Member function implementations
//Member functions of Point
Point::Point(float x0, float y0) {
	x = x0;
	y = y0;
}
void Point::read() {
	cout << "\n x-coordinate: ";
	cin >> x;
	cout << " y-coordinate: ";
	cin >> y;
}
void Point::print() {
	cout << "(" << x << "," << y << ")";
}

// Member functions of Circle
// Constructor 1 version 1
//Circle::Circle(float x0, float y0, float r0) : centerPoint(x0, y0) {
//	radius = r0;
//}
// Constructor 1 version 2 (Point constructor is called twice)
Circle::Circle(float x0, float y0, float r0) {
radius = r0;
centerPoint = Point(x0, y0);
}
//Constructor 2 version 1
Circle::Circle(const Point& cp0, float r0) : centerPoint(cp0) {
	radius = r0;
}
/*Constructor 2 version 2 (Point constructor is called twice)
Circle::Circle(const Point &cp0, float r0) {
radius = r0;
centerPoint = Point(cp0); //Default copy constructor of Point
} */
void Circle::read() {
	cout << "\nEnter radius : ";
	cin >> radius;
	cout << "Enter centerpoint :";
	centerPoint.read();
}
void Circle::print() {
	cout << "\nThe circle data is :";
	cout << "\nRadius is : " << radius;
	cout << "\nCenter point is :";
	centerPoint.print();
}

//Application
void main(void) {
	Point p(11.0, 12.0);
	Circle c1, c2(1.0, 2.0, 10.0),
		c3(p, 20.0);
	c1.print();
	c2.print();
	c3.print();
}