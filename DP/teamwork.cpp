#include <bits/stdc++.h>

using namespace std;
using LL = long long;

const int N = 1e4 + 1;
int mx[N][1001];

void solve() {
	int n, k; cin >> n >> k;
	int skill[n + 1];
	for (int i = 1; i <= n; ++i) cin >> skill[i]; 
	for (int i = 1; i <= n; ++i) {
		int cur = 0;
		for (int m = 1; m <= k; ++m) {
			if (i - m + 1 >= 1) cur = max(skill[i - m + 1], cur);
			mx[i][m] = cur;
		}
	}
	int dp[n + 1];
	memset(dp, -1, sizeof dp);
	dp[0] = 0;
	for (int i = 1; i <= n; ++i) {
		for (int m = 1; m <= k; ++m) {
			if (i - m >= 0) {
				dp[i] = max(dp[i], dp[i - m] + (m * mx[i][m]));
			}
		}
	}
	cout << dp[n] << "\n";
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("teamwork.in", "r", stdin);
    freopen("teamwork.out", "w", stdout);
    int t = 1; 
   // cin >> t;
    while(t--) solve();
}
