//https://practice.geeksforgeeks.org/problems/sum-equals-to-sum/0

#include<bits/stdc++.h>
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
	    for(int i = 0;i<n;i++){
	        cin >> arr[i];
	    }
	    set<int> hm;
	    int sum = 0;
	    int ans = 0;
	    for(int i = 0;i<n;i++){
	        for(int j = i+1;j<n;j++){
	            sum = arr[i] + arr[j];
	            if(hm.find(sum) != hm.end()){
	                ans = 1;
	                break;
	            }
	            else{
	                hm.insert(sum);
	            }
	            
	        }
	    }
	    cout << ans << endl;
	}
	return 0;
}
