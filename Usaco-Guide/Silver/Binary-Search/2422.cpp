#include <bits/stdc++.h>

using namespace std;
using LL = long long;

void solve() {
	LL n; cin >> n;
	if (n == 1) {
		cout << 1 << "\n";
		return;
	}
	LL each = n * n / 2;
	auto test = [&] (LL mid) {
		LL cnt = 0, cntmid = 0;
		//cerr << mid << endl;
		for (LL i = 1; i <= n; ++i) {
			LL idx = (mid + i - 1) / i;
			if (idx <= n) cnt += n - idx + 1;
			if (mid % i == 0 and mid / i <= n) cntmid++;
		}
		if (cntmid == 0) {
			if (cnt > (n * n - cnt)) return 1;
			else return 2;
		}
		if (cnt < each) return 2;
		if (cnt - each <= cntmid) return 3;
		else return 1;

	};
	LL lo = 1, hi = n * n;
	while (lo < hi) {
		LL mid = lo + (hi - lo + 1) / 2;
		if (test(mid) == 1) {
			//more element on right
			lo = mid;
		} else if (test(mid) == 2) {
			//more element on left;
			hi = mid - 1;
		} else {
			cout << mid << "\n";
			break;
		}
	}
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t = 1; 
 //   cin >> t;
    while(t--) solve();
}
