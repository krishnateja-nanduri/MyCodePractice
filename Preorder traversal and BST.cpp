#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int main()
 {
	//code
	int t,n;
	cin>>t;
	while(t--)
	{ 
	    int out=0;
	    cin>>n;
	    int a[n];
	    for(int i=0;i<n;i++)
	    cin>>a[i];
	    stack<int>s;
	    int root=INT_MIN;
	    for(int i=0;i<n;i++)
	    {
        if(a[i]<root)
        {
            out=1;
            break;
        }
        
        while(!s.empty() && s.top()<a[i])
        {
            root=s.top();
            s.pop();
            
        }
        s.push(a[i]);
    }
    if(out==1)
    cout<<"0"<<endl;
    else
    cout<<"1"<<endl;

	
	
	}
	return 0;
	
}
