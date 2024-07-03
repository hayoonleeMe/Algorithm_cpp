#include <bits/stdc++.h>
using namespace std;

int N;
deque<int> dq;

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);

	cin >> N;

	string op;
	while (N--)
	{
		cin >> op;

        int val;
        if (op == "push_front")
        {
            cin >> val;
            dq.push_front(val);
        }
        else if (op == "push_back")
        {
            cin >> val;
            dq.push_back(val);
        }
        else if (op == "pop_front")
        {
            if (dq.empty())
                cout << "-1\n";
            else
            {
                cout << dq.front() << '\n';
                dq.pop_front();
            }
        }
        else if (op == "pop_back")
        {
            if (dq.empty())
                cout << "-1\n";
            else
            {
                cout << dq.back() << '\n';
                dq.pop_back();
            }
        }
        else if (op == "size")
            cout << dq.size() << '\n';
        else if (op == "empty")
        {
            if (dq.empty())
                cout << "1\n";
            else
                cout << "0\n";
        }
        else if (op == "front")
        {
            if (dq.empty())
                cout << "-1\n";
            else
                cout << dq.front() << '\n';
        }
        else if (op == "back")
        {
            if (dq.empty())
                cout << "-1\n";
            else
                cout << dq.back() << '\n';
        }
	}
}