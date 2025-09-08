#include <bits/stdc++.h>

using namespace std;
using LL = long long;

void solve() {
	int n, m; cin >> n >> m;
	int city[n + 1], tower[m + 1];
	for (int i = 1; i <= n; ++i) cin >> city[i];
	for (int i = 1; i <= m; ++i) cin >> tower[i];
	vector<int> dis(n + 1, INT_MAX);
	int v = 1;
	for (int u = 1; u <= n; ++u) {
		while (v <= m and city[u] > tower[v]) v++;
		if (v <= m) dis[u] = min(dis[u], abs(city[u] - tower[v]));
	}
	v = m;
	for (int u = n; u >= 1; --u) {
		while (v >= 1 and city[u] < tower[v]) v--;
		if (v >= 1) dis[u] = min(dis[u], abs(city[u] - tower[v]));
	}
	// for (int i = 1; i <= n; ++i) cerr << dis[i] << " \n"[i == n];
	int ans = 0;
	for (int i = 1; i <= n; ++i) ans = max(ans, dis[i]);
	cout << ans << "\n";
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t = 1; 
//    cin >> t;
    while(t--) solve();
}
