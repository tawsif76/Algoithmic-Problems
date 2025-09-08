#include <bits/stdc++.h>

using namespace std;
using LL = long long;

void solve() {
	LL n, t; cin >> n >> t;
	LL ara[n + 1];
	for (int i = 1; i <= n; ++i) cin >> ara[i];
	sort(ara + 1, ara + n + 1);
	LL lo = ara[1], hi = t * ara[n];
	auto test = [&](LL peak) {
		LL taken = 0;
		for (int i = 1; i <= n; ++i) {
			if (peak < ara[i]) break;
			if (taken >= t) break;
			LL can = peak / ara[i];
			taken += can;
		}
		return taken >= t;
	};
	while (lo < hi) {
		LL mid = lo + (hi - lo) / 2;
		if (test(mid)) hi = mid;
		else lo = mid + 1;
	} 
	cout << hi << "\n";
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t = 1; 
//    cin >> t;
    while(t--) solve();
}
