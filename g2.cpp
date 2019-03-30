// LABKA 2.3 v.1 class implementation
#include <iostream>
#include <fstream>
#include <algorithm>
#include <string>
#include "g2.h"
#include "g2use.h"

// CONSTRUCTORS
Point::Point(const double& x, const double& y) : _x{ x }, _y{ y } {}
DirLine::DirLine(const Point& p1, const Point& p2) : _p1{ p1 }, _p2{p2} {
	if (_p1 != _p2)
		_isDirLine = true;
}
Segment::Segment(const Point& p1, const Point& p2) : _p1{ p1 }, _p2{ p2 } {
	if (_p1 != _p2)
		_length = _p1.distPointToPoint(_p2);
}
Triangle::Triangle(const Point& A, const Point& B, const Point& C) {
	if (isTriangle(A, B, C)) {
		_A = A;
		_B = B;
		_C = C;
		_isTriangle = true;
	}
}

// OPERATORS
std::istream& operator>>(std::ifstream& ifs, Point& p) {
	double tempX, tempY;
	ifs >> tempX >> tempY;
	Point tempP(tempX, tempY);
	p = tempP;
	return ifs;
}
std::istream& operator>>(std::ifstream& ifs, DirLine& l) {
	Point tempP1, tempP2;
	ifs >> tempP1;
	ifs >> tempP2;
	DirLine tempDirLine(tempP1, tempP2);
	l = tempDirLine;
	return ifs;
}
std::istream& operator>>(std::ifstream& ifs, Triangle& tri) {
	Point tempP1, tempP2, tempP3;
	ifs >> tempP1;
	ifs >> tempP2;
	ifs >> tempP3;
	Triangle tempTriangle(tempP1, tempP2, tempP3);
	tri = tempTriangle;
	return ifs;
}
std::ostream& operator<<(std::ofstream& ofs, Point& p) {
	ofs << '(' << p.getX() << ", " << p.getY() << ')';
	return ofs;
}
std::ostream& operator<<(std::ofstream& ofs, const DirLine& l) {
	Point tP1 = l.getP1();
	Point tP2 = l.getP2();
	ofs << tP1;
	ofs << " ; ";
	ofs << tP2;
	return ofs;
}
std::ostream& operator<<(std::ofstream& ofs, const Segment& seg) {
	Point segP1 = seg.getP1();
	Point segP2 = seg.getP2();
	ofs << segP1;
	ofs << " ; ";
	ofs << segP2;
	return ofs;
}
std::ostream& operator<<(std::ofstream& ofs, const Triangle& tri) {
	Point a = tri.getA();
	Point b = tri.getB();
	Point c = tri.getC();
	ofs << "Triangle: ";
	ofs << a;
	ofs << " ; ";
	ofs << b;
	ofs << " ; ";
	ofs << c;
	ofs << " ; ";
	ofs << std::endl;
	return ofs;
}

Point Point::operator=(const Point& otherPoint) {
	_x = otherPoint._x;
	_y = otherPoint._y;
	return *this;
}
bool Point::operator==(const Point& otherPoint) const { 
	return (_x == otherPoint._x && _y == otherPoint._y); 
}
bool Point::operator!=(const Point & otherPoint) const {
	return (_x != otherPoint._x || _y != otherPoint._y); 
}
DirLine DirLine::operator=(const DirLine& lin) {
	_p1 = lin._p1;
	_p2 = lin._p2;
	_isDirLine = lin._isDirLine;
	return *this;
}
Triangle Triangle::operator=(const Triangle& tri) {
	_A = tri._A;
	_B = tri._B;
	_C = tri._C;
	_isTriangle = tri._isTriangle;
	return *this;
}

// METHODS
double Point::getX() const { return _x; }
double Point::getY() const { return _y; }

Point DirLine::getP1() const { return _p1; }
Point DirLine::getP2() const { return _p2; }
bool DirLine::getIsLine() const { return _isDirLine; }
short DirLine::deviation(const Point& p) const {
	// pseudoscalar composition
	double checkVal = (_p2.getX() - _p1.getX()) * (p.getY() - _p1.getY()) -  (p.getX() - _p1.getX()) * (_p2.getY() - _p1.getY());
	constexpr double eps = 1e-1;
	if (abs(checkVal - 0.) < eps) // on line
		return 0;
	else if (checkVal > 0) // over line
		return 1;
	else // under line
		return -1;
}	

Point Segment::getP1() const { return _p1; }
Point Segment::getP2() const { return _p2; }

Point Triangle::getA() const { return _A; }
Point Triangle::getB() const { return _B; };
Point Triangle::getC() const { return _C; };
bool Triangle::getIsTriangle() const { return _isTriangle; }


double Point::distPointToPoint(const Point& otherPoint) const {
	//formula - https://drive.google.com/open?id=1qqhEAy6ZMNQm5wH8REvXU4_cxcqebK-v
	return sqrt(pow(_x - otherPoint.getX(), 2.) + pow(_y - otherPoint.getY(), 2.));
}
