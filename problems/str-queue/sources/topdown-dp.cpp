#include <iostream>
#include <algorithm>
#include <map>

std::map<char, int> CHAR2IDX = {
    { 'U', 0 },
    { 'O', 1 },
    { 'S', 2 },
    { 'P', 3 },
    { 'C', 4 }
};
int n1, n2;
char q1[2001], q2[2001];
int dp[2001][2001][5];

int getMinScore(int s1, int s2, int prev) {
    if (s1 == n1 && s2 == n2) {
        return 0;
    }
    int& result = dp[s1][s2][prev];
    if (result != -1) {
        return result;
    }

    result = INT32_MAX;
    if (s1 < n1) {
        int front1 = CHAR2IDX[q1[s1]];
        result = std::min(result, getMinScore(s1+1, s2, front1) + (front1 == prev ? 0 : 1));
    }
    if (s2 < n2) {
        int front2 = CHAR2IDX[q2[s2]];
        result = std::min(result, getMinScore(s1, s2+1, front2) + (front2 == prev ? 0 : 1));
    }

    return result;
}

int main() {
    scanf("%d %d", &n1, &n2);
    scanf("%s", q1);
    scanf("%s", q2);

    std::fill(&dp[0][0][0], &dp[0][0][0] + sizeof(dp) / sizeof(int), -1);
    int cand1 = getMinScore(1, 0, CHAR2IDX[q1[0]]);
    int cand2 = getMinScore(0, 1, CHAR2IDX[q2[0]]);
    printf("%d", std::min(cand1, cand2));

    return 0;
}