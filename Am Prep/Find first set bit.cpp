//https://practice.geeksforgeeks.org/problems/find-first-set-bit/0

#include<bits/stdc++.h>
using namespace std;

int getpos(int n)
{
    for(int i=0;i<32;i++)
    {
        if(n & (1 << i)) return (i+1);
    }
    
    return 0;
}

int main()
 {
    int t;
    cin >> t;
    
    while(t--)
    {
        int n;
        cin >> n;
        cout<<getpos(n)<<endl;
    }
	//code
	return 0;
}
