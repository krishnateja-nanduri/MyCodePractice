//https://www.hackerrank.com/challenges/two-robots/problem

 #include <iostream>
 #include <vector>
 #include <utility>
 #include <algorithm>
 using namespace std;
 using std::vector;
 const int infty = 1000001;
 
 int solve(int N, int M, vector<std::pair<int,int>>& queries) {
     vector<vector<int>> dp(N, vector<int>(M+1, infty));
     dp[0][0] = std::abs(queries[0].second - queries[0].first);
     for (int i = 1; i < N; ++i) {
         dp[i][0] = std::min(dp[i][0],
                        abs(queries[i].first - queries[i-1].second)
                        + abs(queries[i].second - queries[i].first)
                        + dp[i-1][0]);
         int last_pos = queries[i-1].second;
         dp[i][last_pos] = std::min(dp[i][last_pos],
                               + abs(queries[i].second - queries[i].first)
                               + dp[i-1][0]);
 
         for (int p = 1; p <= M; ++p) {
             dp[i][p] = std::min(dp[i][p],
                            abs(queries[i].first - queries[i-1].second)
                            + abs(queries[i].second - queries[i].first)
                            + dp[i-1][p]);
             dp[i][last_pos] = std::min(dp[i][last_pos],
                                   abs(queries[i].first - p)
                                   + abs(queries[i].second - queries[i].first)
                                   + dp[i-1][p]);
         }
     }
 
     int result = dp[N-1][0];
     for (int p = 0; p <= M; ++p)
         result = std::min(result, dp[N-1][p]);
 
     return result;
 }
 
 int main() {
     int T;
     cin >> T;
     int M, N, Ma, Mb;
     for (int i = 0; i < T; ++i) {
         vector<std::pair<int,int>> queries;
         cin >> M >> N;
         for (int j = 0; j < N; ++j) {
             cin >> Ma >> Mb;
             queries.push_back({Ma, Mb});
         }
         int x = solve(N, M, queries);
         cout << x <<endl;
     }
 }
