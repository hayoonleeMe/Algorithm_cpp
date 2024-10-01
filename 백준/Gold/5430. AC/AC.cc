#include <bits/stdc++.h>
using namespace std;

int t, n;
string f, ns;

deque<int> split(const string& input, const string& delimiter) {
	deque<int> result;
	if (input.size() == 2) return result;
	auto start = 1;
	auto end = input.find(delimiter, start);
	while (end != string::npos) {
		result.push_back(stoi(input.substr(start, end - start)));
		start = end + delimiter.size();
		end = input.find(delimiter, start);
	}
	result.push_back(stoi(input.substr(start, input.size() - start - 1)));
	return result;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	cin >> t;
	while (t--) {
		cin >> f >> n >> ns;
		deque<int> a = split(ns, ",");
		bool flag = 0;
		bool rev = 0;
		for (char c : f) {
			if (c == 'R') {
				rev ^= 1;
			} else {
				if (a.size()) {
					if (rev) a.pop_back();
					else a.pop_front();
				} else {
					cout << "error\n";
					flag = 1;
					break;
				}
			}
		}
		if (flag) continue;
		cout << "[";
		for (int i = 0; i < a.size(); ++i) {
			int idx = rev ? a.size() - 1 - i : i;
			cout << a[idx];
			if (i < a.size() - 1) cout << ",";
		}
		cout << "]\n";
	}
}