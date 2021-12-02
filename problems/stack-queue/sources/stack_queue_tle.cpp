#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int N;
    cin >> N;
    queue<int> Q;
    for (int i = 0; i < N; i++) {
        int x;
        cin >> x;
        Q.push(x);
    }
    long long answer = 0;
    int before = 0;
    while (!Q.empty()) {
        if (Q.front() == before + 1) {
            Q.pop();
            before++;
        } else {
            int x = Q.front();
            Q.pop();
            Q.push(x);
        }
        answer += 2;
    }

    cout << answer << '\n';
}
