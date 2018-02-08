//https://practice.geeksforgeeks.org/problems/find-k-th-character-in-string/0

#include<bits/stdc++.h>
using namespace std;

int main() 
{
    int t;
    cin>>t;
    while(t--)
    {
        int m,n,k;
        cin>>m>>k>>n;
        int c=0;
        string s="";
        while(m>0)
        {
            c=m%2;
            m=m/2;
            char a;
            if(c==1)
            a='1';
            else 
            a='0';
            s=s+a;
        }
        reverse(s.begin(),s.end());
        
        string s1="";
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<s.length();j++)
            {
               if(s[j]=='1')
               s1=s1+"10";
               else
               s1=s1+"01";
            }
             s=s1;
             s1="";
        }
          cout<<s[k]<<endl;
       
    }
    
	//code
	return 0;
}
