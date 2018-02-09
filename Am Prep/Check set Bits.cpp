//https://practice.geeksforgeeks.org/problems/check-set-bits/0

#include <iostream>
using namespace std;


int b(int n)
{
    if(n==0) return 0;
    if(n==1) return 1;
    int num=1;
    while(num<n)
    {
        num=num*2;
    }
    if(n==num-1) return 1;
    return 0;
}

int main() {
	//code
	int t;
	cin>>t;
	while(t)
	{
	    int n;
	    cin>>n;
	    if(b(n)) cout<<"YES"<<endl;
	    else cout<<"NO"<<endl;
	    t--;
	}
	return 0;
}
