//https://practice.geeksforgeeks.org/problems/reverse-each-word-in-a-given-string/0

#include<bits/stdc++.h>
using namespace std;
#define ll long long int
int main(){
    int counter,t;
    cin>>counter;
    for(t=0;t<counter;t++){
        ll i,j,n,m,k=0,arr[100000+1],count=0,temp[100000+1],var=0;
        string str,s="";
        cin>>str;
        n=0;
        k=0;
        m=str.length();
        //reverse(str.begin(),str.end());
        while((n=str.find(".",n))!=string::npos){
            reverse(str.begin()+k,str.end()-m+n);
            n=n+1;k=n;
            var=n;
        }
        reverse(str.begin()+var,str.end());
        cout<<str<<endl;
        
    }
    return 0;
}
