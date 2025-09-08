#include <bits/stdc++.h>

using namespace std;
using LL = long long;

void solve() {
	int u, p, b, m; cin >> u >> p >> b >> m;
	vector<pair<int, string > > v;
	for (int i = 1; i <= m; ++i) {
		int c; string s; cin >> c >> s;
		v.push_back({c, s});
	}
	sort(v.begin(), v.end());
	LL cost = 0, take = 0;
	for (int i = 0; i < m; ++i) {
		if (v[i].second[0] == 'U') {
			if (u) cost += v[i].first, --u, take++;
			else if (b) cost += v[i].first, --b, take++;
		} else {
			if (p) cost += v[i].first, --p, take++;
			else if (b) cost += v[i].first, --b, take++;
		}
	}
	cout << take << " " << cost << "\n";
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t = 1; 
//    cin >> t;
    while(t--) solve();
}
