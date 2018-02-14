//https://practice.geeksforgeeks.org/problems/unique-numbers/0

#include <bits/stdc++.h>
using namespace std;

int main() {
	//code
	int t;
	cin>>t;
	while(t--)
	{
	    int l, u, x, f, c, p, n;
	    cin>>l>>u;
	    for(int i=l; i<=u; i++)
	    {
	        n=0;
	        int dig[10]={0};
	        c=0;
	        p=i;
	        while(p>0)
	        {   
	            n++;
	            x=p%10;
	                dig[x]=1;
	                p=p/10;
	        }
	        for(int i=0; i<10; i++)
	        {
	            if(dig[i]==1)
	                c++;
	        }
	        if(c==n)
	        {
	            cout<<i<<" ";
	        }
	    }
	    	cout<<endl;

	}
	return 0;
}
