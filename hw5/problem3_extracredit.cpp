class A
{
public:
    int i;
    int foo(int *x){return 0;}
    int fooX(double (*)(float &z)){return 0;}
    void fooY(void (*)()){}
};

int main()
{
    A classA;
    int m = 1;
    int *n = &m;
    //int A::*
    int A::*a = &A::i;
    classA.*a = 1;
    //int (A::*)(int *)
    int (A::*b)(int *) = &A::foo;
    //int (A::**)(int *)
    int (A::**c)(int *) = &b;
    //int (A::*&)(int *)
    int (A::*pd)(int *) = &A::foo;
    int (A::*&d)(int *) = pd;
    //int (A::*)(double (*)(float &))
    int (A::*e)(double (*)(float &)) = &A::fooX;
    //void (*p[10]) (void (*)())
}