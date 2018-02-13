//https://practice.geeksforgeeks.org/problems/maximum-money/0

#include <iostream>
using namespace std;

int main() {
	int t,i,j,k;
	cin >> t;
	int n[t],m[t];
	for(i=0;i<t;i++)
	{
	    cin >> n[i] >> m[i];
	    if(n[i]%2==0)
	    {
	        n[i]=(n[i]/2)*m[i];
	    }
	    else
	    {
	        n[i]=(n[i]/2+1)*m[i];
	    }
	}
	for(i=0;i<t;i++)
	{
	    cout << n[i]<<endl;
	}
	return 0;
}
