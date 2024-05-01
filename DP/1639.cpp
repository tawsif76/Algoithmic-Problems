#include <bits/stdc++.h>

using namespace std;
using LL = long long;

const int N = 5005;

int dp[N][N];

void solve() {
	string x, y; cin >> x >> y;
	x = "#" + x;
	y = "#" + y;
	for (int i = 0; i < (int) x.size(); ++i)
		for (int j = 0; j < (int) y.size(); ++j) dp[i][j] = 50004;
	dp[0][1] = dp[1][0] = 1;
	dp[0][0] = 0;
	for (int i = 0; i < (int) x.size(); ++i) {
		for (int j = 0; j < (int) y.size(); ++j) {
			if (i and j and x[i] == y[j]) dp[i][j] = min(dp[i][j], dp[i - 1][j - 1]);
			if (i and j) dp[i][j] = min(dp[i][j], 1 + dp[i - 1][j - 1]);
			if (i) dp[i][j] = min(dp[i][j], 1 + dp[i - 1][j]);
			if (j) dp[i][j] = min(dp[i][j], 1 + dp[i][j - 1]);
		}
	}
	cout << dp[(int) x.size() - 1 ][(int) y.size() - 1] << "\n";
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t = 1; 
    // cin >> t;
    while(t--) solve();
}
