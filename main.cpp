// LABKA 2.3 v.1
#include <iostream>
#include <Windows.h>
#include <fstream>
#include "g2.h"
#include "g2use.h"

int main() {
	//opens terminal in fullscreen mode
	system("mode con COLS=700");
	ShowWindow(GetConsoleWindow(), SW_MAXIMIZE);
	SendMessage(GetConsoleWindow(), WM_SYSKEYDOWN, VK_RETURN, 0x20000000);

	putAboutStudent();

	std::ifstream inputFile;
	while (true) {
		std::string inputFilePath = getFilePath('i');
		inputFile.open(inputFilePath, std::ios_base::in);
		if (inputFile.fail())
			inputFilePath.clear();
		else
			break;
	}
	
	std::ofstream outputFile;
	while (true) {
		std::string outputFilePath = getFilePath('o');
		outputFile.open(outputFilePath, std::ios_base::out);
		if (outputFile.fail())
			outputFilePath.clear();
		else
			break;
	}
	try { processData(inputFile, outputFile); }
	catch (std::exception & ex) {
		std::cerr << "\n\t" << ex.what() << std::endl << std::endl;
		system("pause");
		return -1;
	}
	system("pause");
	return 0;
}
