//https://www.hackerrank.com/challenges/array-splitting/problem

#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <climits>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <unordered_map>

#define ll long long

#define MIN(a, b) a < b ? a : b
#define MAX(a, b) a > b ? a : b

using namespace std;

int readline(char *str) {
    int i = 0;
    char ch;
    while((ch = getchar()) != '\n') {
        str[i++] = ch;
    }
    str[i] = '\0';
    return i;
}

int arr[16400];

int _process(int start, int end, ll int half_sum) {
    int mid = -1;
    ll int temp_sum = 0;
    for(int i = start; i <= end; i++) {
        temp_sum += arr[i];
        if(temp_sum == half_sum && i != end) {
            mid = i;
            break;
        }
    }

    if(mid == -1) {
        return 0;
    }

    if(half_sum % 2 == 0) {
        int ca = _process(start, mid, half_sum/2);
        int cb = _process(mid+1, end, half_sum/2);
        int m = MAX(ca, cb);
        return 1 + m;
    }
    else {
        return 1;
    }
}

int process(int n, ll int sum) {
    int count = 0;
    count = _process(0, n-1, sum/2);
    return count;
}

int main(int argc, char *argv[]) {
    int t;
    cin >> t;

    while(t--) {
        int n;
        ll int sum = 0;
        cin >> n;
        for(int i = 0 ; i < n; i++) {
            cin >> arr[i];
            sum += arr[i];
        }

        int ans;
        if(sum & 1) {
            ans = 0;
        }
        else {
            ans = process(n, sum);
        }
        cout << ans <<endl;
    }

    return 0;
}
