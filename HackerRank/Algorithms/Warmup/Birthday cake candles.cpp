//https://www.hackerrank.com/challenges/birthday-cake-candles/problem

#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;
  int maxVal = 0, ans = 0;
  for (int i = 0; i < n; i++) {
    int height;
    cin >> height;
    if (height > maxVal) {
      maxVal = height;
      ans = 1;
    } else if (height == maxVal) {
      ans++;
    }
  }
  cout << ans << endl;
  return 0;
}

