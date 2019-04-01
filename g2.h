// LABKA 2.3 v.1 class
#pragma once

class Point {
public:
	Point() = default;
	Point(const double& x, const double& y);
	Point operator = (const Point&);
	bool operator == (const Point&) const;
	bool operator != (const Point&) const;
	double getX() const;
	double getY() const;
	double distPointToPoint(const Point&) const;
private:
	double _x{ 0. };
	double _y{ 0. };
};

class DirLine {
public:
	DirLine() = default;
	DirLine(const Point&, const Point&);
	DirLine operator = (const DirLine&);
	Point getP1() const;
	Point getP2() const;
	bool getIsLine() const;
	short deviation(const Point&) const; 	// checks if the point on the left/right side or on the line
private:
	Point _p1{ 0., 0. };
	Point _p2{ 0., 0. };
	//bool signiifcant of the line
	//if 2 point are same -> it's not a line
	bool _isDirLine= false;
};

class Segment {
public:
	Segment() = default;
	Segment(const Point&, const Point&);
	Point getP1() const;
	Point getP2() const;
private:
	Point _p1{ 0., 0. };
	Point _p2{ 0., 0. };
	double _length{ 0 };
};

class Triangle {
public:
	Triangle() = default;
	Triangle(const Point&, const Point&, const Point&);
	Triangle operator = (const Triangle&);
	Point getA() const;
	Point getB() const;
	Point getC() const;
	bool getIsTriangle() const;
private:
	Point _A{ 0., 0. };
	Point _B{ 0., 0. };
	Point _C{ 0., 0. };
	//bool signiifcant of the triangle
	//if 3 point on the same line -> it's not a triangle
	bool _isTriangle = false;
};

std::istream& operator>>(std::ifstream&, Point&);
std::ostream& operator<<(std::ofstream&, Point&);

std::istream& operator>>(std::ifstream&, DirLine&);
std::ostream& operator<<(std::ofstream&, const DirLine&);

std::ostream& operator<<(std::ofstream&, const Segment&);

std::istream& operator>>(std::ifstream&, Triangle&);
std::ostream& operator<<(std::ofstream&, const Triangle&);
