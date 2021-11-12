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
	int teamMemberPriority[26][26] = {}; // ['A']['a'] = A팀에서 a 지원자에 대한 선호도 ( 낮을수록 높음 )
	int teamsSize[26] = {}; // ['A'] = A팀에서 몇 명 뽑을지

	priority_queue<pair<int, char>> teamsMember[26];
	queue<char> membersTeam[26];
	queue<char> waitingList;

	cin >> T >> M >> N;

	int teamSize, teamN;
	char team, member;

	// M개의 동아리에 대한 정보
	for (int i = 0; i < M; i++) {
		cin >> team >> teamSize;
		teamsSize[team - 'A'] = teamSize;
		for (int j = 0; j < N; j++) {
			cin >> member;
			teamMemberPriority[team - 'A'][member - 'a'] = j + 1;
		}
	}

	// N명의 지원자에 대한 정보
	for (int i = 0; i < N; i++) {
		cin >> member >> teamN;
		for (int j = 0; j < teamN; j++) {
			cin >> team;
			membersTeam[member - 'a'].push(team);
		}
		waitingList.push(member);
	}

	// T일 동안 매칭 시작
	for (int i = 0; i < T; i++) {
		// 동아리에 지원하기
		while (!waitingList.empty()) {
			member = waitingList.front();
			waitingList.pop();
			if (!membersTeam[member - 'a'].empty()) {
				team = membersTeam[member - 'a'].front();
				membersTeam[member - 'a'].pop();
				teamsMember[team - 'A'].push({ teamMemberPriority[team - 'A'][member - 'a'], member });
			}
		}
		// 동아리에서 컷하기
		for (int j = 0; j < 26; j++) {
			while (teamsMember[j].size() > teamsSize[j]) {
				pair<int, char> t = teamsMember[j].top();
				teamsMember[j].pop();
				waitingList.push(t.second);
			}
		}
	}

	// 결과 출력
	for (int i = 0; i < 26; i++) {
		if (!teamsMember[i].empty()) {
			cout << char('A' + i) << ' ';
			vector<char> teamsMembers;
			while (!teamsMember[i].empty()) {
				member = teamsMember[i].top().second;
				teamsMember[i].pop();
				teamsMembers.push_back(member);
			}
			for (int j = teamsMembers.size() - 1; j > 0; j--)
				cout << teamsMembers[j] << ' ';
			cout << teamsMembers[0] << '\n';
		}
	}
}