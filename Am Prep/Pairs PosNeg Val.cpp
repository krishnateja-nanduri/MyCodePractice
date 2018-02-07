//https://practice.geeksforgeeks.org/problems/pairs-with-positive-negative-values/0

#include <bits/stdc++.h>
using namespace std;

int main()
{
	//code
	int t;
	cin>>t;
	for(int i=0;i<t;i++)
	{
	    int n;
	    cin>>n;
	    int a[n],c[n/2],p=0,j=0,k=n-1;
	    for(int m=0;m<n;m++)
	    {
	        cin>>a[m];
	    }
	    sort(a+0,a+n);
	    while(j<k)
	    {
	        if(a[k]==(-a[j]))
	        {
	            c[p]=a[k];
	            c[p+1]=(a[j]);
	            p=p+2;
	            k--;
	            j++;
	        }
	        else if(a[k]>(-a[j]))
	        {
	            k--;
	        }
	        else 
	        {
	            j++;
	        }
	    }
	    if(p==0)
	    {
	        cout<<"0"<<endl;
	    }
	    else
	    {
	     for(int l=p-1;l>=0;l--)
	    {
	        cout<<c[l]<<" ";
	    }
	    cout<<endl;
	    }
	}
	
	return 0;
}
