/*
	team festival solution_ac
*/
#include<iostream>
#include<queue>

using namespace std;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	int T, M, N;
	int teamMemberPriority[26][26] = {}; // ['A']['a'] = A������ a �����ڿ� ���� ��ȣ�� ( �������� ���� )
	int teamsSize[26] = {}; // ['A'] = A������ �� �� ������

	priority_queue<pair<int, char>> teamsMember[26];
	queue<char> membersTeam[26];
	queue<char> waitingList;

	cin >> T >> M >> N;

	int teamSize, teamN;
	char team, member;

	// M���� ���Ƹ��� ���� ����
	for (int i = 0; i < M; i++) {
		cin >> team >> teamSize;
		teamsSize[team - 'A'] = teamSize;
		for (int j = 0; j < N; j++) {
			cin >> member;
			teamMemberPriority[team - 'A'][member - 'a'] = j + 1;
		}
	}

	// N���� �����ڿ� ���� ����
	for (int i = 0; i < N; i++) {
		cin >> member >> teamN;
		for (int j = 0; j < teamN; j++) {
			cin >> team;
			membersTeam[member - 'a'].push(team);
		}
		waitingList.push(member);
	}

	// T�� ���� ��Ī ����
	for (int i = 0; i < T; i++) {
		// ���Ƹ��� �����ϱ�
		while (!waitingList.empty()) {
			member = waitingList.front();
			waitingList.pop();
			if (!membersTeam[member - 'a'].empty()) {
				team = membersTeam[member - 'a'].front();
				membersTeam[member - 'a'].pop();
				teamsMember[team - 'A'].push({ teamMemberPriority[team - 'A'][member - 'a'], member });
			}
		}
		// ���Ƹ����� ���ϱ�
		for (int j = 0; j < 26; j++) {
			while (teamsMember[j].size() > teamsSize[j]) {
				pair<int, char> t = teamsMember[j].top();
				teamsMember[j].pop();
				waitingList.push(t.second);
			}
		}
	}

	// ��� ���
	for (int i = 0; i < 26; i++) {
		if (teamsSize[i] > 0){
			cout << char('A' + i);

			vector<char> teamsMembers;
			while (!teamsMember[i].empty()) {
				member = teamsMember[i].top().second;
				teamsMember[i].pop();
				teamsMembers.push_back(member);
			}
			if (teamsMembers.empty()) {
				cout << '\n';
			}
			else {
				cout << ' ';
				for (int j = teamsMembers.size() - 1; j > 0; j--)
					cout << teamsMembers[j] << ' ';
				cout << teamsMembers[0] << '\n';
			}
		}
	}
}
