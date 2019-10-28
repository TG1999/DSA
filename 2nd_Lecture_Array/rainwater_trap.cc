// Solution
// First find the left max and right max height for each element
// Then take element and subtract it's height from the min of left max and right max of that element 
// If it's greater than 0 add it in the total
# include <iostream>
using namespace std;
int main()
{
    int n;
    cin >> n;
    int arr[1000];
    for(int i=0;i<n;i++)
    {
        cin >> arr[i];
    }
    int left[1000];
    int right[1000];
    int cur_max_left=arr[0];
    for(int i=0;i<n;i++)
    {   if(arr[i]>cur_max_left)
    {
        cur_max_left=arr[i];
    }
        left[i]=cur_max_left;
    }
    int cur_max_right=arr[n-1];
    for(int i=n-1;i>=0;i--)
    {   if(arr[i]>cur_max_right)
    {
        cur_max_right=arr[i];
    }
        right[i]=cur_max_right;
    }
    int total=0;
    for(int i=0;i<n;i++)
    {   cout << left[i] <<'\t'<< right [i] <<'\t' <<arr[i]<<endl;
        cout << min(left[i],right[i])-arr[i]<<endl;
        if (min(left[i],right[i])-arr[i]>0)
        total=total+min(left[i],right[i])-arr[i];
    }
    cout << total;
}