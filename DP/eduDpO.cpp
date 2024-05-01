#include <bits/stdc++.h>

using namespace std;
using LL = long long;

const int N = 21;
const LL mod = (LL) 1e9 + 7;

LL dp[(1 << N) + 3];
bool adj[N + 1][N + 1];

void solve() {
	int n; cin >> n;
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= n; ++j) cin >> adj[i][j];
	}

	dp[0] = 1;

	for (int mask = 0; mask < (1 << n); ++mask) {
		int partner = __builtin_popcount(mask);
		for (int w = 0; w < n; ++w) {
			if ((mask & (1 << w)) || (!adj[partner + 1][w + 1])) continue;
			dp[mask | (1 << w)] += dp[mask];
			dp[mask | (1 << w)] %= mod;  
		}
	}

	cout << dp[(1 << n) - 1] << "\n";
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t = 1; 
//    cin >> t;
    while(t--) solve();
}
