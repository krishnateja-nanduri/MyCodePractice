//https://practice.geeksforgeeks.org/problems/sum-of-lengths-of-non-overlapping-subarrays/0

#include<bits/stdc++.h>
using namespace std;
int main() {
	long int t,n,i,k;
	long int arr[100000];
	cin>>t;
	while(t--)
	{   
	    cin>>n;
	    
	    for(i=0;i<n;i++)
	    cin>>arr[i];
	    
	    cin>>k;
	    
	    int l=0,r=0,max=-999,ct=0,i=0,ans=0;
	    
	    while(i<n)
	    {
	        int fd=0,ct=0;
	        while(arr[i]<=k && i<n)
	        {
	            ct++;
	            if(arr[i]==k) fd=1;
	            i++;
	        }
	        
	        if(fd==1) ans+=ct;
	        while(arr[i]>k && i<n) i++;
	        
	    }
	    cout<<ans<<"\n";
	}
	return 0;
}
