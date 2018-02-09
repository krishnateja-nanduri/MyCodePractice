//https://practice.geeksforgeeks.org/problems/index-of-first-1-in-a-sorted-array-of-0s-and-1s/0

#include <bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin>>t;
	while(t--)
	{
	    int n;
	    cin>>n;
	    int a[n];
	    int ans=-1,flag=0;
	    for(int i=0;i<n;i++)
	    {
	        cin>>a[i];
	        if(a[i]==1 && flag==0)
	        {
	        ans=i;
	        flag=1;
	        }
	    }
	    cout<<ans<<endl;
	}
	return 0;
}
