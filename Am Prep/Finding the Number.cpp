//https://practice.geeksforgeeks.org/problems/finding-the-numbers/0

#include<iostream>
using namespace std;
typedef long long int ll;

int main()
 {
	//code
	int t;
	cin>>t;
	
	while(t--)
	{
	    int n;
	    cin>>n;
	    int size=2*n+2;
	    ll ar[size],res=0,num1=0,num2=0;
	    
	    for(int i=0;i<size;i++)
	    {
	        cin>>ar[i];
	        res^=ar[i];
	    }
	    
	    ll pos= res & ~(res-1);
	    for(int i=0;i<size;i++)
	    {
	        if(ar[i] & pos)
	        {
	            num1^=ar[i];
	        }
	        else
	        {
	            num2^=ar[i];
	        }
	    }
	    if(num1<num2)
	        cout<<num1<<" "<<num2<<"\n";
	    else
	        cout<<num2<<" "<<num1<<"\n";
	    
	}
	return 0;
}
