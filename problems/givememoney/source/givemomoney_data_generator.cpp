/*
* give me money Data Generator
*/
#include "testlib.h"
#include<iostream>

using namespace std;

int N;
int list[100000] = {};
bool made[100001] = {};

int main(int argc, char* argv[]) {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	registerGen(argc, argv, 1);
	
	N = rnd.next(1, 100000);
	
	for (int i = 0; i < N; i++) {
		int cityNum = rnd.next(1, N);
		while (!made[cityNum]) {
			cityNum = rnd.next(1, N);
		}
		list[i] = cityNum;
		made[cityNum] = true;
	}
	
	cout << N << '\n';
	for (int i = 0; i < N - 1; i++)
		cout << list[i] << ' ';
	cout << list[N - 1];

	return 0;
}