#include <bits/stdc++.h>

using namespace std;
using LL = long long;

void solve() {
	int n; cin >> n;
	vector<pair<int, int > > v(n);//milk, cow
	for (auto &u : v) cin >> u.second >> u.first;
	sort(v.begin(), v.end());
	int i = 0, j = n - 1, ans = 0;
	while (i <= j) {
		if (v[i].second > v[j].second) v[i].second -= v[j].second, ans = max(ans, v[i].first + v[j].first), j--;
		else if (v[i].second < v[j].second) v[j].second -= v[i].second, ans = max(ans, v[i].first + v[j].first), i++;
		else ans = max(ans, v[i].first + v[j].first), i++, --j; 
	}
	cout << ans << "\n";
}

int main() {
	freopen("pairup.in", "r", stdin);
	freopen("pairup.out", "w", stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t = 1; 
//    cin >> t;
    while(t--) solve();
}
