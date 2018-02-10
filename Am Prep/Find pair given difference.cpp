//https://practice.geeksforgeeks.org/problems/find-pair-given-difference/0

#include<bits/stdc++.h>
using namespace std;
int main()
 {
	int t;
	cin>>t;
	 while(t--)
	 {
	     int n,diff;
	     cin>>n>>diff;
	     int a[n];
	     map<int,int>m;
	     for(int i=0;i<n;++i)
	     { cin>>a[i];
	        m[a[i]]++;
	     }
	     int flag=0;
	     for(int i=0;i<n;++i)
	     {
	         int x=a[i]+diff;
	         if(m[x]!=0)
	           {
	                flag=1;
	                break;
	           }
	     }
	     if(flag==1)
	     cout<<"1";
	     else
	     cout<<"-1";
	    cout<<"\n"; 
	 }
	
	return 0;
}
