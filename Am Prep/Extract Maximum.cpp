//https://practice.geeksforgeeks.org/problems/extract-maximum/0

#include<iostream>
using namespace std;
int chk(string k)
{
    for(int i=0;i<k.length();i++)
        if(! isdigit(k[i])) return false;
        return true;
}
int main() {
	int t,n,i,j;
	string str;
	cin>>t;
	while(t--)
	{   string mx="";
	    cin>>str;
	    for(i=0;i<str.length()+1;i++)
	        for(j=i+1;j<str.length()+1;j++)
	        {	if( chk(str.substr(i,j-i)) && str[i]!='0' ){
	            if(str.substr(i,j-i).length() > mx.length() )
	            {
	                mx=str.substr(i,j-i);
	             //   cout<<mx<<":";
	            }
	            else if (str.substr(i,j-i).length() == mx.length())
	            {
	                if(stoi(str.substr(i,j-i))>stoi(mx))
	                { mx=str.substr(i,j-i);  }
	             //   cout<<mx<<":";
	            }
	        }}
	        if(mx.compare("")==0)
	        cout<<"0 \n"; else
	   cout<<mx<<"\n";
	}
	return 0;
}
