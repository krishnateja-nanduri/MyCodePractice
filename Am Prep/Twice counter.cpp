//https://practice.geeksforgeeks.org/problems/twice-counter/0

#include<iostream>
#include<map>
using namespace std;

int main() {
	int t;
	cin>>t;
	while(t--)
	{
	    int n,i,count=0;
	    cin>>n;string a;
	    string str[n];
	    map<string,int> m;
	    for(i=0;i<n;i++)
	     cin>>str[i];
	    for(i=0;i<n;i++)
	    { m[str[i]]++;
	     // cout<<m[str[i]]<<" ";
	      if(m[str[i]]==2)
	      { count++;}
	      if(m[str[i]]==3 )
	     {    count--;}
	    }
	    cout<<count<<"\n";
	    
	    
	}
	return 0;
}
