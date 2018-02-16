//https://practice.geeksforgeeks.org/problems/hamiltonian-path/0

#include<bits/stdc++.h>
using namespace std;
bool check(vector<vector<bool>> &G, vector<bool> &v, int currPos, int n, int count) {
    if (count == n) return true;
    
    for (int i=0; i < n; i++) {
        if (!v[i] && G[currPos][i]) {
            v[i] = true;
            if (check(G, v, i, n, count + 1)) {
                return true;
            }
            v[i] = false;
        }
    }
    return false;
}
int start(vector<vector<bool>> &G, int n) {
    for (int i=0; i < n; i++) {
        int sum = 0;
        for (int j=0; j < n; j++) {
            if (G[i][j]) sum ++;
        }
        if (sum == 1) return i;
    }
    return 0;
}
int main() {
	int t;
	cin >> t;
	while(t--) {
	    int n, m;
	    cin >> n >> m;
	    vector<vector<bool>> G(n);
	    for (int i=0; i < n; i++) {
	        for (int j=0; j < n; j++) G[i].push_back(false);
	    }
	    for (int i=0; i < m; i++) {
	        int v1, v2;
	        cin >> v1 >> v2;
	        G[v1-1][v2-1] = true;
	        G[v2-1][v1-1] = true;
	    }
	    vector<bool> v(n);
	    for (int i=0; i < n; i++) v[i] = false;
	    int src = start(G, n);
	    if (src == -1) cout << 0 << "\n";
	    else {
	        v[src] = true;
	        cout << check(G, v, src, n, 1) << "\n";
	    }
	}
	return 0;
}
