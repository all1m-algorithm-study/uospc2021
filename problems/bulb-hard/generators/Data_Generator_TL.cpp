#include<iostream>
#include "testlib.h"

using namespace std;

int main(int argc, char* argv[]) {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	registerGen(argc, argv, 1);

	int N = 100000;

	cout << N << '\n';
	for (int i = 0; i < N - 1; i++) {
		cout << rnd.next(0, 1) << ' ';
	}
	cout << rnd.next(0, 1) << '\n';

	return 0;
}
