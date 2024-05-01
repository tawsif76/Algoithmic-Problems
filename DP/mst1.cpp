//https://www.spoj.com/problems/MST1/en/

#include <bits/stdc++.h>

using namespace std;
using LL = long long;

const int N = (int) 2e7 + 1;

int dp[N];
int tc = 1;

void solve() {
	int n; cin >> n;
	cout << "Case " << tc++ << ": ";
	cout << dp[n] << '\n';
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t = 1; 
	dp[1] = 0;
	for (int i = 2; i < N; ++i) {
		dp[i] = 1 + dp[i - 1];
		if (i % 2 == 0) dp[i] = min(dp[i], 1 + dp[i / 2]);
		if (i % 3 == 0) dp[i] = min(dp[i], 1 + dp[i / 3]);
	}
    cin >> t;
    while(t--) solve();
}
