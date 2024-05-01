#include <bits/stdc++.h>

using namespace std;
using LL = long long;

const int N = (int) 1e5 + 5;

LL dp[N][(1 << 7) + 5];

void solve() {
	int n, p, k; cin >> n >> p >> k;
	vector<pair<LL, int > > v(n + 1);
	v[0] = {(LL)1e9 + 7, 0};
	for (int i = 1; i <= n; ++i) {
		cin >> v[i].first;
		v[i].second = i;
	}
	sort(v.rbegin(), v.rend());

	map<int, int> mp;
	int h = 0;
	for (auto [val, idx] : v) mp[idx] = h++;
	vector<vector<LL > > str(n + 1, vector<LL>(p, 0));
	for (int i = 1; i <= n; ++i) {
		for (int j = 0; j < p; ++j) {
			cin >> str[mp[i]][j];
		}
	}

	memset(dp, -1, sizeof dp);
	dp[0][0] = 0;

	for (int i = 1; i <= n; ++i) {
		for (int mask = 0; mask < (1 << p); ++mask) {
			int player = __builtin_popcount(mask);
			int free = (i - 1) - player;
			if (free < k) {
				if (dp[i - 1][mask] != -1) dp[i][mask] = dp[i - 1][mask] + v[i].first;
			} else {
				if(dp[i - 1][mask] != -1) dp[i][mask] = dp[i - 1][mask];
			}
			for (int pos = 0; pos < p; ++pos) {
				if ((mask & (1 << pos)) and (dp[i - 1][mask ^ (1 << pos)] != -1)) {
					dp[i][mask] = max(dp[i][mask], dp[i - 1][mask ^ (1 << pos)] + str[i][pos]);
				}
			}
		}
	}

	cout << dp[n][(1 << p) - 1] << "\n";
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t = 1; 
    // cin >> t;
    while(t--) solve();
}
