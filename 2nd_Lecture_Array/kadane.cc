# include <iostream>
using namespace std;
int main()
{   
    //Take two variables maxsum and cursum equal to 0
    //Add element to cursum 
    // if cursum gets less than 0
    // cursum=0
    // then choose max element from cursum and maxsum
    int arr[100];
    int n;
    cin >> n;
    int maxsum=0;
    int cursum=maxsum;
    for(int i=0;i<n;i++)
    {
        cin >> arr[i];
    }
    for(int i=0;i<n;i++)
    {
        cursum=cursum+arr[i];
        if(cursum<0)
        {
            cursum=0;
        }
        maxsum=max(maxsum,cursum);
    }
    cout << maxsum;
}