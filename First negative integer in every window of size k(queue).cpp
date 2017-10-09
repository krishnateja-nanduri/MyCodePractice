#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,k,i,j;
        cin>>n;
        vector<int> arr(n);
        for(i=0;i<n;i++)
        {
            cin>>arr[i];
        }
        cin>>k;
        int num;
        for(i=0;i<=n-k;i++)
        {
            num = 0;
            for(j=i;j<i+k;j++)
            {
                if(arr[j]<0)
                {
                    num = arr[j];
                    break;
                }
            }
            cout<<num<<" ";
        }
        cout<<endl;
    }
	return 0;
}
