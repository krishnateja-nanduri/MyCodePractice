// Question : http://practice.geeksforgeeks.org/problems/print-leaf-nodes-from-preorder-traversal-of-bst/0
#include <bits/stdc++.h>
#include <iostream>
using namespace std;
void BSTtraverse(int *arr,int l,int h)
{
    if(l>h)
    return;
    if(l==h)
    cout<<arr[l]<<" ";
    int i;
    for(i=l+1;i<=h;i++)
        if(arr[i]>arr[l])
        break;
    BSTtraverse(arr,l+1,i-1);
    BSTtraverse(arr,i,h);
}
int main() {
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int arr[n];
        for(int i=0;i<n;i++)
        {
            cin>>arr[i];
        }
        BSTtraverse(arr,0,n-1);
	    cout<<endl;
    }
	return 0;
}
