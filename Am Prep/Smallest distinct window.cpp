//https://practice.geeksforgeeks.org/problems/smallest-distant-window/0

#include<bits/stdc++.h>
using namespace std;

int smallestwindow(string s){
	int mini=s.length();
	map<char,int > m;
	for(int i=0;i<s.length();i++)
	m[s[i]]=1;
	map<char,int> :: iterator it;
	int count=0;
	for(it=m.begin();it!=m.end();it++) 
	count+=it->second;
	if(count==s.length())
	return count;

	for(int i=0;i<=s.length()-count;i++){
		map<char,int> v;
		int temp=0,j=i;
		while(temp<count&&j<s.length()){
			v[s[j]]=1;
			j++;
			temp=v.size();
		}
		if(temp==count)
		mini=min(mini,j-i);
		if(mini==count)
		return mini;
		
	}
	return mini;
}
int main(){
	int t;
	cin>>t;
	while(t--){
		string s;
	cin>>s;
	cout<<smallestwindow(s)<<endl;
	
	}
	return 0;
}
