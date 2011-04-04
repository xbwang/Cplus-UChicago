#include <iostream>
#include <vector>
#include <iterator>
#include <iomanip>
using namespace std;

int main()
{
    vector<int> hexNumbers;
    hexNumbers.reserve(10*sizeof(int));
    cout << "- decimal numbers: ";
    for(int i = 0;i < 10;i++){
        hexNumbers.push_back(5+i*50);
        cout << 5+i*50 << " ";
    }
    cout << endl;
    
    vector<int>::iterator it;
    cout << "- hex numbers: ";
    for(it = hexNumbers.begin();it != hexNumbers.end();it++){
        cout << setfill('0') << setw(2) << hex << *it << " ";
    }
    cout << endl;
    
    return 0;
}
//If the entry is greater than 255, it will output the full length of the hex number.