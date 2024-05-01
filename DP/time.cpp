//http://www.usaco.org/index.php?page=viewproblem2&cpid=993

#include <bits/stdc++.h>

using namespace std;
using LL = long long;

void solve() {
	int n, m, c; cin >> n >> m >> c;
	vector<int> adj[n];
	int cost[n + 1];
	for (int i = 0; i < n; ++i) cin >> cost[i];
	for (int i = 1; i <= m; ++i) {
		int u, v; cin >> u >> v;
		--u, --v;
		adj[u].push_back(v);
	}
	int dp[1003][n + 1], ans = 0;
	memset(dp, -1, sizeof dp);
	dp[0][0] = 0;
	for (int days = 0; days < 1000; ++days) {
		for (int i = 0; i < n; ++i) {
			for (auto u : adj[i]) {
				if (dp[days][i] != -1) dp[days + 1][u] = max(dp[days + 1][u], dp[days][i] + cost[i]);
			}
		}
		ans = max(ans, dp[days][0] - c * days * days);
	}
	cout << ans << "\n";
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t = 1; 
    freopen("time.in", "r", stdin);
    freopen("time.out", "w", stdout);
    // cin >> t;
    while(t--) solve();
}
