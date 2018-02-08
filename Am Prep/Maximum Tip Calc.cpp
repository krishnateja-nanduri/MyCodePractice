//https://practice.geeksforgeeks.org/problems/maximum-tip-calculator/0

#include <iostream>
using namespace std;
int n;
int a[110];
int b[110];

int solve(int i,int X,int Y)
{
	if(i==n)
		return 0;

	if(X<=0 )
		return b[i] + solve(i+1,X,Y-1);
	if(Y<=0)
		return a[i] + solve(i+1,X-1,Y);
	else 
		return max(a[i] + solve(i+1,X-1,Y), b[i] + solve(i+1,X,Y-1));
		
	
}

int main() {
    int i;
	cin>>i;
	cin.ignore(1000, '\n');
	while(i--){
	    int x,y;
	    cin>>n>>x>>y;
	    cin.ignore(1000, '\n');
	    for(int i=0;i<n;i++){
	        cin>>a[i];
	    }
	    cin.ignore(1000, '\n');
	    for(int i=0;i<n;i++){
	        cin>>b[i];
	    }
	    cin.ignore(1000, '\n');
	    if(x+y<n)
        {
            y=n-x;
        }
	    cout<<solve(0,x,y);
	    cout<<"\n";
	}
    
	//code
	return 0;
}
