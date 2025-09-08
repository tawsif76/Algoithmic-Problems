#include <bits/stdc++.h>

using namespace std;
using LL = long long;

void solve() {
	int n, T; cin >> n >> T;
	int ara[n + 1];
	for (int i = 1; i <= n; ++i) cin >> ara[i];
	int lo = 1, hi = n;
	auto valid = [&] (int unit) {
		priority_queue<int> pq;
		int j = 1, time = 0;
		while (j <= unit) pq.push(-ara[j++]);
		while (!pq.empty()) {
			time += max(0, -pq.top() - time);
			pq.pop();
			if (j <= n) {
				pq.push(-(ara[j++] + time));
			}
		}
		return time <= T;
	};
	while (lo < hi) {
		int mid = (lo + hi) >> 1;
		if (valid(mid)) hi = mid;
		else lo = mid + 1;
	}
	cout << hi << "\n";
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("cowdance.in", "r", stdin);
    freopen("cowdance.out", "w", stdout);
    int t = 1; 
 //   cin >> t;
    while(t--) solve();
}
