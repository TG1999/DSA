# include <iostream>
using namespace std;
int main()
{
    int x=10;
    int y=10;
    cout <<&y << endl;
    // it does not work with char variables
    char ch='A';
    cout <<&ch;
    //Explicit Typecasting
    cout << (void *)&ch <<endl;
    int *xptr=&x;
    // here xptr has address and *(xptr) means print the bucket stored at that address 
    // int *xptr=&x means int *xptr; then xptr=&x; so xptr has address and *(xptr)
    cout << xptr<<endl;// Address of xptr
    cout << &x;//Address 
}