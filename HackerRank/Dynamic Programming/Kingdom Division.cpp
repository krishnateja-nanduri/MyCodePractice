//https://www.hackerrank.com/challenges/kingdom-division/problem

#include <iostream>
#include <vector>

using namespace std;

vector<int> graph[100005];

long long mem[100005][2][2];
const int MOD = 1000000007;

long long g(int node, int parent, int index, int color, int ally) {
    
    if (index == graph[node].size()) {
        return ally;
    }
    
    int child = graph[node][index];
    
    if (child == parent) {
        return g(node, parent, index + 1, color, ally);
    }
    
    if (mem[child][color][ally] != -1) {
        return mem[child][color][ally];
    }
    
    long long res = (g(child, node, 0, color, 1) * g(node, parent, index + 1, color, 1)) % MOD;
    res = res + (g(child, node, 0, 1 - color, 0) * g(node, parent, index + 1, color, ally)) % MOD;
    
    return mem[child][color][ally] = res;
}

int main() {
    
    int n;
    cin >> n;
    
    for (int i = 0; i <= n; ++i) {
        mem[i][0][0] = mem[i][0][1] = mem[i][1][0] = mem[i][1][1] = -1;
    }
    
    for (int i = 0; i < n - 1; ++i) {
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    
    cout << (2ll * g(1, 0, 0, 0, 0)) % MOD << "\n";
    
    return 0;
}
