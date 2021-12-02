/*
	UOSPC_Libary ���� �ڵ�

	1) �Է¹ޱ�
	
	2) �� �ڸ�(C) ī��Ʈ

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
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (map[i][j] == 'C') {
				ans++;
			}
		}
	}

	cout << ans << '\n';

	return 0;
}
