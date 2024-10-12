#include <bits/stdc++.h>
using namespace std;

const int START = 0, END = 21;
int n = 10, ret;
int dice[13], v[35], horse[5], b[13];
vector<int> board[35];

bool check(int here) {
	for (int i = 1; i <= 4; ++i)
		if (horse[i] == here) return 1;
	return 0;
}

void solve() {
	int sum = 0;
	for (int i = 0; i < n; ++i) {
		if (horse[b[i]] == END) return;	// can't choose this horse, early return
		int here = horse[b[i]];
		for (int j = 0; j < dice[i]; ++j) {
			if (j == 0 && board[here].size() == 2) here = board[here][1];
			else here = board[here][0];
			if (here == END) break;		// finish
		}
		if (here != END && check(here)) return;	// already exist another horse, early return
		horse[b[i]] = here;
		sum += v[here];
	}
	ret = max(ret, sum);
}

void go(int cnt) {
	if (cnt == n) {
		memset(horse, 0, sizeof(horse));
		solve();
		return;
	}
	for (int i = 1; i <= 4; ++i) {
		b[cnt] = i;
		go(cnt + 1);
		b[cnt] = 0;
	}
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	// board
	board[0].push_back(1);
	board[1].push_back(2);
	board[2].push_back(3);
	board[3].push_back(4);
	board[4].push_back(5);
	board[5].push_back(6);
	board[5].push_back(22);
	board[6].push_back(7);
	board[7].push_back(8);
	board[8].push_back(9);
	board[9].push_back(10);
	board[10].push_back(11);
	board[10].push_back(29);
	board[11].push_back(12);
	board[12].push_back(13);
	board[13].push_back(14);
	board[14].push_back(15);
	board[15].push_back(16);
	board[15].push_back(28);
	board[16].push_back(17);
	board[17].push_back(18);
	board[18].push_back(19);
	board[19].push_back(20);
	board[20].push_back(21);
	board[22].push_back(23);
	board[23].push_back(24);
	board[24].push_back(25);
	board[28].push_back(27);
	board[27].push_back(26);
	board[26].push_back(25);
	board[29].push_back(30);
	board[30].push_back(25);
	board[25].push_back(31);
	board[31].push_back(32);
	board[32].push_back(20);
	// score
	v[1] = 2;
	v[2] = 4;
	v[3] = 6;
	v[4] = 8;
	v[5] = 10;
	v[6] = 12;
	v[7] = 14;
	v[8] = 16;
	v[9] = 18;
	v[10] = 20;
	v[11] = 22;
	v[12] = 24;
	v[13] = 26;
	v[14] = 28;
	v[15] = 30;
	v[16] = 32;
	v[17] = 34;
	v[18] = 36;
	v[19] = 38;
	v[20] = 40;
	v[22] = 13;
	v[23] = 16;
	v[24] = 19;
	v[25] = 25;
	v[26] = 26;
	v[27] = 27;
	v[28] = 28;
	v[29] = 22;
	v[30] = 24;
	v[31] = 30;
	v[32] = 35;

	for (int i = 0; i < n; ++i)
		cin >> dice[i];
	go(0);
	cout << ret;
}