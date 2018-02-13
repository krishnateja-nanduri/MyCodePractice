//https://practice.geeksforgeeks.org/problems/find-all-pairs-whose-sum-is-x/0

#include<iostream>
using namespace std;
int main() 
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,m,sum;
        cin>>m>>n>>sum;
        int a[m],b[n],i,j;
        for(i=0;i<m;i++)
        cin>>a[i];
        for(j=0;j<n;j++)
        cin>>b[j];
        int temp,round;
        for(round=1;round<=m-1;round++)
        {
            for(i=0;i<=m-1-round;i++)
            {
                if(a[i]>a[i+1])
                {
                    temp=a[i];
                    a[i]=a[i+1];
                    a[i+1]=temp;
                }
            }
        }
     
        int k=0;
        for(i=0;i<m;i++)
         {
             for(j=0;j<n;j++)
             {
                 if(sum!=a[i]+b[j])
                 continue;
                 else
                 {
                     if(k==0)
                     cout<<a[i]<<" "<<b[j];
                     if(k!=0)
                     {
                         cout<<","<<" ";
                         cout<<a[i]<<" "<<b[j];
                     }
                     k++;
                 }
             }
         }
         if(k==0)
         cout<<"-1";
         cout<<"\n";
    }
	return 0;
}
