//https://www.hackerrank.com/challenges/string-reduction/problem

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> vi;
typedef vector<vi> vii;
ll gcd(ll a,ll b) {return b==0?a:gcd(b,a%b);}
int main(){
    ll t;
    cin>>t;
    while(t--){
        string s;
        cin>>s;
        ll a[3];
        memset(a,0,sizeof(a));
        for(ll i=0;i<s.size();i++){
            a[s[i]-'a']++;
        }
        if((a[0]==0&&a[1]==0)||(a[1]==0&&a[2]==0)||(a[0]==0&&a[2]==0))
            cout<<s.size()<<endl;    
        else if(!(a[0]&1)&&!(a[1]&1)&&!(a[2]&1))cout<<2<<endl;
        else if((a[0]&1)&&(a[1]&1)&&(a[2]&1)) cout<<2<<endl;
        else cout<<1<<endl;
    }
    return 0;
}
