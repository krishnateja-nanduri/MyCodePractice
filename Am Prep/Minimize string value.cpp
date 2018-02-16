//https://practice.geeksforgeeks.org/problems/minimize-string-value/0

#include<algorithm>
#include<iostream>
using namespace std;
int main()
 {
	int t; 
        cin>>t;
        while(t--)
        {
            int a[125]={0},k,max=-1,index,sum=0,i;
             string s;
             cin>>s;
             cin>>k;
             for(i=0;i<s.length();i++)
              a[s[i]]++;
             while(k--)
             {
                 for(i=0;i<s.length();i++)
                 {
                     if(a[s[i]]>max)
                     {
                       max=a[s[i]];
                       index=i;
                     }
                     
                 }
                 max=0;
                 a[s[index]]--;
             }
             for(i=96;i<125;i++)
             {
                if(a[i]>0)
               sum=sum+(a[i]*a[i]);  
             }
              
              
             cout<<sum<<endl;
         }

}
