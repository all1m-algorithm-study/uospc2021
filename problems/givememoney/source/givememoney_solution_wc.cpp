/*
	O(N^2) Time Limit Code
*/
#include<iostream>

using namespace std;

int N;
int list[100000] = {};
bool opened[100001] = {};

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> N;
	for (int i = 0; i < N; i++)
		cin >> list[i];

	int ans = 0;
	for (int i = 0; i < N; i++) {
		opened[list[i]] = true;
		bool check = true;
		for (int j = 1; j <= list[i]; j++) {
			if (!opened[j]) {
				check = false;
				break;
			}
		}
		if (check) ans++;
	}

	cout << ans << '\n';

	return 0;
}
