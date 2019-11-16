# include <iostream>
using namespace std;


int counter=0;

void solve(int arr[],int i,int n,int op[],int j)
{
    if(i==n)
    {
        for(int x=0;x<j;x++)
        {
        cout << op[x] <<" ";
        }
        cout << endl;
        counter = counter +1;
        return;
    }
    op[j]=arr[i];
    solve(arr,i+1,n,op,j+1);
    
    solve(arr,i+1,n,op,j);
}

int main()
{
int arr[10000]={2,1,3};
int op[10000];
int ans[100][100];
solve(arr,0,3,op,0);
}