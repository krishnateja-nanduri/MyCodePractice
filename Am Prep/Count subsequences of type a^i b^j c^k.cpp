//https://practice.geeksforgeeks.org/problems/count-subsequences-of-type-ai-bj-ck/0

#include<iostream>
using namespace std;
int main()
{
	int tst;
	cin>>tst;
	while(tst--)
	{
		string str;
		cin>>str;
		int ac=0,bc=0,cc=0;
		for(int i=0;i<str.length();i++)
		{
			if(str[i]=='a')
			ac=(1+2*ac);
			else if(str[i]=='b')
			bc=ac+2*bc;
			else if(str[i]=='c')
			cc=bc+2*cc;
		}
		cout<<cc<<endl;
	}
}
