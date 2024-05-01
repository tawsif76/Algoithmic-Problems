#include <bits/stdc++.h>

using namespace std;
using LL = long long;

const int N = 5009;
const LL mod = (LL) 1e9 + 7;

bool is_com[N];
vector<int> prime;
LL dp[N];

void sieve() {
	prime.push_back(0);
	for (int i = 2; i < N; ++i) {
		if (!is_com[i]) {
			prime.push_back(i); 
		}
		for (int j = 1; j < (int) prime.size() and 1LL * prime[j] * i < N; ++j) {
			is_com[prime[j] * i] = true;
			if (i % prime[j] == 0) break; 
		}
	}
}

LL add(LL a, LL b) {
	a += b;
	if (a >= mod) a -= mod;
	return a;
}

void solve() {
	int n, m; cin >> n >> m;
	for (int i = 0; i <= n + 3; ++i) dp[i] = 0;
	dp[0] = 1;
	for (int i = 1; i <= n + 1; i++) {
		for (int p : prime) {
			if (i - (p + 1) >= 0 and p + 1 <= m) dp[i] = add(dp[i], dp[i - (p + 1)]);
		}
	}
	cout << dp[n + 1] << "\n";
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    sieve();
    int t = 1; cin >> t;
    while(t--) solve();
}
