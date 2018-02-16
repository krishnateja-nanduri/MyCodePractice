//https://practice.geeksforgeeks.org/problems/max-value/0

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
	    int a[n];
	    for(int i=0;i<n;i++){
	        cin>>a[i];
	        a[i]=a[i]-i;
	    }
	    int min=a[0],max=a[0];
	    for(int i=0;i<n;i++)
	    {
	        if(a[i]>max)
	           max=a[i];
	        if(min>a[i])
	           min=a[i];
	    }
	    cout<<max-min<<endl;
	}
	return 0;
}
