//https://www.hackerrank.com/challenges/dynamic-programming-classics-the-longest-common-subsequence/problem

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
	// Read input
	int n, m;
	cin>>n>>m;
	int *array1 = new int[n];
	int *array2 = new int[m];
	for(int i = 0; i < n; i++) {
		cin>>array1[i];
	}
	for(int i = 0; i < m; i++) {
		cin>>array2[i];
	}
	// Setup DP 
	int **matrix = new int*[n+1];
	for(int i = 0; i <= n; i++) {
		matrix[i] = new int[m+1];
		for(int j = 0; j <= m; j++) {
			matrix[i][j] = 0;
		}
	}
	// Main algorithm
	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= m; j++) {
			if(array1[i-1] == array2[j-1]) {
				// Property 1
				matrix[i][j] = matrix[i-1][j-1] + 1;
			} else {
				// Property 2
				matrix[i][j] = max(matrix[i-1][j], matrix[i][j-1]);
			}
		}
	}
	// Read off solution, size of lcs is matrix[n][m]
	int *lcs = new int[matrix[n][m]];
	int count = matrix[n][m];
	int i = n, j = m;
	while(count > 0) {
		if(matrix[i-1][j] == matrix[i][j]) {
			// Value came from smaller array1
			i--;
		} else if(matrix[i][j-1] == matrix[i][j]) {
			// Value came from smaller array2
			j--;
		} else {
			// Value came from the letter at the current index
			lcs[count-1] = array1[i-1];
			i--;
			j--;
			count--;
		}
	}
	for(int i = 0; i < matrix[n][m]; i++) {
		cout<<lcs[i]<<" ";
	}
    return 0;
}
