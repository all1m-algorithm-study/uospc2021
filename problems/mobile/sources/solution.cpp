#include <iostream>
#include <vector>
using namespace std;
#define SIZE 101

int n;
long long dp[SIZE];
vector<int> adj[SIZE];
int vis[SIZE];

long long gcd(long long a, long long b) {
    while (b != 0) {
        long long r = a%b;
        a = b;
        b = r;
    }
    return a;
}

long long lcm(long long a, long long b) {
    return a * (b / gcd(a, b));
}

void DFS(int t) {
    vis[t] = 1;
    if (adj[t].size() == 0) return;

    for (auto n: adj[t]) {
        if (vis[n] == 1) continue;
        DFS(n);
        dp[t] = lcm(dp[t], dp[n]);
    }
    dp[t] *= adj[t].size();
}

int main() {
    cin >> n;

    for (int i=0; i<n-1; i++) {
        int a,b;
        cin >> a >> b;
        adj[a].push_back(b);
    }

    for (int i=1; i<=n; i++) dp[i] = 1;

    DFS(1);
    cout << dp[1];
}
