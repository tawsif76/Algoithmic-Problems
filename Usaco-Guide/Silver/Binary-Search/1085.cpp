#include <bits/stdc++.h>

using namespace std;
using LL = long long;

void solve() {
	int n, k; cin >> n >> k;
	LL ara[n + 1];
	for (int i = 1; i <= n; ++i) cin >> ara[i];
	auto test = [&] (LL mxSum) {
		LL curSum = 0;
		int seg = 1;
		for (int i = 1; i <= n; ++i) {
			curSum += ara[i];
			if (curSum > mxSum) {
				seg++;
				curSum = ara[i];
				if (curSum > mxSum) return false;
			}
 		}
 		return seg <= k;
	};
	LL lo = 1, hi = accumulate(ara + 1, ara + n + 1, 0LL);
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
