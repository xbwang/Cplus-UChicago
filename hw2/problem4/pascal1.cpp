#include <vector>
#include <iostream>
#include <string>
#include <iomanip>
#include <algorithm>
#include <sstream>
using namespace std;

typedef vector<int> Row;
typedef vector<Row> Triangle;

Row
nextRow(Row row)
{
    Row result;
    int previous = 0;
    for (Row::iterator it = row.begin(); it != row.end(); it++) {
        result.push_back(previous + *it);
        previous = *it;
    }
    result.push_back(previous);
    return result;
}

const int size = 16;

int numDigits(int i)
{
	ostringstream os;
	os << i;
	return os.str().size();
}
/*
int
numDigits(int i)
{
    int digits = 1;
    while((i/=10) != 0) {
        digits++;
    }
    return digits;
}
*/
int eltSize;

void
printRow(Row row)
{
    for(Row::iterator it = row.begin(); it != row.end(); it++) {
        cout << setw(eltSize) << *it << " ";
    }
    cout << endl;
}

void
printTriangle(Triangle triangle)
{
    Row lastRow = triangle[size - 1];
    int maxElement = *max_element(lastRow.begin(), lastRow.end());
    eltSize = numDigits(maxElement);
    for(int i = 0; i < size; i++) {
        string spaces((size - i - 1) * eltSize / 2, ' ');
        cout << spaces;
        printRow(triangle[i]);
    }
}


int
main()
{
    Triangle triangle;
    Row previousRow;
    previousRow.push_back(1);
    for(int i = 0; i < size; i++) {
        triangle.push_back(previousRow);
        previousRow = nextRow(previousRow);
    }
    printTriangle(triangle);
    return 0;
}