// LABKA 2.3 v.1 additional functions
#include <iostream>
#include <fstream>
#include <string>
#include "g2.h"
#include "g2use.h"

void putAboutStudent() {
	std::cout << "Laboratory work 3 - 1 Geometry on the area" << std::endl;
	std::cout << "Group: K-14 Danilchenko Alexander" << std::endl;
	std::cout << "VAR: 57 Determinates the position of line comparatively to the triangle" << std::endl;
}

std::string getFilePath(const char& ioVar) {
	std::string filePath = "";
	if (ioVar == 'i') {
		std::cout << "\nEnter the path to the input file: ";
		std::cin.clear(); //clears the stream if ^z is pushed
		getline(std::cin, filePath);
		//if the input is clear -> read information from in.txt from the root folder
		if (filePath.empty())
			filePath = "D:/Studying/Programming/LABS/Laboratory Work 2.3 v.1/Laboratory Work 2.3 v.1/in.txt";
	}
	else {
		std::cout << "\nEnter the path to the output file: ";
		std::cin.clear();
		getline(std::cin, filePath);
		//if file path is empty -> save the output to the out.txt in the root folder
		if (filePath.empty())
			filePath = "D:/Studying/Programming/LABS/Laboratory Work 2.3 v.1/Laboratory Work 2.3 v.1/out.txt";
		//if user didn't provided full adress -> create a new file in the root folder
		else if (filePath[0] != 'C' && filePath[0] != 'D' && filePath[0] != 'E' && filePath[0] != 'Z')
			filePath += ".txt";
	}
	return filePath;
}

void processData(std::ifstream& ifs, std::ofstream& ofs) {
	Triangle triangle;
	ifs >> triangle;
	// if the points in file are not representing triangle -> throw exception
	if (!(triangle.getIsTriangle()))
		throw std::logic_error("Points are not represent a triangle!");
	ofs << triangle;
	while (!(ifs.eof())) {
		DirLine tempDirLine;
		ifs >> tempDirLine;
		if (tempDirLine.getIsLine()) {
			std::string result = whereIsDirLine(triangle, tempDirLine);
			ofs << tempDirLine << " : " << result << std::endl;
		}
		else {
			Segment tempSeg(tempDirLine.getP1(), tempDirLine.getP2());
			ofs << tempSeg << " : coordinates specify zero-length segment" << std::endl;
		}
	}
}

bool isTriangle(const Point& A, const Point& B, const Point& C) {
	// formula - https://drive.google.com/open?id=18Z6FNiHCm7uyOtyxxKnPdbsm-nNU_Y_3
	// three points not create a triangle if they are located on the same line
	constexpr double eps = 1e-5;
	double checkVal = ((B.getX() - A.getX()) * (C.getY() - A.getY())) - ((B.getY() - A.getY()) * (C.getX() - A.getX()));
	if (abs(checkVal - 0.) < eps)
		return false;
	else
		return true;
}

bool isLineCrossTriangle(const Triangle& tri, const DirLine& l) {
	// formula - https://drive.google.com/open?id=1j4B5eD03fFUwgrvZqZ4C5_C0AQzl3SsO
	if ((l.deviation(tri.getA()) > 0 && l.deviation(tri.getB()) < 0) || (l.deviation(tri.getA()) < 0 && l.deviation(tri.getB()) > 0) ||
		(l.deviation(tri.getB()) > 0 && l.deviation(tri.getC()) < 0) || (l.deviation(tri.getB()) < 0 && l.deviation(tri.getC()) > 0) ||
		(l.deviation(tri.getA()) > 0 && l.deviation(tri.getC()) < 0) || (l.deviation(tri.getA()) < 0 && l.deviation(tri.getC()) > 0))
		return true;
	else
		return false;
}

std::string whereIsDirLine(const Triangle& tri, const DirLine& l) {
	Point triVertex[3] = { tri.getA(), tri.getB(), tri.getC() };
	size_t pBelToLine = 0; // amount of points, which belogns to DirLine
	for (size_t i = 0; i < 3; ++i)
		if (l.deviation(triVertex[i]) == 0)
			++pBelToLine;
	if (pBelToLine == 1)
		return "line has one common point with the triangle";
	else if (pBelToLine == 2)
		return "segment of the triangle belongs to line";
	else if (isLineCrossTriangle(tri, l))
		return "line crosses the triangle";
	else
		return "line has no common points with the triangle";
}
