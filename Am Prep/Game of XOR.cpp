//https://practice.geeksforgeeks.org/problems/game-of-xor/0

#include<iostream>
using namespace std;
int main()
 {
	//code
	int t;
	cin>>t;
	while(t--)
	{
	    int n;
	    cin>>n;
	    int x=0;
	    for(int i=0;i<n;i++)
	    {
	        int y;
	        cin>>y;
	        if(i%2==0)
	        x=x^y;
	    }
	    if(n%2==0)
	    cout<<0<<'\n';
	    else
	    cout<<x<<'\n';
	}
	return 0;
}
