//https://practice.geeksforgeeks.org/problems/first-and-last-occurrences-of-x/0

#include <iostream>
using namespace std;

int main() {
	//code
	int t;
	cin>>t;
	while(t--)
	{
	    int n,k,tmp,first=-1,last;
	    cin>>n>>k;
	    for(int i=0;i<n;i++)
	    {
	        cin>>tmp;
	        if(tmp==k&&first==-1)
	        {
	            first=i;
	        }
	        if(tmp==k)
	            last=i;
	    }
	    if(first!=-1)
        cout<<first<<" "<<last<<"\n";
        else
         cout<<"-1\n";
	}
	return 0;
}
