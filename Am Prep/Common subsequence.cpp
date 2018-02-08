//https://practice.geeksforgeeks.org/problems/common-subsequence/0

#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin >> t;
    while(t--){  
        string a, b;
        cin >> a >> b;
        bool f = false;
        for (int i = 0; i < a.size(); i++){
            if(a.find(b[i]) == string :: npos)
                continue;
            else{
                f = true;
                break;
            }
        }
        if (f) cout << 1 << endl;
        else cout << 0 << endl;
    }
	return 0;
}
