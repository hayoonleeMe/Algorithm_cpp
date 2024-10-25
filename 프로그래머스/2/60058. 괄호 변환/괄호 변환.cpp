#include <string>
#include <vector>
#include <stack>

using namespace std;

bool check(const string& s) {
    stack<char> st;
    for (char c : s) {
        if (c == '(') st.push(c);
        else {
            if (st.size()) st.pop();
        }
    }
    return st.empty();
}

string solution(string p) {
    if (p.size() == 0) return p;
    int op = 0, cl = 0;
    string u = "", v = "";
    for (int i = 0; i < p.size(); ++i) {
        if (p[i] == '(') {
            ++op;
            u += "(";
        } else if (p[i] == ')') {
            ++cl;
            u += ")";
        }
        if (op != 0 && op == cl) {
            if (i + 1 < p.size()) v = p.substr(i + 1);
            break;
        }
    }
    if (check(u)) {
        u += solution(v);
        return u;
    }
    string temp = "(";
    temp += solution(v);
    temp += ")";
    u.erase(0, 1);
    u.erase(u.size() - 1, 1);
    string temp2 = "";
    for (char c : u)
        temp2 += c == '(' ? ")" : "(";
    temp += temp2;
    return temp;
}