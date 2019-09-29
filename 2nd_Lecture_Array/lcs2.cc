# include <iostream>
using namespace std;
int main()
{   //Naive Solution with N^3 complexity
    // Algorithm used
    //1) Find a cummulative sum array using cumsum[i]=cumsum[i-1] + arr[i] here if i=0 then cumsum[i]=arr[0]
    //2) Using two nested loops 
    //3) One (i) going from 0 to n-1 then other(j) going from i to n-1 
    //4) then use i,j in this way to get sum from i to j cusrum=cumsum[j]-cumsum[i-1] and if i=0 then cursum=cumsum[j]
    //5) then give the maximum as answer :)
    int arr[10];
    int n ;
    cin >> n;
    for (int i=0;i<n;i++)
    {
        cin>> arr[i];
    }
    int cumsum[10];
    for (int i=0;i<n;i++)
    {
        if (i==0)
        {
            cumsum[i]=arr[i];
        }
        else
        {
            cumsum[i]=cumsum[i-1]+arr[i];
        }
    }
    // for(int i=0;i<n;i++)
    // {
    //     cout << cumsum[i]<<endl;
    // }
    int maxsum=0;
    int cursum=0;
    for (int i=0;i<n;i++)
    {   
        for(int j=i;j<n;j++)
        {   cursum=0; 
            if(i==0)
            {
                cursum=cumsum[j];
            }   
            else
            {
             cursum=cumsum[j]-cumsum[i-1];
            }
            if(cursum>maxsum)
        {
            maxsum=cursum;
        }
        }
        
    }
    cout << maxsum;
}