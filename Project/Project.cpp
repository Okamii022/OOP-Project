#include "COLUMN.h"
#include "ROW.h"
#include <iostream>

int main()
{
    string test[] = { "key","board","ceva"};
    string test2[] = { "key","board","boom"};
    int noCol = 3;
    int row = 1;
    Row rowEntry(test, noCol);
    std::cout << rowEntry;
    Row rowEntry2(test2,noCol);
    std::cout << rowEntry2;
}



