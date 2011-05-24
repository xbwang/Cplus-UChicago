using namespace std;

class Numbers
{
public:
    static const int value = 0;
    template<class T> class result{};
};

template<typename T>
void test(T &num)
{
    //if the codes are written like
    //num->result < Numbers::value < 1 >;
    //the compiler wouldn't know whether it's the boolean of *Number::value < 1* as the template input of result
    //or it's the num's result comparing with Number::value<1>
    num->template result < Numbers::value < 1 >;
};

int main()
{
    return 0;
}
