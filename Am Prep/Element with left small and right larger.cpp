//https://practice.geeksforgeeks.org/problems/unsorted-array/0

#include <iostream>
using namespace std;

int main() {
	int t;
	cin>>t;
	while(t--){
	    int n;
	    cin>>n;
	    int a[n],max[n],min[n];
	    for(int i=0;i<n;i++)
	        cin>>a[i];
	    max[0]=a[0];
	    for(int i=1;i<n;i++){
	        max[i]=max[i-1];
	        if(a[i]>max[i])
	            max[i]=a[i];
	    }
	    min[n-1]=a[n-1];
	    for(int i=n-2;i>=0;i--){
	        min[i]=min[i+1];
	        if(a[i]<min[i])
	            min[i]=a[i];
	    }
	  
	    int f=0;
	    for(int i=1;i<n-1&&f==0;i++)
	        if(max[i]==min[i]){
	            cout<<a[i]<<endl;
	            f=1;
	        }
	    if(f==0)
	        cout<<-1<<endl;
	}
	return 0;
}
