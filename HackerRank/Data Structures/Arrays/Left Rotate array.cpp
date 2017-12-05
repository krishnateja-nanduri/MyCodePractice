//https://www.hackerrank.com/challenges/array-left-rotation/problem

#include <bits/stdc++.h>

using namespace std;

vector <int> leftRotation(vector <int> a, int n, int d) {
    // Complete this function
    d %= n;
    vector<int> vec(n);
    for(int i = 0; i < n; i++) {
        vec[(n+i-d)%n] = a[i];
    }
    return vec;
}

int main() {
    int n;
    int d;
    cin >> n >> d;
    vector<int> a(n);
    for(int a_i = 0; a_i < n; a_i++){
       cin >> a[a_i];
    }
    vector <int> result = leftRotation(a, n, d);
    for (ssize_t i = 0; i < result.size(); i++) {
        cout << result[i] << (i != result.size() - 1 ? " " : "");
    }
    cout << endl;


    return 0;
}

