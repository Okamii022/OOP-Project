#pragma once

#include<iostream>
#include<string>

class Column {
private:
	std::string columnName = ""; //name of the column
	std::string columnType = ""; // type of the column, integer, float or text
	int size = 0;
	std::string defaultValue = "";
	bool isPrimaryKey = false;
	bool isForeignKey = false;


};