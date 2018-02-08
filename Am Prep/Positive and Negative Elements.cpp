//https://practice.geeksforgeeks.org/problems/positive-and-negative-elements/0

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
	    int arr[n];
	    int x = 0;
	    int j = 0;
	    int k = 1;
	    for(int i = 0;i<n;i++){
	        cin >> x;
	        if(x>0){
	            if(j < n){
	                arr[j] = x;
	            }     
	            j += 2;
	        }
	        else{
	            if(k<n){
	                arr[k] = x;
	            }
	            k += 2;
	        }
	    }
	    for(int i = 0;i<n;i++){
	        cout << arr[i] <<" ";
	    }
	    cout << endl;
	}
	return 0;
}
