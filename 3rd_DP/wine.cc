# include <iostream>
using namespace std;
int memo[100][100];
int ans(int arr[], int be, int en,int year)
{
    if(be>en) return 0;
    int q1= arr[be]*year + ans(arr,be+1,en,year+1);
    int q2= arr[en]*year + ans(arr,be,en-1,year+1);
    return max(q1,q2);
}

int ans_td(int arr[], int be, int en,int year)
{
    if(be>en) return 0;
    if (memo[be][en]!=-1) return memo[be][en];
    int q1= arr[be]*year + ans(arr,be+1,en,year+1);
    int q2= arr[en]*year + ans(arr,be,en-1,year+1);
    memo[be][en]= max(q1,q2);
    return memo[be][en];
}

int ans_bu()
{
    int dp[100][100]={};
}

int main()
{
    int arr[100]={1,4,2,3};
    cout << 1 << endl;
    for(int i=0;i<100;i++)
    {
        for(int j=0;j<100;j++)
        {
            memo[i][j]=-1;
        }
    }
    cout << ans_td(arr,0,3,1)<<endl;
}