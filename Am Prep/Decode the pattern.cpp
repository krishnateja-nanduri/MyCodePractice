//https://practice.geeksforgeeks.org/problems/decode-the-pattern/0

#include<bits/stdc++.h>
using namespace std;
int main()
 {
     int t,num;
     cin>>t;
     string s,m,n;
     for(int i=0;i<t;i++)
     {
        cin>>num;
        vector<string>v;
        v.push_back("1");
        v.push_back("11");
        char ch='1';
        int count=1;
        s="11";
        for(int k=0;k<21;k++)
        {
            ch=s[0];
            count=1;
            int flag=0;
            m="";
            for(int j=1;j<s.length();j++)
            {
                if(s[j]==ch)
                {
                    count++;
                }
                else 
                {
                    
                    n=to_string(count);
                    n+=ch;
                    m+=n;
                    count=1;
                    ch=s[j];
                }
            }
                    n=to_string(count);
                    n+=ch;
                    m+=n;
                    v.push_back(m);
                    s=m;
     }
     cout<<v[num-1]<<endl;
     }
	return 0;
}
