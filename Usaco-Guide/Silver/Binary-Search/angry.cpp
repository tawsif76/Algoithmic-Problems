#include <bits/stdc++.h>

using namespace std;
using LL = long long;

void solve() {
	int n, k; cin >> n >> k;
	LL ara[n + 1];
	for (int i = 1; i <= n; ++i) cin >> ara[i];
	sort(ara + 1, ara + n + 1);
	auto test = [&](LL R) {
		int remCow = k - 1, range = ara[1] + (2 * R), i;
		for (i = 1; i <= n; ++i) {
			if (ara[i] <= range) continue;
			if (remCow == 0) break;
			remCow--;
			range = ara[i] + (2 * R);
		}
		return (i == n + 1);
	};
	LL lo = 0, hi = (LL) 1e9;
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
    freopen("angry.in", "r", stdin);
    freopen("angry.out", "w", stdout);
    int t = 1; 
//    cin >> t;
    while(t--) solve();
}
