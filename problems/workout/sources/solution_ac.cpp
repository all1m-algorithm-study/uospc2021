/*
	UOSPC_Workout 정답 코드

	1) 입력받기

	2) -1이 아닌 입력 2개 찾아서 계산하기
*/
#include<iostream>

using namespace std;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	int N, p1 = -1, p2 = -1;
	int list[100];

	cin >> N;
	for (int i = 0; i < N; i++)
		cin >> list[i];

	for (int i = 0; i < N; i++){
		if (list[i] != -1 && p1 == -1) {
			p1 = i;
		}
		else if (list[i] != -1 && p1 != -1) {
			p2 = i;
			break;
		}
	}

	int d = (list[p2] - list[p1]) / (p2 - p1);
	list[0] = list[p1] - p1 * d;
	for (int i = 1; i < N; i++)
		list[i] = list[i - 1] + d;

	for (int i = 0; i < N; i++)
		cout << list[i] << '\n';

	return 0;
}