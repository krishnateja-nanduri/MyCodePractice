//https://practice.geeksforgeeks.org/problems/start-elements/0

#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin >> t;
    while(t--){   
        int n;
        cin >> n;
        vector<int> a(n);
        int m = INT_MIN;
        for (int i = 0; i < n; i++)
            cin >> a[i];
        set <int , greater<int> > ss;
        for (int i = n - 1; i >= 0; i--){
            if(a[i] > m){
                m = a[i];
                ss.insert(m);
            }
        }
        for (auto i = ss.begin(); i != ss.end(); i++){
            cout << *i << " ";
        }
        cout << endl;
        if(count(a.begin(), a.end(), m) > 1) cout << -1 << endl;
        else cout << m << endl;
    }
	return 0;
}
