#pragma once

#include<iostream>
#include<string>

class Column {
private:
	std::string columnName = ""; //name of the column
	std::string columnType = ""; // type of the column, integer, float or text
	int size = 0; //the size of the data associated to each column
	std::string defaultValue = ""; // default value if no value is added
	bool isPrimaryKey = false; //is the column a primary key or not
	bool isForeignKey = false; //is the column a foreign key or not

};