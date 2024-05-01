#include <bits/stdc++.h>

using namespace std;
using LL = long long;

const int N = (int) 1e5 + 5;
const LL mod = 1000000007;

LL dp[N];

void solve() {
	string s; cin >> s;
	memset(dp, 0, sizeof dp);
	dp[0] = 1;
	s = "#" + s;
	LL fre[27]{}, occ[27]{};
	for (int i = 1; i <= (int) s.size() - 1; ++i) {
		dp[i] = ((dp[i - 1] % mod) * (2LL % mod)) % mod; 
		if (occ[s[i] - 'A']) {
			dp[i] = (((dp[i] % mod) - (fre[s[i] - 'A'] % mod)) + mod) % mod;
			fre[s[i] - 'A'] = ((fre[s[i] - 'A'] % mod) + ((dp[i] % mod) - (dp[i - 1] % mod)) % mod) % mod; 
		} else fre[s[i] - 'A'] = dp[i - 1];
		occ[s[i] - 'A'] = 1;
	}
	cout << dp[(int) s.size() - 1] % mod << "\n";
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t = 1; 
    cin >> t;
    while(t--) solve();
}
