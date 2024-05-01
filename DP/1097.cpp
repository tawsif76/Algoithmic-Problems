#include <bits/stdc++.h>
 
using namespace std;
using LL = long long;
 
const int N = 5005;
const LL inf = (LL)1e14;
 
LL dp[N][N];
 
void solve() {
	int n; cin >> n;
	int ara[n + 1];
	LL sum = 0;
	for (int i = 1; i <= n; ++i) cin >> ara[i], sum += ara[i];
 
	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= n; ++j) dp[i][j] = -inf;
 
	for (int l = n; l >= 1; --l) {
		for (int r = l; r <= n; ++r) {
			if (l == r) dp[l][r] = ara[l];
			else {
				dp[l][r] = max(ara[l] - dp[l + 1][r], dp[l][r]);
				dp[l][r] = max(ara[r] - dp[l][r - 1], dp[l][r]);
			}
		}
	}
 
	cout << (sum + dp[1][n]) / 2 << "\n";
}
 
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t = 1; 
    // cin >> t;
    while(t--) solve();
}