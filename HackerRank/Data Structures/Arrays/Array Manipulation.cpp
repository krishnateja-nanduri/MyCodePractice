// https://www.hackerrank.com/challenges/crush/problem

#include <bits/stdc++.h>
using namespace std;


int main() {
    long int N,K
    int p,q,sum,Mx=0,x=0;

    cin>>N>>K;
    long int *a=new long int[N+1]();

    for(int i=0;i<K;i++)
    {
        cin>>p>>q>>sum;
        a[p]+=sum;
        if((q+1)<=N) a[q+1]-=sum;
    }

    for(int i=1;i<=N;i++)
    {
       x=x+a[i];
       if(Mx<x) Mx=x;

    }

    cout<<Mx;
    return 0;
}
