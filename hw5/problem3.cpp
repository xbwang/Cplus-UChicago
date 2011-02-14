class A
{
public:
    A(){}
    ~A(){}  
};

int i()
{
    return 0;
}

char* k(char *temp_a, char *temp_b)
{
    char a = 'k';
    char *b = &a;
    return b;
}
int main()
{
    //double
    double a = 1.0;
    //A *
    A* b = new A();
    //const char *
    const char *c = "c";
    //const char &
    char d = 'd';
    const char &rd = d;
    //long[7]
    long e[7] = {1,2,3,4,5,6,7};
    //int **
    int temp = 1;
    int *f_a = &temp;
    int **f_b = &f_a;
    //int *&
    int *pg = &temp;
    int *&g = pg;
    //float &
    float h = 1.0;
    float &rh = h;
    //int (*)()
    int (*pi)() = &i;
    //int (*&)()
    int (*pj)() = &i;
    int (*&j)() = pj;
    //char *(*)(char *, char *)
    char *(*pk)(char *,char *) = &k;
}