#include <bits/stdc++.h>
using namespace std;

int n, m, ret = 1e6;
int board[53][53];
vector<pair<int, int>> house, chicken;
vector<int> b;

void combi(int start) {
	if (b.size() == m) {
		int houLen = 0;
		for (auto h : house) {
			int chiLen = 1e6;
			for (int idx : b) {
				auto cPos = chicken[idx];
				chiLen = min(chiLen, abs(cPos.first - h.first) + abs(cPos.second - h.second));
			}
			houLen += chiLen;
		}
		ret = min(ret, houLen);
		return;
	}
	for (int i = start + 1; i < chicken.size(); ++i) {
		b.push_back(i);
		combi(i);
		b.pop_back();
	}
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	cin >> n >> m;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			cin >> board[i][j];
			if (board[i][j] == 1) house.push_back({ i, j });
			else if (board[i][j] == 2) chicken.push_back({ i,j });
		}
	}

	combi(-1);
	cout << ret;
}