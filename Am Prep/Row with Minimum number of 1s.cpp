//https://practice.geeksforgeeks.org/problems/row-with-minimum-number-of-1s/0

#include<iostream>
#include<climits>

using namespace std;
int main()
 {
	int m,n,t;
	cin>>t;
	while(t--)
	{
	    cin>>n>>m;
	    int a;
	    int index =-1;
	    int min_count=INT_MAX; 
	    for(int i=0;i<n;i++)
	    {
	        int count = 0;
	        for(int j=0;j<m;j++)
	        {
	            cin>>a;
	            if(a) count++;
	        }
	        if(count){
	        if(count < min_count){
	        index = i;min_count=count;}}
	    }
	    cout<<index<<endl;
	}
	return 0;
}
