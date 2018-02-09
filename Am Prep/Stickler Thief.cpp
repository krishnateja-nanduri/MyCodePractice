//https://practice.geeksforgeeks.org/problems/stickler-theif/0

#include<bits/stdc++.h>
using namespace std;
int find_max(int a[],int n)
{
    int inc=a[0],exc=0,temp;
    for(int i=1;i<n;i++)
    {
        temp=exc+a[i];
        exc=max(exc,inc);
        inc=temp;
    }
    return max(exc,inc);
}
int main()
 {
	//code
	int t;
	cin>>t;
	while(t--)
	{
	    int n;
	    cin>>n;
	    int a[n];
	    for(int i=0;i<n;i++)
	       cin>>a[i];
	    cout<<find_max(a,n)<<endl;
	}
	return 0;
}
