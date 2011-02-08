#include <boost/tokenizer.hpp>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
using namespace boost;

class node{
    private:
        string dir;
        size_t split;
        vector<string> vec;
    public:
        node(string str_in){
            dir = str_in;
        }
        void print(){
            split = dir.find_last_of("/");
            vec.push_back(dir.substr(split+1));
            while(dir != "."){
                dir = dir.substr(0, split);
                split = dir.find_last_of("/");
                vec.insert(vec.begin(), "  ");
            }
            copy(vec.begin(), vec.end(), ostream_iterator<string>(cout, ""));
            cout << endl;
        }
};

int main(int argc, char** argv)
{
    *argv = *argv++;    //drop the first argument which is the program itself
    
    for(; *argv != NULL; *argv++){
        string s = *argv;
        tokenizer<escaped_list_separator<char> > tok(s);
        tokenizer<escaped_list_separator<char> >::iterator it;
        for(it = tok.begin(); it !=tok.end(); ++it){
            node *dir = new node(*it);
            dir->print();
        }
    }
    
    return 0;
}