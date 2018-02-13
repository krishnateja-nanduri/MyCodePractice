//https://practice.geeksforgeeks.org/problems/numbers-with-same-first-and-last-digit/0

#include<iostream>
using namespace std;

int getfdgt(int x)
{
    while(x>=10)
    {
        x=x/10;
    }
    return x;
}

int getCount(int x)
{
    if(x<10)
        return x;
        
    int t=x/10;
    int ans=9+t;
    
    int fdgt=getfdgt(x);
    int ldgt=x%10;
    
    if(fdgt > ldgt)
        ans--;
        
    return ans;
    
}


int main()
 {
	int t;
	cin>>t;
	for(int i=1;i<=t;i++)
	{
	int low,high;
	cin >> low >> high;
	int ans=getCount(high)-getCount(low-1);
	
	cout<<ans<<endl;
	}
	return 0;
}
