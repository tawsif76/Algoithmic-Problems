#include <bits/stdc++.h>

using namespace std;
using LL = long long;

void solve() {
	int n, d, m; cin >> n >> d >> m;
	vector<pair<int, int > > v;
	for (int i = 0; i < m; ++i) {
		int x; cin >> x;
		v.push_back({x, i + 1});
	}
	sort(v.begin(), v.end());
	// for (auto [u, x] : v) cerr << u << " " << x << endl;
	// cerr << "----------------------------------------------\n";
	int lo = 1, hi = m;
	vector<int> ans[n + 1], final[n + 1];
	auto test = [&] (int numOfMachine) {
		for (int i = 1; i <= n; ++i) ans[i].clear();
		int cur = 0, tot = 0, day = 0;
		for (int i = 0; i < m; ) {
			int j = i;
			if (day < v[i].first) cur = 0;
			day = max(day, v[i].first);
			while (j < m and v[i].first == v[j].first) {
				if (day - v[j].first > d) return false;
				ans[day].push_back(v[j].second);
				cur++;
				tot++;
				j++;
	//			if (numOfMachine == 2) cerr << "#" << day << " " << tot << " " << cur << endl;
				if (cur == numOfMachine) cur = 0, day++;
			}
			i = j;
		}
		return tot == m;
	};
	while (lo < hi) {
		int mid = lo + (hi - lo) / 2;
		if (test(mid)) {
			hi = mid;
			for (int i = 1; i <= n; ++i) {
				final[i].clear();
				for (auto u : ans[i]) final[i].push_back(u);
			}
		}
		else lo = mid + 1;
	}
	cout << hi << "\n";
	for (int i = 1; i <= n; ++i) {
		for (auto u : final[i]) cout << u << " ";
		cout << 0 << "\n";
	}
} 

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t = 1; 
//    cin >> t;
    while(t--) solve();
}
