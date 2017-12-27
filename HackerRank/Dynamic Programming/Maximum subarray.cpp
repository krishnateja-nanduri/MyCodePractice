//https://www.hackerrank.com/challenges/maxsubarray/problem

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int nonconti(int a[],int size)
{   
    int max_sum = 0,temp=0,neg_max=-9999;
    
    for(int i=0;i<size;i++)
    {   
        if ( a[i] < 0 )
          {  temp++;
             if( a[i] > neg_max )
                 neg_max = a[i];
          }
        else
            max_sum += max(0,a[i]);
    }
    if( temp == size )
        return neg_max;
    return max_sum;
}

int conti(int a[],int size)
{
    int max_so_far = a[0],curr_max = a[0];
    
    for(int i=1;i<size;i++)
    {
        curr_max = max(a[i],curr_max+a[i]);
        max_so_far = max(curr_max,max_so_far);
    }
    return max_so_far;
}

int main() {
    int T;
    cin>>T;
    while(T--)
    {   int size,output1=0,output2=0,*a;
        cin>>size;
        a = new int[size];
        for(int i=0;i<size;i++)
                cin>>a[i];
        output1 = conti(a,size);
        output2 = nonconti(a,size);
        cout<<output1<<" "<<output2<<"\n";
    }
    
    return 0;
}
