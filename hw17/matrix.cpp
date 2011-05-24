/*********************
* hw17-1
* Xiangbo Wang
* xbwang@uchicago.edu
**********************/
#include <iostream>
#include <sstream>
#include <algorithm>
#include <iomanip>
#include <numeric>
#include <boost/progress.hpp>
using namespace std;

// g++ on Cygwin appears to define a macro named "minor"
// This helps illustrate why namespaces are good and macros are bad
#undef minor 

template<int h, int w = h>
class IntegerMatrix {
public:
    int &operator()(int x, int y) {
        return data[x][y];
    }

    int operator()(int x, int y) const {
        return data[x][y];
    }

    inline IntegerMatrix();

    template<class charT, class Traits>
    inline friend
    basic_ostream<charT, Traits> &
    operator<<
      (basic_ostream<charT, Traits> &os, const IntegerMatrix<h, w> &m) {
        size_t width = m.longestElementSize() + 2;
        os << "[ " << endl;
        for(int i = 0; i < h; i++) {
            for(int j = 0; j < w; j++) {
                os << setw(static_cast<streamsize>(width)) << m(i, j);
            }
            os << endl;
        }
        os << "]" << endl;
        return os;
    }
    IntegerMatrix<h-1, w-1> minor(int r, int c) const {
        IntegerMatrix<h-1, w-1> result;
        for(int i = 0; i < h; i++) {
            if (i == r) {
                continue;
            }
            for(int j = 0; j < w; j++) {
                if(j == c) {
                    continue;
                }
                result(i < r ? i : i - 1, j < c ? j : j - 1) = data[i][j];
            }
        }
        return result;
    }
    int determinant() const {
	    //problem1
	    //method1
        static_assert(h == w, "determinant should be taken on square matrix");
        int val = 0;
        for(int i = 0; i < h; i++) {
            val += (i % 2 ? -1 : 1)
                   * data[i][0]
                   * minor(i, 0).determinant();
        }
        return val;
    }
private:
    int data[h][w];
    static size_t accumulateMax(size_t acc, int i) {
        ostringstream ostr;
        ostr << i;
        return max(acc, ostr.str().size());
    }
    size_t longestElementSize() const {
        const int *ip = &data[0][0];
        return accumulate(ip, ip + h*w, 0, accumulateMax);
    }
};

template<>
int
IntegerMatrix<1,1>::determinant() const
{
    return data[0][0];
}

template<int h, int w>
IntegerMatrix<h,w>::IntegerMatrix() 
{
    // Why not a memset?
    int *ip = &data[0][0];
    fill(ip, ip + h*w, 0);
}

int
main()
{
    boost::progress_timer howlong;

    IntegerMatrix<2, 2> m;
    m(0, 0) = 1;
    m(0, 1) = 2;
    m(1, 0) = 3;
    m(1, 1) = 4;
    static int total;
    for(int i = 0; i < 1000000; i++) {
        m(1,1) = i;
        total += m.determinant();
    }

    IntegerMatrix<1,2> test;
    cout << test.determinant() << endl;
}
