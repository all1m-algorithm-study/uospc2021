/*
	UOSPC_Workout Test data Generator �ڵ�

	1) 1 <= N <= 100 �̱�

	2) 0 <= M <= max(0, N - 2) �̱�
	
	3) N������ �ִ� M�� -1�� ġȯ
*/
#include "testlib.h"
#include<iostream>
#include<vector>
#include<cmath>

using namespace std;

int main(int argc, char* argv[]) {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	registerGen(argc, argv, 1);

	int N = rnd.next(2, 100);
	int M = rnd.next(0, max(0, N - 2));
	int s = rnd.next(1, 100);
	int d = rnd.next(1, 100);

	
	vector<int> schedule;
	for (int i = 0; i < N; i++) {
		if (schedule.empty()) schedule.push_back(s);
		else schedule.push_back(schedule.back() + d);
	}

	// N������ �ִ� M�� �����ϰ� �����
	for (int i = 0; i < N; i++) {
		if (M > 0 && rnd.next(0, 1) == 0) {
			schedule[i] = -1;
			M--;
		}
	}

	cout << N << '\n';
	for (int i = 0; i < N; i++)
		cout << schedule[i] << '\n';

	return 0;
}