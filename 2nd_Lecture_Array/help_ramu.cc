# include <iostream>
using namespace std;
int main()
{   int t;
cin >> t;
while (t--)
{
    int c1,c2,c3,c4;
    cin >>c1>>c2>>c3>>c4;    
    int m,n;
    cin >> m;
    cin >> n;
    int rickshaw[1000],cab[1000];
    for(int i=0;i<m;i++)
    {
        cin >> rickshaw[i];
    }
    for(int i=0;i<n;i++)
    {
        cin >> cab[i];
    }
    int rickcost=0;
    for (int i=0;i<m;i++)
    {
        rickcost=rickcost+min(rickshaw[i]*c1,c2);
    }
    rickcost=min(rickcost,c3);
    int cabcost=0;
    for (int i=0;i<n;i++)
    {
        cabcost=cabcost+min(cab[i]*c1,c2);
    }
    cabcost=min(cabcost,c3);
    cout << min(c4,cabcost+rickcost);
}

    
}