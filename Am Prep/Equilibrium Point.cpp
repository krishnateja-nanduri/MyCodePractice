//https://practice.geeksforgeeks.org/problems/equilibrium-point/0

#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
int main()
{
    ll t;
    cin>>t;
    while(t--)
    {
        ll n;
        cin>>n;
        ll ar[n],sum=0;
        for(ll i=0;i<n;i++)
        {
            cin>>ar[i];
            sum+=ar[i];
        }
        
        ll flag=0,sum1=0,x;
        
        for(ll i=0;i<n;i++)
        {
            if(i!=0)
            sum1+=ar[i-1];
            if(sum1==sum-sum1-ar[i])
            {
                flag=1;
                x=i+1;
                break;
            }
         //   if(flag==1)
         //   break;
        }
        if(flag==0)
        cout<<"-1"<<endl;
        else
        cout<<x<<endl;
        
    }
    return 0;
}
