# include <iostream>
using namespace std;
int main()
{   //Naive Solution with N^3 complexity
    // Algorithm used
    //1) Find all the sub arrays
    //2) Using three nested loops 
    //3) One (i) going from 0 to n-1 then other(j) going from i to n-1 then one(k) going from i to j
    //4) Pick the subarray with greatest sum :)
    int arr[10];
    int n;
    cin >> n;
    int maxsum=0;
    int left=0;
    int right=0;
    for (int i=0;i<n;i++)
    {
        cin >> arr[i];
    }
    for ( int i=0;i<n;i++)
    {
        for (int j=i;j<n;j++)
        {int cursum=0;
            for(int k=i;k<=j;k++)
            {
                cursum=cursum+arr[k];
            }
        if (cursum>maxsum)
        {   cout << cursum << endl;
            maxsum=cursum;
            left=i;
            right=j;
        }    
        }
    }
    for (int i=left;i<=right;i++)
    {
        cout<<arr[i];
    }
}