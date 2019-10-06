# include <iostream>
using namespace std;
int memo[1000];
int memo_fib(int n)
{
  if(n==0) return 0;
    if(n==1) return 1;
    if(memo[n]!=-1) return memo[n];
    memo[n]= memo_fib(n-1)+memo_fib(n-2);  
    return memo[n];
}
int dp_fib(int n)
{   int dp[1000]={};
    dp[0]=0;
    dp[1]=1;
    for (int i=2;i<=n;i++)
    {
        dp[i]=dp[i-1]+dp[i-2];
    }
    return dp[n];
}
int fib(int n)
{
    if(n==0) return 0;
    if(n==1) return 1;
    return fib(n-1)+fib(n-2);
}
int main()
{
    int n;
    cin >> n;
    for(int i=0;i<1000;i++)
    {
        memo[i]=-1;
    }
    cout << dp_fib(n) << endl;
}