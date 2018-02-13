//https://practice.geeksforgeeks.org/problems/champagne-overflow/0

#include <bits/stdc++.h>
using namespace std;
float arr[1001][1001];
void fillNow(int i,int j,float amount){
    if(amount==0){
        return ;
    }
    else{
        if(arr[i][j]!=1){
            
            arr[i][j]= arr[i][j] + amount;
            
            if(arr[i][j]>1){
                amount=arr[i][j]-1;
                arr[i][j] = 1;
            }
            else{
                amount = 0;
            }
        }
        if(arr[i][j]==1){
            int x = i+1;
            int y = j+1;
            fillNow(x,y,amount/2);
            int z = j;
            fillNow(x,z,amount/2);
        }
    }
}
int main() {
	int T;
	cin >> T;
	while(T--){
	    int unit;
	    int a;
	    int b;
	    cin >> unit;
	    cin >> a;
	    cin >> b;

	    int i,j;
	    for(i=0;i<1000;i++){
	        for(j=0;j<1000;j++){
	            arr[i][j]=0;
	        }
	    }
	    while(unit>0){
	        fillNow(0,0,(float)1);
	        unit--;
	        
	    }
	    cout << arr[a-1][b-1] << "\n";
	}
	return 0;
}
