//https://practice.geeksforgeeks.org/problems/number-of-groups/0

#include<bits/stdc++.h>
using namespace std;
int main()
 {
int t;
scanf("%d",&t);
for(int z=0;z<t;z++){
	//code
	int n;
	cin>>n;
	int a[n];
	int c1=0,c2=0,c3=0;
	for(int i=0;i<n;i++){
	    cin>>a[i];
	    if(a[i]%3==0){
	        c3++;
	    }
	    else if(a[i]%3==1){
	        c1++;
	    }
	    else{
	        c2++;
	    }
	}
	long int ans= (c1*c2*c3)+(c2*c1);
	if(c3>1){
	    int temp= ((c3-1)*c3)/2;
	    ans+=temp;
	}
	if(c3>2){
    	int temp= ((c3-1)*(c3-2)*c3)/6;
    	ans+=temp;
	}
	if(c1>=3){
	    int temp= ((c1-1)*(c1-2)*c1)/6;
	    ans+=temp;
	}
	if(c2>=3){
	    int temp= ((c2-1)*(c2-2)*c2)/6;
	    ans+=temp;
	}
	cout<<ans<<endl;
	
}
	return 0;
}
