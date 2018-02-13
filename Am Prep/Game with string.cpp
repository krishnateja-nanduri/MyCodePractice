//https://practice.geeksforgeeks.org/problems/game-with-string/0

#include<bits/stdc++.h>
using namespace std;
int mp[26];
int main() {
	int t,n,i,k;
	string s;
	cin>>t;
	while(t--)
	{
	    cin>>s;
	    cin>>k;
	    memset(mp,0,sizeof (mp));
	    
	    for(i=0;i<s.length();i++)
	    mp[s[i]-'a']++;
	    
	    priority_queue<int> pq;
	    
	    for(i=0;i<26;i++)
	    {pq.push(mp[i]); }
	    
	    while(k--)
	    {
	        int vl=pq.top();
	        pq.pop();
	        vl--;
	        pq.push(vl);
	    }
	    
	    long int ans=0;
	    while(!pq.empty())
	    {  
	        int tp=pq.top();
	      //  cout<<tp<<":";
	        pq.pop();
	        ans+=tp*tp;
	    }
	    cout<<ans<<"\n";
	}
	return 0;
}
