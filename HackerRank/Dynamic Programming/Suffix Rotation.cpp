//https://www.hackerrank.com/challenges/suffix-rotation/problem

#include <bits/stdc++.h>

using namespace std;

const int Maxl = 26;
const int Maxn = 1005;
const int Inf = 1000000000;

int q;
string s;
vector <char> let;
int dp[Maxl][Maxn];
bool beg[Maxn];

void Insert(int best[], int val)
{
    if (val < best[0]) best[1] = best[0], best[0] = val;
    else if (val < best[1]) best[1] = val;
}

int getBest(int best[], int val)
{
    return best[0] == val? best[1]: best[0];    
}

int main(){
    cin >> q;
    for(int a0 = 0; a0 < q; a0++){
        cin >> s;
        fill((int*)dp, (int*)dp + Maxl * Maxn, Inf);
        let.clear();
        for (int i = 0; i < s.length(); i++)
            let.push_back(s[i]);
        sort(let.begin(), let.end()); let.erase(unique(let.begin(), let.end()), let.end());
        int lst = let.size() - 1;
        for (int j = 0; j < s.length(); j++)
            if (s[j] == let[lst]) dp[lst][j] = 0;
        for (int i = lst - 1; i >= 0; i--) {
            int cnt = 0;
            int best[2] = {Inf, Inf};
            for (int j = 0; j < s.length(); j++)
                if (s[j] == let[i]) {
                    int prv = (j - 1 + s.length()) % s.length();
                    while (s[prv] < s[j]) prv = (prv - 1 + s.length()) % s.length();
                    if (s[prv] == s[j] && prv != j)
                        beg[j] = false;
                    else {
                        beg[j] = true; cnt++;
                        int nxt = (j + 1) % s.length();
                        while (s[nxt] <= s[j]) nxt = (nxt + 1) % s.length();
                        dp[i][j] = dp[i + 1][nxt]; Insert(best, dp[i][j]);
                    }
                }
            for (int j = 0; j < s.length(); j++) {
                if (s[j] == let[i] && beg[j])
                    if (cnt == 1) dp[i][j] = best[0];
                    else dp[i][j] = min(cnt - 1 + getBest(best, dp[i][j]), cnt + best[0]);
                else if (s[j] >= let[i]) dp[i][j] = cnt + best[0];
            }
        }
       cout << dp[0][0] <<endl;
    }
    return 0;
}
