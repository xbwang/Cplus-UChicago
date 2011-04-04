/***************************
* Xiangbo Wang
* Homework8 Final Submission
* 2011/03/07
****************************/
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

template<class T, int h, int w = h>
class Matrix {
public:
    T &operator()(int x, int y) {
        return data[x][y];
    }

    T operator()(int x, int y) const {
        return data[x][y];
    }

    inline Matrix();

    template<class charT, class Traits>
    inline friend
    basic_ostream<charT, Traits> &
    operator<<
      (basic_ostream<charT, Traits> &os, const Matrix<T, h, w> &m) {
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
    Matrix<T, h-1, w-1> minor(int r, int c) const {
        Matrix<T, h-1, w-1> result;
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
    // Defer the definition until further below to avoid
    // problems with forward references
    T determinant() const;
private:
    T data[h][w];
    static size_t accumulateMax(size_t acc, T i) {
        ostringstream ostr;
        ostr << i;
        return max(acc, ostr.str().size());
    }
    size_t longestElementSize() const {
        const T *ip = &data[0][0];
        return accumulate(ip, ip + h*w, 0, accumulateMax);
    }
};

template<typename T, int h, int w>
Matrix<T,h,w>::Matrix() 
{
    // Why not a memset?
    T *ip = &data[0][0];
    fill(ip, ip + h*w, 0);
}


template<class T, int h, int w>
T
determinant(const Matrix<T, h, w> &m)
{
    T val = 0;
    for(int i = 0; i < h; i++) {
        val += (i % 2 ? -1 : 1) * m(i, 0) * m.minor(i, 0).determinant();
    }
    return val;
}
//problem3.3
template<class T>
T
determinant(const Matrix<T, 2, 2> &m)
{
    return (m(0,0)*m(1,1)-m(1,0)*m(0,1));
}
/*
//original code
template<class T>
T
determinant(const Matrix<T, 1, 1> &m)
{
    return m(0,0);
}
*/
template<class T, int h, int w>
T
Matrix<T,h,w>::determinant() const 
{
    return ::determinant(*this);
}

int
main()
{
    boost::progress_timer howlong;

    Matrix<double, 2, 2> m;
    m(0, 0) = 1;
    m(0, 1) = 2;
    m(1, 0) = 3;
    m(1, 1) = 4;
    cout << "Determinant " << m.determinant() << endl;
    static double total;
    for(int i = 0; i < 1000000; i++) {
        m(1,1) = i;
        total += m.determinant();
    }
/*3x3 matrix test
    Matrix<double, 3, 3> m;
    m(0, 0) = 1;
    m(0, 1) = 2.1;
    m(0, 2) = 3.1;
    m(1, 0) = 3.2;
    m(1, 1) = 4.3;
    m(1, 2) = 3.5;
    m(2, 0) = 3.1;
    m(2, 1) = 3.2;
    m(2, 2) = 3.3;
    cout << "determinant " << m.determinant() << endl;
    static double total;
    for(int i = 0; i < 1000000; i++) {
        m(1,1) = i;
        total += m.determinant();
    }
*/
}