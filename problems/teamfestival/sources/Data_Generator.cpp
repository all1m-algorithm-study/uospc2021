/*
	teamfestival data_generator 테스트케이스 생성 코드

*/
#include "testlib.h"
#include<iostream>
#include<vector>

using namespace std;

vector<char> pickTeamName(int M) {
	bool checked[26] = {};
	vector<char> teams;
	for (int i = 0; i < M; i++) {
		while (true) {
			int teamName = rnd.next(0, 25);
			if (!checked[teamName]) {
				checked[teamName] = true;
				teams.push_back(char('A' + teamName));
				break;
			}
		}
	}
	return teams;
}

vector<char> pickMemberName(int N) {
	bool checked[26] = {};
	vector<char> members;
	for (int i = 0; i < N; i++) {
		while (true) {
			int memberName = rnd.next(0, 25);
			if (!checked[memberName]) {
				checked[memberName] = true;
				members.push_back(char('a' + memberName));
				break;
			}
		}
	}
	return members;
}

vector<char> pickTeamMember(int N, vector<char> members) {
	bool checked[26] = {};
	vector<char> teamMember;
	for (int i = 0; i < N; i++) {
		while (true) {
			int member = rnd.next(0, N - 1);
			if (!checked[member]) {
				checked[member] = true;
				teamMember.push_back(members[member]);
				break;
			}
		}
	}
	return teamMember;
}

vector<char> pickMemberTeam(int M, vector<char> teams) {
	bool checked[26] = {};
	vector<char> memberTeam;
	for (int i = 0; i < M; i++) {
		while (true) {
			int team = rnd.next(0, M - 1);
			if (!checked[team]) {
				checked[team] = true;
				memberTeam.push_back(teams[team]);
				break;
			}
		}
	}
	return memberTeam;
}

int main(int argc, char* argv[]) {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	registerGen(argc, argv, 1);

	// 1)
	int T = rnd.next(1, 10);
	int N = rnd.next(1, 26);
	int M = rnd.next(1, 26);

	// 2) 대문자 중에 M개 뽑기
	vector<char> teams = pickTeamName(M);

	// 3) 소문자 중에 N개 뽑기
	vector<char> members = pickMemberName(N);

	// 4) 동아리 별 최대 신입 동아리원 수
	int teamSize[26] = {};
	for (char team : teams) {
		teamSize[team - 'A'] = rnd.next(1, N);
	}

	// 5) 동아리원 별 지원 동아리 수
	int memberSize[26] = {};
	for (char member : members) {
		memberSize[member - 'a'] = rnd.next(1, M);
	}

	cout << T << ' ' << M << ' ' << N << '\n';
	for (char team : teams) {
		cout << team << ' ' << teamSize[team - 'A'] << ' ';
		// 5) 동아리 별 신입 동아리원 선호도
		vector<char> teamMember = pickTeamMember(N, members);
		for (int j = 0; j < teamMember.size() - 1; j++)
			cout << teamMember[j] << ' ';
		cout << teamMember[teamMember.size() - 1] << '\n';
	}
	for (char member : members) {
		cout << member << ' ' << memberSize[member - 'a'] << ' ';
		vector<char> memberTeam = pickMemberTeam(memberSize[member - 'a'], teams);
		for (int j = 0; j < memberTeam.size() - 1; j++)
			cout << memberTeam[j] << ' ';
		cout << memberTeam[memberTeam.size() - 1] << '\n';
	}

	return 0;
}
