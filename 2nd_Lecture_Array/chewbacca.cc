# include <iostream>
using namespace std;
int main()
{
    char c[100];
    cin >> c;
    int i=0;
    if (c[0]=='9')
    {
        i++;
    }
    for(;c[i]!='\0';i++)
    {
        int digit=c[i]-'0';
        if(digit>=5)
        {
            digit=9-digit;
        }
        c[i]=digit+'0';
    }
    cout<< c;
}