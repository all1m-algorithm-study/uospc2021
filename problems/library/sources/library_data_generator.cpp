/*
	UOSPC_Library 테스트케이스 생성 코드
	
	1) 1 <= N, M <= 100 사이의 숫자를 랜덤하게 생성
	2) N x M 크기의 char 배열 선언 후 테두리 'W' 으로 입력
	3) 나머지 부분에 대해서 랜덤하게 '.', 'P', 'C' 를 입력
*/
#include "testlib.h"
#include<iostream>

using namespace std;

char randChar(int c) {
	if (c == 0) return '.';
	if (c == 1) return 'P';
	if (c == 2) return 'C';
}

int main(int argc, char *argv[]) {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	registerGen(argc, argv, 1);

	// 1)
	int N = rnd.next(1, 100);
	int M = rnd.next(1, 100);

	// 2)
	char map[100][100] = {};
	for (int j = 0; j < M; j++)
		map[0][j] = map[N - 1][j] = 'W';
	for (int i = 0; i < N; i++)
		map[i][0] = map[i][M - 1] = 'W';

	// 3)
	for (int i = 1; i < N - 1; i++)
		for (int j = 1; j < M - 1; j++)
			map[i][j] = randChar(rnd.next(0, 2));

	cout << N << ' ' << M << '\n';
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cout << map[i][j] << ' ';
		}
		cout << '\n';
	}

	return 0;
}
