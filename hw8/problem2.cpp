#include <iostream>
using namespace std;

template<class T>
class Complex
{
public:
    Complex() {}
    Complex(T r, T i) : real(r), image(i) {}
    
    template<class U>
    inline friend Complex<U> operator+(const Complex<U> &a, const Complex<U> &b);
    template<class U>
    inline friend Complex<U> operator*(const Complex<U> &a, const Complex<U> &b);
    inline void operator+=(const Complex<T> &b){
        real = real+b.real;
        image = image+b.image;
    }
    inline void operator*=(const Complex<T> &b){
        real = real*b.real - image*b.image;
        image = image*b.real + real*b.image;
    }
    
    template<class charT, class Traits>
    inline friend basic_ostream<charT, Traits> &
    operator<<
        (basic_ostream<charT, Traits> &os, const Complex<T> &num){
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
    T real,image;   
};

template<class U>
Complex<U> operator+(const Complex<U> &a, const Complex<U> &b)
{
    Complex<U> result;
    result.real = a.real + b.real;
    result.image = a.image + b.image;
    return result;
}

template<class U>
Complex<U> operator*(const Complex<U> &a, const Complex<U> &b)
{
    Complex<U> result;
    result.real = a.real*b.real - a.image*b.image;
    result.image = a.image*b.real + a.real*b.image;
    return result;
}

int main()
{
    
    Complex<int> a1(1,2), b1(2,3);
    cout << "- complex<int> number<a1>: " << a1 << endl;
    cout << "- complex<int> number<b1>: " << b1 << endl;
    cout << "- sum: " << a1+b1 << endl;
    cout << "- multiplcation: " << a1*b1 << endl;
    a1+=b1;
    cout << "- a+=b: " << a1 << endl;
    a1*=b1;
    cout << "- a*=b: " << a1 << endl;

    Complex<float> a2(1.1,1.2), b2(2.1,2.2);
    cout << "- complex<float> number<a2>: " << a2 << endl;
    cout << "- complex<float> number<b2>: " << b2 << endl;
    cout << "- sum: " << a2+b2 << endl;
    cout << "- multiplcation: " << a2*b2 << endl;
    a2+=b2;
    cout << "- a+=b: " << a2 << endl;
    a2*=b2;
    cout << "- a*=b: " << a2 << endl;
    return 0;
}