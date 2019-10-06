# include <iostream>
using namespace std;
const int inf=(int)1e9;
int memo[1000]={};
int reduce_recusrion(int n)
{   
    if(n==0||n==1) return 0;
    if(memo[n]!=-1) return memo[n];
    int q1=inf;
    int q2=inf;
    int q3=inf;
    if(n%3==0) q1=1+reduce_recusrion(n/3);
    if(n%2==0) q2=1+reduce_recusrion(n/2);
    q3=1+reduce_recusrion(n-1);
    memo[n] = min(q1,min(q2,q3));
    return memo[n];
}
int reduce(int n)
{   int dp[1000]={};
    dp[0]=0;
    dp[1]=0;
    dp[2]=1;
    dp[3]=1;
    for(int i=4;i<=n;i++)
    {   int q1=inf;
    int q2=inf;
    int q3=inf;
        if(i%3==0) q1=1+dp[i/3];
        if(i%2==0) q2=1+dp[i/2];
        q3=1+dp[i-1];
        dp[i]=min(q1,min(q2,q3));
    }
    return dp[n];
}
int main()
{
    int n;
    cin >> n;
    for(int i=0;i<1000;i++)
{
    memo[i]=-1;
}
    cout<<reduce_recusrion(n)<<endl;
    cout<<reduce(n);
    
}