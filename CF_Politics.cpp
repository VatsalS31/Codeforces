#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,k;
        cin>>n>>k;
        
       
        vector<string>str(n);
        for(int i=0;i<n;i++)
        {
             cin>>str[i];
           
        }
        int maxno=1;
        for(int i=1;i<str.size();i++)
        {
            if(str[0]==str[i])
            {
                maxno++;
            }
        }
        cout<<maxno<<endl;
    }
    
}
