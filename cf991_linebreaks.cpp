#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        long long n,m;
        cin>>n;
        cin>>m;
        vector<string>a(n);
        for(int i=0;i<n;i++)
        {
            cin>>a[i];
        }
        long long x=0;
        for(int i=0;i<n;i++)
        {
            if(a[i].size()<=m)
            {
                x++;
                m-=a[i].size();
            }
            else
            {
                break;
            }
        }
        cout<<x<<endl;
    }
    
}
