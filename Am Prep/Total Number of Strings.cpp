//https://practice.geeksforgeeks.org/problems/total-number-of-strings/0

#include <bits/stdc++.h>
using namespace std;

int main() {
	//code
	int T;
	cin>>T;
	while(T--){
	    int n;
	    cin>>n;
	    cout<<(pow(n,3)+3*n+2)/2<<endl;
	}
	return 0;
}
