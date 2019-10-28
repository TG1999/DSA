# include <iostream>
using namespace std;

bool isSorted(int arr[],int n)
{
    if(n==1)
    {
        return true;
    }
    if(arr[n]>arr[n-1])
    {
        return 1*isSorted(arr,n-1);
    }
    else
    {
        return 0*isSorted(arr,n-1);
    }
    
}

int main()
{
    int arr[]={1,2,3,6,7,8};
    int n=6;
    cout << isSorted(arr,5);
}