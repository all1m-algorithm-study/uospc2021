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
    for (int i = 0; i <= N; i++) {
        vector<int> bits(N, 0);
        fill(bits.end()-i, bits.end(), 1);
        do {
            if (solve(arr, bits)) {
                minAnswer = min(minAnswer, i);
                maxAnswer = max(maxAnswer, i);
            }
        } while (next_permutation(bits.begin(), bits.end()));
    }
    cout << maxAnswer << '\n';
    cout << minAnswer << '\n';
}
