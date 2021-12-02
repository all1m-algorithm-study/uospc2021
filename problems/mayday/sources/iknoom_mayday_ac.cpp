#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int N;
    cin >> N;
    int answer = 0;
    map<long long, int> S;
    for (int i = 1; i <= N; i++) {
        long long x;
        cin >> x;
        S[x * i]++;
    }
    for (int i = 1; i <= N; i++) {
        long long x;
        cin >> x;
        if (S[x * i]) {
            answer++;
            S[x * i]--;
        }
    }
    cout << answer << '\n';
}
