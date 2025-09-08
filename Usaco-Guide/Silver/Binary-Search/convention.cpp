#include <bits/stdc++.h>

using namespace std;
using LL = long long;

void solve() {
	int n, m, c; cin >> n >> m >> c;
	int ara[n + 1];
	for (int i = 1; i <= n; ++i) cin >> ara[i];
	sort(ara + 1, ara + n + 1);
	auto test = [&] (int mxTime) {
		int curCow = 1, lcow = 1, bus = 0;
		while (curCow <= n) {
			if (lcow == curCow) bus++;
			if (ara[curCow] - ara[lcow] > mxTime) lcow = curCow;
			else if (curCow - lcow + 1 == c) lcow = ++curCow;
			else curCow++;
		}
		return bus <= m;
	};
	int lo = 0, hi = ara[n] - ara[1];
	while (lo < hi) {
		int mid = (lo + hi) >> 1;
		cerr << mid << " " << test(mid) << endl;
		if (test(mid)) hi = mid;
		else lo = mid + 1;
	}
	cout << hi << "\n";
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
 	freopen("convention.in", "r", stdin);
 	freopen("convention.out", "w", stdout);
    int t = 1; 
  //  cin >> t;
    while(t--) solve();
}
