/*********************
* hw12-1
* Xiangbo Wang
* xbwang@uchicago.edu
**********************/
#include <iostream>
#include <locale>
using namespace std;

int main()
{
    /*early submission version
    locale loc = locale();
    if(isalpha('_', loc)){
        cout << "- \"_\" is an alphabetic in the current locale." << endl;
    }else{
        cout << "- \"_\" is not an alphabetic in the current locale." << endl;
    }
    */
    
    if((use_facet<ctype<char> >(locale())).is(ctype_base::alpha, '_')){
        cout << "- \"_\" is an alphabetic in the current locale." << endl;
    }else{
        cout << "- \"_\" is not an alphabetic in the current locale." << endl;
    }
    return 0;
}