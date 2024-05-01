#include <bits/stdc++.h>

using namespace std;
using LL = long long;

const int inf = (int) 1e9;

void solve() {
	int n, k; cin >> n >> k;
	int ara[n + 1], cnt0[n + 1]{}, cnt1[n + 1]{};
	for (int i = 1; i <= n; ++i) {
		cin >> ara[i];
		cnt0[i] = cnt0[i - 1] + (1 - ara[i]);
		cnt1[i] = cnt1[i - 1] + ara[i];
	}
	int dp[k + 1][n + 1];
	for (int i = 0; i <= k; ++i) {
		for (int j = 0; j <= n; ++j) {
			dp[i][j] = inf;
		}
	}
	dp[0][0] = 0;
	for (int i = 1; i <= k; ++i) {
		for (int idx = 1; idx <= n; ++idx) {
			for (int len = 1; len <= n; ++len) {
				if (idx - len >= 0) {
					int zero = cnt0[idx] - cnt0[idx - len];
					int one = cnt1[idx] - cnt1[idx - len];
 					dp[i][idx] = min(dp[i][idx], dp[i - 1][idx - len] + (zero * one));
				}
			}
		}
	}
	cout << dp[k][n] << "\n";
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t = 1; 
    // cin >> t;
    while(t--) solve();
}
