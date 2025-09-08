#include <bits/stdc++.h>

using namespace std;
using LL = long long;

void solve() {
	int n, m; cin >> n >> m;
	vector<pair<LL, LL > > v;
	for (int i = 0; i < m; ++i) {
		LL x, y; cin >> x >> y;
		v.push_back({x, y});
	}
	sort(v.begin(), v.end());
	auto test = [&] (LL d) {
		LL nxt = v[0].first + d, cow = 1;
		for (auto [x, y] : v) {
			if (nxt < x) nxt = x;
			while (nxt <= y) {
				nxt += d;
				cow++;
			}
			if (cow >= n) break;
		}
		return cow >= n;
	};
	LL lo = 1, hi = (LL) 1e18;
	while (lo < hi) {
		LL mid = lo + (hi - lo + 1) / 2;
		if (test(mid)) lo = mid;
		else hi = mid - 1;
	}
	cout << lo << "\n";
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t = 1; 
    freopen("socdist.in", "r", stdin);
    freopen("socdist.out", "w", stdout);
//    cin >> t;
    while(t--) solve();
}
