#pragma once

#include <iostream>
#include <string>
#include <string.h>

class SELECT {
	std::string tableName;		// Name of the table to query
	std::string* columnName;	// Columns to select
	int noOfColumns;			// Number of columns
	std::string whereColumn;	// Column used in the WHERE clause
	std::string whereValue;		// Value used in the WHERE clause
	// to add: bool isWhereTrue (maybe)

};