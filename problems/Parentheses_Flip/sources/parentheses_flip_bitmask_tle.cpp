#include <bits/stdc++.h>

using namespace std;

bool solve(vector<int> arr, vector<int> &bits) {
    for (int i = 0; i < (int) arr.size(); i++) {
        arr[i] ^= bits[i];
    }
    int stack = 0;
    for (auto i : arr) {
        if (i == 1) {
            if (stack == 0) {
                return false;
            }
            stack--;
        } else {
            stack++;
        }
    }
    if (stack != 0) {
        return false;
    }
    return true;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int N;
    cin >> N;
    string S;
    cin >> S;
    vector<int> arr;
    for (auto c : S) {
        if (c == '(') arr.push_back(0);
        else arr.push_back(1);
    }
    int minAnswer = N, maxAnswer = 0;
    for (int i = 0; i < (1 << N); i++) {
        int cur = 0;
        vector<int> bits;
        for (int j = 0; j < N; j++) {
            if ((1 << j) & i) {
                cur++;
                bits.push_back(1);
            } else {
                bits.push_back(0);
            }
        }
        if (solve(arr, bits)) {
            minAnswer = min(minAnswer, cur);
            maxAnswer = max(maxAnswer, cur);
        }
    }
    cout << maxAnswer << '\n';
    cout << minAnswer << '\n';
}
