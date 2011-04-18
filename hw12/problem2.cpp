/*********************
* hw12-2
* Xiangbo Wang
* xbwang@uchicago.edu
**********************/
#include <iostream>
#include <locale>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int main( ) {

    // Create two strings, one with a German character
    string s1 = "diät";
    string s2 = "dich";

    vector<string> v;
    v.push_back(s1);
    v.push_back(s2);

    // Sort without giving a locale, which will sort according to the
    // current global locale's rules.
    sort(v.begin( ), v.end( ));
    for (vector<string>::const_iterator p = v.begin( ); p != v.end( ); ++p)
        cout << *p << endl;

    // Set the global locale to German, and then sort
    locale::global(locale("german"));

    // lambda replacement    
    sort(v.begin( ), v.end( ), [](string s1, string s2)->bool{
        return ((use_facet<collate<char> >(locale())).compare(
            s1.data(), s1.data()+s1.size(), s2.data(), s2.data()+s2.size()) < 0);
        });
    for (vector<string>::const_iterator p = v.begin( ); p != v.end( ); ++p)
        cout << *p << endl;
}