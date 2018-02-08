//https://practice.geeksforgeeks.org/problems/left-rotate-matrix-k-times/0

#include <iostream>
#include <vector>

using namespace std;

int main() {
	int t;
	cin >> t;
	for (int i = 0; i < t; ++i) {
	    int M, N, K;
	    cin >> M >> N >> K;
	    auto mtx = vector<vector<int>>(M, vector<int>(N));
	    for (int m = 0; m < M; ++m) {
	        for (int n = 0; n < N; ++n) {
	            int number;
	            cin >> number;
	            mtx[m][n] = number;
	        }
	    }
	    
	    for (int k = 0; k < K; ++k) {
	        auto rotmtx = mtx;
	        for (int m = 0; m < M; ++m) {
    	        for (int n = 0; n < N-1; ++n) {
    	            rotmtx[m][n] = mtx[m][n+1];
    	        }
    	        rotmtx[m][N-1] = mtx[m][0];
	        }
	        mtx = rotmtx;
	    }
	    
	    for (int m = 0; m < M; ++m) {
	        for (int n = 0; n < N; ++n) {
	            cout << mtx[m][n] << " ";
	        }
	        //cout << endl;
	    }
	    cout << endl;
	}
	return 0;
}
