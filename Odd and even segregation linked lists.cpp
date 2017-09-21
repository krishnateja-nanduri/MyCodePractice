#include <bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin>>t;
	while(t--){
	    int n;
	    cin>>n;
	    int x;
	    list<int> odd;
	    list<int> even;
	    
	   for(int i=0;i<n;i++)
	   {
	       cin>>x;
	       if(x%2==0)
	       even.push_back(x);
	       else
	       odd.push_back(x);
	       
	   }
	   
	   while(!even.empty())
	   {
	       cout<<even.front()<<" ";
	       even.pop_front();
	   }
	   
	   while(!odd.empty())
	   {
	       cout<<odd.front()<<" ";
	       odd.pop_front();
	   }
	   cout<<endl;
	    }
	return 0;
}
