/*
	UOSPC_Libary 정답 코드

	1) 입력받기

	2) 빈 자리(C) 중에 주변에 사람이 앉아있는 자리(P)가 없는 경우 count

*/
#include<iostream>

using namespace std;

bool isInside(int x, int y, int N, int M) {
	return (0 <= x && x < N && 0 <= y && y < M);
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	int N, M;
	char map[100][100] = {};

	// 1)
	cin >> N >> M;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			cin >> map[i][j];

	// 2)
	int dx[4] = { -1, 0, 1, 0 }, dy[4] = { 0, -1, 0, 1 };
	int ans = 0;
	for (int i = 0; i < N; i++){
		for (int j = 0; j < M; j++){
			bool check = true;
			if (map[i][j] == 'C') {
				for (int d = 0; d < 4; d++) {
					int nextX = i + dx[d], nextY = j + dy[d];
					if (!isInside(nextX, nextY, N, M)) continue;
					if (map[nextX][nextY] == 'P') {
						check = false;
						break;
					}
				}
				if (check) ans++;
			}
		}
	}

	cout << ans << '\n';

	return 0;
}