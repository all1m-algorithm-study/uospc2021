#include <iostream>
#include <algorithm>
#include <vector>

int n1, n2;
char q1[2001], q2[2001];
char combined[4001];

int main() {
    scanf("%d %d", &n1, &n2);
    scanf("%s", q1);
    scanf("%s", q2);

    std::vector<bool> onePos(n1+n2, true);
    std::fill(onePos.begin(), onePos.begin()+n2, false);
    int answer = INT32_MAX;

    do {
        int i1 = 0, i2 = 0;
        for (int i = 0; i < n1+n2; ++i) {
            combined[i] = (onePos[i] ? q1[i1++] : q2[i2++]);
        }
        int score = 0;
        for (int i = 0; i < n1+n2-1; ++i) {
            score += (combined[i] != combined[i+1] ? 1 : 0);
        }
        answer = std::min(answer, score);
    } while (std::next_permutation(onePos.begin(), onePos.end()));

    printf("%d", answer);

    return 0;
}