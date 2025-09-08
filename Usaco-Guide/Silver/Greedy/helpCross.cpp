#include <bits/stdc++.h>

using namespace std;
using LL = long long;

void solve() {
	int n, m; cin >> n >> m;
	multiset<int> chick;
	for (int i = 0; i < n; ++i) {
		int x; cin >> x; 
		chick.insert(x);
	}
	vector<pair<int, int > > cow(m); 
	for (auto &u : cow) cin >> u.first >> u.second;
	sort(cow.begin(), cow.end(), [](pair<int, int> &p1, pair<int, int> &p2) { return p1.second < p2.second; });
	// for (auto u : cow) cerr << u.first << ' ' << u.second << "\n";
	int ans = 0;
	for (int i = 0; i < m; ++i) {
		auto who = chick.lower_bound(cow[i].first);
		if (who != chick.end() and *who <= cow[i].second) {
			ans++;
			chick.erase(chick.find(*who));
		}
	}
	cout << ans << "\n";
}

int main() {
		freopen("helpcross.in", "r", stdin);
		freopen("helpcross.out", "w", stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t = 1; 
//    cin >> t;
    while(t--) solve();
}
