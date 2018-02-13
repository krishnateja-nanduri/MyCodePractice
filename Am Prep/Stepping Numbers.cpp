//https://practice.geeksforgeeks.org/problems/stepping-numberswrong-output/0

#include<bits/stdc++.h>
using namespace std;
long convert(string s)
{
	long len = s.size()-1,num = 0;

	for(int i=0;i<s.size();i++)
	{
		char c = s[i];
		//if(c!='0')
		num = num + pow(10,len)*(c-48);
		len--;
	}
	return num;
}
int main()
{
	int test;
	cin>>test;

	while(test--){
	long n,m;
	cin>>n>>m;

	vector<string> v;

	for(int i=0;i<10;i++)
	{
		string s = "";
		char c = i+48;
		s = s + c;
		v.push_back(s);
	}

	//sort(v.begin(),v.end());
	
	//cout<<endl;
	long count = 0,i=0;

	while(1)
	{
		string s = v[i];
		i++;
		//cout<<s<<" ";
		if(s=="0")
		{
			if(0>=n)
			    count++;
			continue;
		}
		long num = convert(s);
		if(num>=n&&num<=m)
		{
			count++;
		}
		else if(num>m)
		{
			//cout<<s<<" "<<m<<endl;
			break;
		}

		
		long len = s.size();
		char c = s[len-1];
		if(c!='9'&&c!='0')
		{
			char c1 = c + 1;
			char c2 = c - 1;
			v.push_back(s+c2);
			v.push_back(s+c1);
			//cout<<s+c2<<" "<<s+c1<<endl;
		}
		else if(c=='0')
		{
			char c1 = c + 1;
			v.push_back(s+c1);
		}
		else if(c=='9')
		{
			char c2 = c - 1;
			v.push_back(s+c2);
		}
	}

	cout<<count<<endl;
}
	return 0;
}
