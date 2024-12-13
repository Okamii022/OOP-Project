#pragma once
#include <iostream>
#include <string>

class Row {
private:
	int rowNumber;
	std::string* value; //dynamic array for storing each value
	int columnNumber; //will be used for the dynamic array

public:
	Row(int rowNumber, std::string value, int columnNumber) :rowNumber(rowNumber), columnNumber(columnNumber)
	{
		//copy for dynamic field to be added (does it belong here though?)
	}

	Row(int colCount) {
	
	}

	~Row()
	{
		delete[] value;
	}
};