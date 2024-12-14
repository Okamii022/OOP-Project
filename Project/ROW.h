#pragma once
#include <iostream>
#include <string>

class Row {
private:
	int rowNumber;
	std::string* value; //dynamic array for storing each value
	int columnNumber; //will be used for the dynamic array

public:
	//add the initializer list in the cpp file tomorrow(or tonight later)
	Row(int rowNumber, std::string value, int columnNumber);
	//same here
	Row(int colCount);

	~Row();
};