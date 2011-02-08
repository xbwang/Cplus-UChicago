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
    const string mixed = "* " + string(greeting.size(), ' ') + " *";
    const string stars = string(mixed.size(), '*');

    cout << endl;
    cout << stars << endl << mixed << endl;
    cout << "* " << greeting << " *" << endl;
    cout << mixed << endl << stars << endl;
    
	return 0;
}

