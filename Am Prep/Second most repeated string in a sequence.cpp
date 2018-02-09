//https://practice.geeksforgeeks.org/problems/second-most-repeated-string-in-a-sequence/0

#include<bits/stdc++.h>
using namespace std;

int main(){
	int t;
	cin>>t;
	while(t-- != 0){
		int n;
		cin>>n;
		vector<string> str(n);

		for(int i=0; i<n; i++)	cin>>str[i];

		map<string, int> mp;
		
		for(int i=0; i<n; i++){
			mp[str[i]]++;
		}
		
		pair<string, int> first, next;
		first.second = -1;
		
		for(pair<string, int> p : mp ){
			if(p.second > first.second){
				
				next = first;
				first = p;
				
			} else if (p.second > next.second){
				next = p;
			}
		}
		
		cout<<next.first<<"\n";
	}
}
