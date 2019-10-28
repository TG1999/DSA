# include <iostream>
using namespace std;

int fast(int a, int b)
{
    if(b==0)
    {
        return 1;
    }
    if(b%2==0)
    {
        int ans=fast(a,b/2);
        return ans*ans;
    }
    else
    {
        int ans=fast(a,b/2);
        return a*ans*ans;
    }
    
}

int main()
{
    int a;
    int b;
    cin >> a >> b;
cout << fast(a,b);
}