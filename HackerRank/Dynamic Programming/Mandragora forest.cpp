//https://www.hackerrank.com/challenges/mandragora/problem

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

ll int arr[100010];

int compar(const void * a, const void * b) {
    return (*(int *)a) > (*(int *)b);
}

int main(int argc, char *argv[]) {
    int t;
    cin >> t;

    while(t--) {
        int n;
        ll int sum = 0;
        cin >> n;
        for(int i = 0; i < n; i++) {
            cin >> arr[i];
            sum += arr[i];
        }

        qsort(arr, n , sizeof(ll int), compar);

        ll int op, tp, temp_sum = sum;
        op = (0 + 1) * temp_sum;
        for(int x = 1; x < n; x++) {
            temp_sum -= arr[x-1];
            tp = (x + 1) * temp_sum;
            if(tp < op) {
                break;
            }
            op = MAX(tp, op);
        }
        cout << op <<endl;
    }

    return 0;
}
