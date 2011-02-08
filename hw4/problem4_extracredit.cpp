/************************************
* Final Version
* Xiangbo Wang / xbwang@uchicago.edu
* Problem4, extra credit
************************************/
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

struct maxlenftn
{
    maxlenftn() { maxlen = 0; }
    void operator() (string s){
        maxlen = max (maxlen, s.size());
    }
    string::size_type maxlen;
};

int main()
{
    const char *na[] = {
        "Spertus", "Lemon", "Golden", "Melhus"
    };
    vector<string> names(na, na+sizeof(na)/sizeof(const char*));
    maxlenftn maxf;
    //the problem here is that the last argument of
    //for_each is passed by value, so the result needs
    //to be captured after for_each returns
    maxf = for_each(names.begin(), names.end(), maxf);  
    cout << maxf.maxlen << endl;
    return 0;
}