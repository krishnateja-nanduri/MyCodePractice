//https://practice.geeksforgeeks.org/problems/k-anagrams-1/0

#include <bits/stdc++.h>
using namespace std;

int main() {
	int t,n;
	cin>>t;
	while(t--){
	    unordered_map<string,int> m;
	    string s;
	    cin>>n;
	    for(int i=0;i<n;i++){
	        cin>>s;
	        sort(s.begin(),s.end());
	        m[s]++;
	    }
	    for(auto it = m.begin(); it!=m.end();it++) cout<<it->second<<" ";
	    cout<<endl;
	}
	return 0;
}
