//https://practice.geeksforgeeks.org/problems/chocolate-station/0

#include<bits/stdc++.h>
#define len 100005
#define mod 1000000007
#define sq(i) i*i
using namespace std;
typedef long long ll;


//vector<ll> arr;
int main(){
    int t;
    cin>>t;
    while(t--){
        vector<int> inp(len);
        int n,k;
        cin>>n;
        for(int i=0;i<n;i++){
            cin>>inp[i];
        }
        cin>>k;
        int ans=inp[0],cur=0;
        for(int i=1;i<n;i++){
            int temp=inp[i-1]-inp[i];
            if(temp<0){
                if(cur+temp>=0){
                    cur+=temp;
                }
                else{
                    ans+=abs(cur+temp);
                    cur=0;
                }
            }
            else{
                cur+=temp;
            }
            //cout<<cur<<" "<<ans<<endl;
        }
        cout<<(ans*k)<<endl;
    }
}

