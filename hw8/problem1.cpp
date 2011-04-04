/***************************
* Xiangbo Wang
* Homework8 Final Submission
* 2011/03/05
****************************/
#include <iostream>
using namespace std;

class ComplexInt
{
public:
    ComplexInt() { image=0; real=0; }
    ComplexInt(int r, int i) : image(i), real(r) {}

    /* @GC: inline operator methods. make global n friend */
    inline friend ComplexInt operator+(const ComplexInt &a, const ComplexInt &b);
    inline friend ComplexInt operator*(const ComplexInt &a, const ComplexInt &b);
    //the +=/*= need to update the original value, so it can't be a friend method
    inline void operator+=(const ComplexInt &b){
        real = real+b.real;
        image = image+b.image;
    }
    inline void operator*=(const ComplexInt &b){
        real = real*b.real - image*b.image;
        image = image*b.real + real*b.image;
    }
    
    template<class charT, class Traits>
    inline friend
    basic_ostream<charT, Traits> &
    operator<<
      (basic_ostream<charT, Traits> &os, const ComplexInt &num) {
        if(num.image > 0){
            os << num.real << "+" << num.image << "i";
        }else if(num.image == 0){
            os << num.real;
        }else{
            os << num.real << num.image << "i";
        }
        return os;
    }
private:
    int real, image;
};

ComplexInt operator+(const ComplexInt &a, const ComplexInt &b)
{
        ComplexInt result;
        result.image = a.image + b.image;
        result.real = a.real + b.real;
        return result;
}

ComplexInt operator*(const ComplexInt &a, const ComplexInt &b)
{
        ComplexInt result;
        result.real = a.real*b.real - a.image*b.image;
        result.image = a.image*b.real + a.real*b.image;
        return result;
}

int main()
{
    ComplexInt a(1,2), b(2,3), c;
    cout << "- complex number<a>: " << a << endl;
    cout << "- complex number<b>: " << b << endl;
    cout << "- sum: " << a+b << endl;
    cout << "- multiplcation: " << a*b << endl;
    a+=b;
    cout << "- a+=b: " << a << endl;
    a*=b;
    cout << "- a*=b: " << a << endl;
    return 0;
}
