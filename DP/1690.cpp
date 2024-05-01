#include <bits/stdc++.h>

using namespace std;
using LL = long long;

const int N = 20;
const LL mod = (LL) 1e9 + 7;

LL dp[(1 << N) + 3][N + 1];
vector<int> adj[N + 1];

void solve() {
	int n, m; cin >> n >> m;
	for (int i = 1; i <= m; ++i) {
		int u, v; cin >> u >> v;
		adj[v].push_back(u);
	}

	dp[1][1] = 1;

	for (int mask = 2; mask < (1 << n); ++mask) {
		if ((mask != ((1 << n) - 1)) and (mask & (1 << (n - 1)))) continue;
		for (int city = 1; city <= n; ++city) {
			if ((mask & (1 << (city - 1))) == 0) continue;
			for (int v : adj[city]) {
				if ((mask & (1 << (v - 1))) == 0) continue;
				dp[mask][city] += dp[mask - (1 << (city - 1))][v];
				dp[mask][city] %= mod;
			}  
		}
	}

	cout << dp[(1 << n) - 1][n] << "\n";
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t = 1; 
//    cin >> t;
    while(t--) solve();
}
