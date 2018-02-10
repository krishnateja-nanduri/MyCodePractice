//https://practice.geeksforgeeks.org/problems/uncommon-characters/0

#include <iostream>

using namespace std;

int main() {
	//code
	int t;
	cin>>t;
	while(t--)
	{
	    string s1,s2;
	    cin>>s1>>s2;
	    int a[26]={0};
	    int b[26]={0};
	    for(int i=0;i<s1.length();i++)
	    {
	        a[s1[i]-'a']=1;
	    }
	    for(int i=0;i<s2.length();i++)
	    {
	        b[s2[i]-'a']=1;
	    }
	    for(int i=0;i<26;i++)
	    {
	        if(a[i]^b[i])
	        cout<<(char)('a'+i);
	    }
	    cout<<endl;
	}
	return 0;
}
