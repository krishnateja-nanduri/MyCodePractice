//https://practice.geeksforgeeks.org/problems/check-if-a-number-can-be-expressed-as-xy/0

#include <bits/stdc++.h>
using namespace std;

int main() {
	//code
	int t;
	cin>>t;
	while(t--)
	{
	    int n;
	    int c=0;
	    cin>>n;
	    if(n==1)
	        {
	            c=1;
	        }
	        else
	        {
	    for(int i=1; i<=n/2; i++)
	    {
	        for(int j=1; j<=n/2; j++)
	        {
	            if(pow(i, j)==n)
	            {
	            c=1;
	            break;
	            }
	        }
	        if(c==1)
	        break;
	    }}
	    if(c==1)
	        cout<<"1\n";
	    else
	        cout<<"0\n";
	}
	return 0;
}
