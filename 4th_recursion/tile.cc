# include <iostream>
using namespace std;
// mXn space to be covered using 
// mX1 tiles
// how many ways to cover them
// Solution f(n)=f(n-1)+f(n-4)
// Base cases:if (n==m) then return 2  
// if(n<m) return 1
int num_of_ways(int n,int m)
{
    if(n==m)
    {
        return 2;
    }
    if(n<m)
    {
        return 1;
    }
    return num_of_ways(n-1,m) + num_of_ways(n-m,m);
}

int main()
{
    int n,m;
    cin >> m >> n;
    cout << num_of_ways(n,m);
}