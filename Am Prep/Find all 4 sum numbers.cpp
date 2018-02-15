//https://practice.geeksforgeeks.org/problems/find-all-four-sum-numbers/0

#include<bits/stdc++.h>
using namespace std;
string toStr(int v)
{
    string s="";
    for(int i=v;i>0;i=i/10)
    s=(char)(i%10+'0')+s;
    return s;
}
int main()
 {
	//code
	int t;
	cin>>t;
	while(t>0)
	{
	    int n,x,i,k,l,j,f=0;
	    cin>>n>>x;
	    int a[n];
	    for(i=0;i<n;i++)
	    cin>>a[i];
	    sort(a,a+n);
	    int tmp[4];
	    set<string> st;
	    for(i=0;i<=n-4;i++)
	    {
	        for(j=i+1;j<=n-3;j++)
	        {
	            if(a[j]==a[j-1]&&(j-1)!=i)
	            continue;
	            k=j+1;
	            l=n-1;
	            while(k<l)
	            {
	                if(a[i]+a[j]+a[k]+a[l]==x)
	                {
	                    tmp[0]=a[i];
	                    tmp[1]=a[j];
	                    tmp[2]=a[k];
	                    tmp[3]=a[l];
	                    sort(tmp,tmp+4);
	                    string s="";
	                    for(int g=0;g<4;g++)
	                    s+=toStr(tmp[g])+" ";
	                    if(st.find(s)==st.end())
	                    {
	                    cout<<tmp[0]<<" "<<tmp[1]<<" "<<tmp[2]<<" "<<tmp[3]<<" $";
	                    st.insert(s);
	                    f=1;
	                    }
	                    k++;
	                    l--;
	                }
	                else if(a[i]+a[j]+a[k]+a[l]<x)
	                k++;
	                else
	                l--;
	            }
	        }
	    }
	    if(f==0)
	    cout<<"-1";
	    cout<<endl;
	    t--;
	}
	return 0;
}
