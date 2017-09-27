#include <iostream>
#include <set>
using namespace std;

int main() {
	int t;
	cin >> t;
	while (t-- > 0) {
	    int n; cin >> n;
	    set<int> s;
	    for (int i = 0; i < n; i++) {
	        int x; cin >> x;
	        s.insert(x);
	    }
	    
	    int k; cin >> k;
	    int sum = 0;
	    for (const int x : s) {
	        sum += x;
	        if (--k == 0) {
	            break;
	        }
	    }
	    cout << sum << '\n';
	}
	return 0;
}
