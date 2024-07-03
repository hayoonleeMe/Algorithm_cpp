#include <bits/stdc++.h>
using namespace std;

int T, N, M;

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);

	cin >> T;
	while (T--)
	{
		cin >> N >> M;
		vector<int> vn, vm;
		for (int i = 0; i < N; ++i)
		{
			int t;
			cin >> t;
			vn.push_back(t);
		}
		for (int i = 0; i < M; ++i)
		{
			int t;
			cin >> t;
			vm.push_back(t);
		}

		sort(vn.begin(), vn.end(), greater<int>());
		sort(vm.begin(), vm.end(), greater<int>());

		int cnt = 0;
		int mx_vm_i = 0;
		int vm_size = vm.size();
		int i = 0;
		while (i < N && mx_vm_i < M)
		{
			if (vn[i] > vm[mx_vm_i])
			{
				cnt += vm_size - mx_vm_i;
				++i;
			}
			else
				++mx_vm_i;
		}

		cout << cnt << '\n';
	}
}