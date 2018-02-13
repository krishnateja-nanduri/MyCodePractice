//https://practice.geeksforgeeks.org/problems/smallest-positive-missing-number/0

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
	    int a[n];
	    int hash[100000]={0};
	    for(int i=0;i<n;i++)
	    {
	        cin>>a[i];
	        if(a[i]>0)
	        hash[a[i]]++;
	    }
	    for(int i=1;i<100000;i++)
	    {
	        if(hash[i]==0)
	        {
	            cout<<i<<endl;
	            break;
	        }
	    }
	}
	return 0;
}
