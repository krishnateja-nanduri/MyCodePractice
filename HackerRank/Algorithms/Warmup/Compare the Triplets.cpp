//https://www.hackerrank.com/challenges/compare-the-triplets/problem

#include <bits/stdc++.h>

using namespace std;

vector < int > solve(int a0, int a1, int a2, int b0, int b1, int b2){
    // Complete this function
    vector <int> result;
    int alice = 0, bob = 0;
    if (a0 > b0) 
        alice++;
    else if (a0 < b0) 
        bob++;
    
    
    if (a1 > b1) 
        alice++;
    else if (a1 < b1) 
        bob++;
    

    if (a2 > b2) 
        alice++;
    else if (a2 < b2) 
        bob++;
    
    result.push_back(alice);
    result.push_back(bob);
   return result;
}

int main() {
    int a0;
    int a1;
    int a2;
    cin >> a0 >> a1 >> a2;
    int b0;
    int b1;
    int b2;
    cin >> b0 >> b1 >> b2;
    vector < int > result = solve(a0, a1, a2, b0, b1, b2);
    for (ssize_t i = 0; i < result.size(); i++) {
        cout << result[i] << (i != result.size() - 1 ? " " : "");
    }
    cout << endl;
    

    return 0;
}

