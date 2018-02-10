//https://practice.geeksforgeeks.org/problems/count-the-elements/0

#include <bits/stdc++.h>
using namespace std;


int main() {
	int t,n;
	
	cin>>t;
	while(t--)
	{
	    cin>>n;
	    int b[101] = {0};
	    int a[n];
	    for(int i=0 ; i<n ; i++)
	    {
	        cin>>a[i];
	    }
	    for(int i=0 ; i<n ; i++)
	    {
	        int x;
	        cin>>x;
	        b[x]++;
	    }
	    for(int i=0 ; i<n ; i++)
	    {
	        int y=0;
	        for(int j=0 ; j<=a[i] ; j++)
	            y += b[j];
	        cout << y;
	        if(i!=n-1)
	            cout << ",";
	    }
	    cout << endl;
	}
	
	return 0;
}
