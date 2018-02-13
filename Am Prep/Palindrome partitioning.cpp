//https://practice.geeksforgeeks.org/problems/palindromic-patitioning/0

#include<bits/stdc++.h>
using namespace std;
int main()
{
	int t;
	cin>>t;
	while(t>0)
	{
		string s;
		cin>>s;
		int n = s.length();
		int table[n][n];
		for(int i=0;i<n;i++)
			table[i][i] = 1;
			
		for(int L=2;L<=n;L++)
		{
			for(int i=0;i<=n-L;i++)
			{
				int j = i+L-1;
				if(L==2)
						table[i][j] = (s[i]==s[j]);
				else
					table[i][j] = (s[i]==s[j] && table[i+1][j-1]);
			}
		}
		
		
		int c[n];
		for(int j=0;j<n;j++)
		{
			if(table[0][j])
				c[j] = 0;
			else
			{
				c[j] = INT_MAX;
				for(int i=0;i<j;i++)
				{
					if(table[i+1][j] && 1+c[i]<c[j])
						c[j] = 1+c[i];
				}
			}
		}
		cout<<c[n-1]<<"\n";
		t--;
	}
}
