#include <bits/stdc++.h>

using namespace std;
using LL = unsigned long long;

int tc = 1;

void solve() {
	int n, k; cin >> n >> k;
	LL dp[k][n + 1];
	memset(dp, 0, sizeof dp);
	dp[0][0] = 1;
	LL tot = 0;
	for (int sum = 1; sum < k; ++sum) {
		for (int i = 1; i <= n; ++i) {
			for (int v = 1; v <= 6; ++v) {
				if (sum - v >= 0) dp[sum][i] += dp[sum - v][i - 1];
			}
		}
		tot += dp[sum][n];
	}
	LL den = 1;
	for (int i = 1; i <= n; ++i) den *= 6ULL;
	LL neo = den - tot;
	LL g = __gcd(neo, den);
	neo /= g, den /= g;
	cout << "Case " << tc++ << ": ";
	if (neo == 0) cout << "0\n";
	else if (den == 1) cout << neo << "\n";
	else cout << neo << "/" << den << "\n";
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t = 1; 
    cin >> t;
    while(t--) solve();
}
