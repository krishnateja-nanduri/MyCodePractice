//https://practice.geeksforgeeks.org/problems/four-elements/0

#include<bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin>>t;
	while(t!=0)
	{
	    int n;
	    cin>>n;
	    int i,j,l,r,x,f=0;
	    int arr[n];
	    for(i=0;i<n;i++) cin>>arr[i];
	    cin>>x; sort(arr,arr+n);
	    for(i=0;i<n;i++)
	    {
	        for(j=i+1;j<n;j++)
	        {
	            l=0; r=n-1;
	            while(l<r)
	            {
	                if(l==i||l==j) {l++; continue;}
	                if(r==i||r==j) {r--; continue; }
	                
	                if(arr[i]+arr[j]+arr[l]+arr[r]==x)
	                {
	                    f=1; i=n; j=n; break;
	                }
	                else if(arr[i]+arr[j]+arr[l]+arr[r]<x)
	                {
	                    l++;
	                }
	                else r--;
	                
	            }
	        }
	    }
	    cout<<f<<endl;
	    t--;
	}
	return 0;
}
