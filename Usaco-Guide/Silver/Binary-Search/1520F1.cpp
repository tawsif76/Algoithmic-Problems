#include <bits/stdc++.h>

using namespace std;
using LL = long long;

void solve() {
	int n, t, k; cin >> n >> t >> k;
	int lo = 1, hi = n;
	auto ask = [&] (int l, int r) {
		cout << "? " << l << " " << r << endl;
		int val; cin >> val;
		return val;
	};
	while (lo < hi) {
		int mid = lo + hi >> 1;
		int res = mid - ask(1, mid);
		if (k - res >= 1) lo = mid + 1;
		else hi = mid;
	}
	cout << "! " << hi << endl;
}

int main() {
    int t = 1; 
//    cin >> t;
    while(t--) solve();
}
