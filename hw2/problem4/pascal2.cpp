// Virgil Gheorghiu
// Homework 1.3 - print Pascal's triangle 1..16

#include <iostream>
#include <iomanip>
#include <sstream>
#include <string>
#include <vector>
#include <numeric>
#include <algorithm>
//#include <cmath>
using namespace std;

#define DEFAULT_TRIANGLE_SIZE 16
#define REALLY_BIG 30

int usage (char *name)
{
	cout << name << ": compute and pretty-print Pascal's triangle." << endl;
	cout << "Usage: " << name << " <row>" << endl;
	cout << "\tWhere\t<row> is the last row to stop computing (defaults to 16)." << endl;
	return 1;
}

int main (int argc, char* argv[])
{
	unsigned int i, j, width, blanks, cur_width, pad;
	string str;
	unsigned int triangle_size = DEFAULT_TRIANGLE_SIZE;
	string read;

	vector <unsigned int> ints;
	typedef vector <unsigned int> triangle_row;
	vector <triangle_row> triangle;
	vector <unsigned int>::const_iterator jit;
	vector <unsigned int>::const_iterator largest;
	std::stringstream ss;

	if (argc == 1) triangle_size = DEFAULT_TRIANGLE_SIZE;
	else
	{
		if (argc > 2 || strcmp (argv[1], "--help") == 0) return usage (argv[0]);
		if (argc == 2)
			triangle_size = (unsigned int) atoi (argv[1]);
	}

	if (triangle_size > REALLY_BIG)
	{
		cout << "Are you sure (y/n)? ";
		cin >> read;
		if (read.compare ("n")  == 0)
			exit (0);
	}

	// initialize
	ints.push_back (1);
	triangle.push_back (ints);
	ints.clear ();

	// fill in the triangle
	for (i = 1; i < triangle_size; i++)
	{
		ints.push_back (1);
		for (j = 1; j < i; j++)
			ints.push_back (triangle [i - 1][j - 1] + triangle [i - 1][j]);
		ints.push_back (1);
		triangle.push_back (ints);
		ints.clear ();
	}

	// find the largest element's width
	ss << *(max_element (triangle[triangle_size - 1].begin(), triangle[triangle_size - 1].end()));
	str = ss.str ();
	ss.str ("");
	width = str.length();
	if (width % 2 == 0) width++;

	// Print it out
	for (i = 0; i < triangle_size; i++)
	{
		blanks = ((width + 1) * (triangle_size - 1 - i) / 2);
		cout << setw (blanks) << "";
		for (jit = triangle[i].begin(); jit != triangle[i].end(); ++jit)
		{
			ss << *jit;
			str = ss.str ();
			ss.str ("");
			cur_width = str.length ();
			pad = (width - cur_width + 1) / 2;
			cout << setfill ('.') << setw (pad) << "" << setw (cur_width) << *jit;
			if (2 * pad + cur_width <= width)
				cout << setw (pad) << "";
			else
				cout << setw (pad - 1) << "";
			cout << " ";
			cout << setfill (' ');
		}
		cout << endl;
	}

	return 0;
}
