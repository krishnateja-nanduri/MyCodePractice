//https://practice.geeksforgeeks.org/problems/even-and-odd-elements-at-even-and-odd-positions/0

#include<iostream>
using namespace std;
int main()
 {
	//code
	int t;
	cin >> t;
	int n = 0;
	while(t--){
	    cin >> n;
	    int x = 0;
	    int arr[n];
	    int ans[n];
	    int j = 0;
	    int k = 1;
	    for(int i = 0;i<n;i++){
	        cin >> arr[i];
	        ans[i] = arr[i];
	    }
	    for(int i = 0;i<n;i++){
	        if(arr[i] & 1){
	            if(k < n){
	                ans[k] = arr[i];
	                k += 2;
	            }
	        }
	        else{
	            if(j < n){
	                ans[j] = arr[i];
	                j += 2;
	            }
	        }
	    }
	    
	    for(int i = 0;i<n;i++){
	        cout << ans[i] <<" ";
	    }
	    cout << endl;
	    
	}
	return 0;
}
