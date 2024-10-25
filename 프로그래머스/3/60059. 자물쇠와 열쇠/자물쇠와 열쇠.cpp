#include <string>
#include <vector>

using namespace std;

int n, m, lock_cnt;
bool board[23][23];
vector<pair<int, int>> keys[4], locks;

void rotate(vector<pair<int, int>>& v) {
    vector<pair<int, int>> temp;
    for (const pair<int, int>& p : v) {
        temp.push_back({ m - p.second - 1, p.first });
    }
    v = temp;
}

bool solution(vector<vector<int>> key, vector<vector<int>> lock) {
    n = lock.size();
    m = key.size();
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (lock[i][j] == 0) {
                locks.push_back({ i,j });
                ++lock_cnt;
            } else board[i][j] = 1;
        }
    }
    if (lock_cnt == 0) return 1;
    vector<pair<int, int>> temp;
    for (int i = 0; i < m; ++i)
        for (int j = 0; j < m; ++j)
            if (key[i][j] == 1) temp.push_back({ i,j });
    for (int i = 0; i < 4; ++i) {
        keys[i] = temp;
        rotate(temp);
    }
    
    for (const pair<int, int>& pos_lock : locks) {
        for (int dir = 0; dir < 4; ++dir) {
            for (int b = 0; b < keys[dir].size(); ++b) {
                const pair<int, int>& base = keys[dir][b];
                int cnt = 1;
                for (int i = 0; i < keys[dir].size(); ++i) {
                    if (i == b) continue;
                    pair<int, int> delta = { keys[dir][i].first - base.first, keys[dir][i].second - base.second };
                    int ny = pos_lock.first + delta.first;
                    int nx = pos_lock.second + delta.second;
                    if (ny < 0 || ny >= n || nx < 0 || nx >= n) continue;
                    if (board[ny][nx] == 0) ++cnt;
                    else {
                        cnt = -1;
                        break;
                    }
                }
                if (cnt == lock_cnt) return 1;
            }
        }
    }

    return false;
}