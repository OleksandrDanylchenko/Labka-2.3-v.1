// LABKA 2.3 v.1 additional functions
#pragma once

void putAboutStudent();
std::string getFilePath(const char&);
void processData(std::ifstream&, std::ofstream&);
std::string whereIsDirLine(const Triangle&, const DirLine&);
bool isTriangle(const Point&, const Point&, const Point&);
bool isLineCrossTriangle(const Triangle&, const DirLine&);