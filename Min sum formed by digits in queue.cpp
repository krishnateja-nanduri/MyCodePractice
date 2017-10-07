#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int main()
 {
	int m;
    cin>>m;
    while(m--)
    {
          int n,i,s1=0,s2=0;
          cin>>n;
          int a[n];
          for(i=0;i<n;i++)
	  {
          	cin>>a[i];
	  }
          sort(a,a+n);
          for(i=0;i<n;i++)
          {
              if(i%2==0)
              {
                  s1=s1*10+a[i];
              }
              else
              {
                  s2=s2*10+a[i];
              }
          }
          cout<<s1+s2<<endl;
    }
	return 0;
}
