//https://practice.geeksforgeeks.org/problems/check-if-array-contains-contiguous-integers-with-duplicates-allowed/0

#include <bits/stdc++.h>
using namespace std;

bool iscontiguous(int arr[], int n)
{
     sort(arr, arr+n);
     for (int i = 1; i < n; i++)
        if (arr[i] - arr[i-1] > 1)
            return false;
     
    return true;
    
}

int main() {
	int t;
	cin >> t;
	while (t-- > 0) {
	    int n; 
	    cin >> n;
	    int arr[n];
	    for (int i = 0; i < n; i++) 
	        cin >> arr[i];
	    cout << (iscontiguous(arr, n) ? "Yes" : "No") << '\n';
	}
	return 0;
}
