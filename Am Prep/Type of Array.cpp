//https://practice.geeksforgeeks.org/problems/type-of-array/0

#include <bits/stdc++.h>
using namespace std;

int main() {
	//code
	int t;
	cin>>t;
	while(t--)
	{
	    int n;
	    cin>>n;
	    int ar[n],i,max=0;
	    for(i=0;i<n;i++)
	    {
	        cin>>ar[i];
	        if(ar[i]>max)
	        max=ar[i];
	    }
	    cout<<max<<" ";
	    if(ar[0]<ar[n-1])
	    {
	        if(ar[0]>ar[1])
	        cout<<3<<"\n";
	        else if(ar[1]>ar[0])
	        {
	            if(ar[2]>ar[1])
	            cout<<1<<"\n";
	            else
	            cout<<"3"<<"\n";
	        }
	    }
	    else
	    {
	        if(ar[0]<ar[1])
	        cout<<4<<"\n";
	        else if(ar[1]<ar[0])
	        {
	            if(ar[2]>ar[1])
	            cout<<4<<"\n";
	            else
	            cout<<"2"<<"\n";
	        }
	    }
	}
	return 0;
}
