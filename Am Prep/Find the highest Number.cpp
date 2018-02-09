//https://practice.geeksforgeeks.org/problems/find-the-highest-number/0

#include <iostream>
using namespace std;

int main() {
	//code
	int t,n;
	cin>>t;
	while(t--)
	{
	    cin>>n;
	    int a[n];
	    for(int i=0;i<n;i++)
	    cin>>a[i];
	    for(int j=1;j<n;j++)
	    {
	        if(a[j]>a[j-1]&&a[j]>a[j+1])
	        {
	            cout<<a[j]<<endl;
	            break;
	        }
	    }
	}
	return 0;
}
