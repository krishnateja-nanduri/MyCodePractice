//https://practice.geeksforgeeks.org/problems/prime-number-of-set-bits/0

#include <iostream>
#include<math.h>
using namespace std;

void sieve(int *arr) {
    arr[1] = 1;
    arr[0] = 1;
    for(int i = 2; i < sqrt(100001); i++) {
        int j = 2;
        while(i*j<= 100000) {
            arr[i*j] = 1;
            j++;
        }
    }
}
int main() {
    int arr[100001], i, t, L, R, count;
    sieve(arr);
	cin>>t;
	while(t--) {
	    cin>>L>>R;
	    count = 0;
	    for(i = L; i <= R; i++) {
	        if(arr[__builtin_popcount(i)] == 0){
	            count++;
	        }
	    }
	    cout << count <<endl;
	}
	return 0;
}
