//https://practice.geeksforgeeks.org/problems/find-equal-point-in-string-of-brackets/0

 #include<bits/stdc++.h>
 using namespace std;
 int main()
 {
     int t;
     cin>>t;
     while(t--)
     {
         string s;
         cin>>s;
         int totalend=0,totalopen=0;
         for(int i=0;i<s.size();i++)
         {
             if(s[i]==')')
             totalend++;
         }
         
         for(int i=0;i<s.size();i++)
         {
             if(s[i]=='(')
             totalopen++;
             if(s[i]==')')
             totalend--;
             if(totalopen==totalend)
             {
                 cout<<i+1;
                 break;
             }
         }
         cout<<endl;
     }
 }
