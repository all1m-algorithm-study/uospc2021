/*
	O(NlogN) solution_code
*/
#include<iostream>
#include<queue>

using namespace std;

int N;
int list[100000] = {};

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);



	cin >> N;
	for (int i = 0; i < N; i++)
		cin >> list[i];

	int ans = 0, curNum = 1;
	priority_queue<int> pq;

	for (int i = 0; i < N; i++) {
		if (curNum < list[i]) {
			pq.push(-list[i]);
		}
		else if (curNum == list[i]) {
			ans++;
			curNum++;
			while (!pq.empty() && curNum == -pq.top()) {
				curNum++;
				pq.pop();
			}
		}
	}

	cout << ans << '\n';

	return 0;
}
