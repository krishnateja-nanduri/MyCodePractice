//https://www.hackerrank.com/challenges/diagonal-difference/problem

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main(){
    int n, diag1 = 0, diag2 = 0, abs_diff = 0;
    cin >> n;
    vector< vector<int> > a(n,vector<int>(n));
    for(int a_i = 0;a_i < n;a_i++){
       for(int a_j = 0;a_j < n;a_j++){
          cin >> a[a_i][a_j];
       }
    }
    for(int i=0; i<n; i++)
    {
        diag1 = diag1 + a[i][i];
        diag2 = diag2 + a[i][n-1-i];
    }
    
    abs_diff = abs(diag1-diag2);
    cout << abs_diff <<endl;
    
}

