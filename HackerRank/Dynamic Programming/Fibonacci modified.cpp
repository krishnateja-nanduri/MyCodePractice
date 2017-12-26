//https://www.hackerrank.com/challenges/fibonacci-modified/problem

#include<bits/stdc++.h>
using namespace std;
int calc(int res1[],int res2[],unsigned long long int res_size){
    int prod[1000000]={0};
    int carry=0,tmp,sum;
    for(unsigned long long int i=0;i<res_size;i++){
        for(unsigned long long int j=0;j<res_size;j++){
            prod[i+j]+=res2[i]*res2[j];
            
        }
    }
  
    for(unsigned long long int i=0;i<res_size*2;i++){
        tmp=prod[i]/10;
        prod[i]=prod[i]%10;
        prod[i+1]=prod[i+1]+tmp;
    }
     for(unsigned long long int i=res_size*2;i>0;i--){
        if(prod[i]>0){
            res_size=i+1;
            break;
        }
    }
    
    for(unsigned long long int i=0;i<res_size;i++){
        sum=res1[i]+prod[i]+carry;
        res1[i]=res2[i];
        res2[i]=sum%10;
        carry=sum/10;
    }
    if(carry){
        res2[res_size]=carry%10;
        carry=carry/10;
        res_size++;
    }
    return res_size;
}
int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int t1,t2,n;
    cin>>t1>>t2>>n;
    int res1[1000000]={0},res2[1000000]={0};
    unsigned long long int res_size=1;
    res1[0]=t1;
    res2[0]=t2;
    for(int i=2;i<n;i++)
        res_size=calc(res1,res2,res_size);
    
    for (int i=res_size-1; i>=0; i--)
        cout << res2[i];
    
    return 0;
}
