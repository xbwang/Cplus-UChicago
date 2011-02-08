// Frame.cpp : Defines the entry point for the console application.
//

#include <iostream>
#include <string>
using std::cin;
using std::cout;
using std::endl;
using std::string;

int main()
{
    cout << "What's your name? ";
    string name;
    cin >> name;

    // The message we intende to write
    const string greeting = "Hello, " + name + "!";

    // The number of blanks surrounding the greeting
    const int pad = 1;

    // Rows and columns to write
    const int rows = pad*2 + 3;
    const string::size_type cols = greeting.size() + pad*2 + 2;

    cout << endl;

    for(int r = 0; r != rows; ++r) {
        // How many characters we have written in the row
        string::size_type c = 0;
        while (c != cols) {
            if (r == pad + 1 && c == pad + 1) {
                cout << greeting;
                c += greeting.size();
            } else {
                // On the border?
                if(r == 0 || r == rows - 1
                   || c == 0 || c == cols - 1) {
                    cout << "*";
                } else {
                    cout << " ";
                }
                ++c;
            }
        }
        cout << endl;
    }
	return 0;
}

