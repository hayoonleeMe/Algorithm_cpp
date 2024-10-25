#include <string>
#include <vector>
#include <algorithm>

using namespace std;

void split(const string& s, int size, vector<string>& ret) {
    int cur = 0;
    while (cur + size <= s.size()) {
        ret.push_back(s.substr(cur, size));
        cur += size;
    }
    if (cur < s.size())
        ret.push_back(s.substr(cur));
}

int solution(string s) {
    int answer = s.size();
    for (int i = 1; i <= s.size() / 2; ++i) {
        vector<string> v;
        split(s, i, v);
        string ret = "";
        string pre = v[0];
        int cnt = 1;
        for (int j = 1; j < v.size(); ++j) {
            if (pre == v[j])
                ++cnt;
            else {
                if (cnt > 1) 
                    ret += to_string(cnt);
                ret += pre;
                pre = v[j];
                cnt = 1;
            }
        }
        if (cnt > 1) 
            ret += to_string(cnt);
        ret += pre;
        answer = min(answer, (int)ret.size());
    }
    return answer;
}