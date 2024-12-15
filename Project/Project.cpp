//#include "COLUMN.h"
#include "ROW.h"
#include <iostream>

int main()
{
    string test[] = { "key","board","ceva"};
    int noCol = 3;
    int row = 1;
    Row rowEntry(row, test, noCol);
    std::cout << rowEntry;
}

