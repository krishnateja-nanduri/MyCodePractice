//https://practice.geeksforgeeks.org/problems/fill-array-by-1s/0

#include<bits/stdc++.h>
using namespace std;
int fill(int a[],int n)
{
  int c=0,f=0;
	    int ans=0;
	    for(int i=0;i<n;)
	    {
	        if(a[i]==1)
	        f=1;
	        while(i<n && a[i]==1)
	        i++;
	        c=0;
	        while(i<n && a[i]==0)
	        {
	            i++;
	            c++;
	        }
	        if(f==0 && i==n)
	        return -1;
	        int curr_count;
	        if(f==1 && i<n)
	        {
	            if(c & 1 ==0)
	            {
	                curr_count=c/2;
	            }
	            else
	            curr_count=(c+1)/2;
	            c=0;
	        }
	        else 
	        {
	            curr_count=c;
	            c=0;
	        }
	        ans=max(ans,curr_count);
	    } 
	    return ans;
}
int main() {
	//code
	int t;
	cin>>t;
	while(t--)
	{
	    int n;
	    cin>>n;
	    int a[n];
	    for(int i=0;i<n;i++)
	    cin>>a[i];
	    int c=fill(a,n);
	    cout<<c<<endl;
	}
	return 0;
}
