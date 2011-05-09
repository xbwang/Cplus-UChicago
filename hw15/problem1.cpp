/*********************
* hw15-1
* Xiangbo Wang
* xbwang@uchicago.edu
**********************/
#include "Tuple3.h"
#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
using namespace cspp51055;
using namespace std;
using std::basic_string;
using std::basic_istream;


Tuple3<TYPELIST_3(bool,string,int)>
readLine(istream &input)
{
    Tuple3<TYPELIST_3(bool, string, int)> info;
    
    info.at<int>() = 0;
    info.at<string>() = "";
    info.at<bool>() = false;
    
    char getch;
    while(!input.eof()){
        input.get(getch);
        if(getch == '\n' || input.eof()){
            if(input.eof()){
                info.at<bool>() = true;
            }
            break;
        }
        info.at<string>() += getch;
        info.at<int>()++;
    }
    
    return info;
}

template<class U>
Tuple3<TYPELIST_3(bool,string,int)>
readLine_ec(basic_istream<U> &input)
{
    Tuple3<TYPELIST_3(bool,string,int)> info;
    
    info.at<int>() = 0;
    info.at<string>() = "";
    info.at<bool>() = false;
    
    char getch;
    while(!input.eof()){
        input.get(getch);
        if(getch == '\n' || input.eof()){
            if(input.eof()){
                info.at<bool>() = true;
            }
            break;
        }
        info.at<string>() += getch;
        info.at<int>()++;
    }
    
    return info;
}

int main()
{
    //i use a ifstream to test my function since it's easy to make the input
    //ifstream is in istream so it should work also

    ifstream myfile("test.txt");
    
    Tuple3<TYPELIST_3(bool, string, int)> curStat;
    
    while(!curStat.at<bool>()){
        curStat = readLine(myfile);
        cout << "- characters read: " << curStat.at<int>() << endl;
        cout << "- content read: " << curStat.at<string>() << endl;
    }
    myfile.close();

    //part of extra credit
    cout << "**********************" << endl;
    ifstream myfile_ec("test.txt");
    
    Tuple3<TYPELIST_3(bool, string, int)> curStat_ec;
    while(!curStat_ec.at<bool>()){
        curStat_ec = readLine_ec(myfile_ec);
        cout << "- characters read: " << curStat_ec.at<int>() << endl;
        cout << "- content read: " << curStat_ec.at<string>() << endl;
    }
    myfile_ec.close();
    return 0;
}