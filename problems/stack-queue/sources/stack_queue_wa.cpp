#include <bits/stdc++.h>

#define sz(x) (int)x.size()
#define all(x) x.begin(), x.end()
using namespace std;
using pi = pair<int, int>;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int N;
    cin >> N;
    vector<pi> arr(N);
    for (int i = 0; i < N; i++) {
        cin >> arr[i].first;
        arr[i].second = i;
    }
    sort(all(arr));
    int answer = N * 2;
    for (int i = 1; i < N; i++) {
        if (arr[i - 1].second > arr[i].second) {
            answer += (N - i) * 2;
        }
    }
    cout << answer << '\n';
}
