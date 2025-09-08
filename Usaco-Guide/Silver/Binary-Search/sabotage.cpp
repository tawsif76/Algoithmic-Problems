#include <bits/stdc++.h>

using namespace std;
using LL = long long;

void solve() {
	int n; cin >> n;
	int ara[n + 1], pre[n + 1]{};
	for (int i = 1; i <= n; ++i) {
		cin >> ara[i];
		pre[i] = pre[i - 1] + ara[i];
	}
	auto test = [&] (double x) {
		double mnI = 1e9, overall = 1e9;
		for (int i = 2; i <= n - 1; ++i) {
			mnI = min(mnI, (1.00 * pre[i - 1]) - (1.00 * x * (i - 1)));
			double val = mnI + ((1.00 * i * x) - (1.00 * pre[i]));
			overall = min(overall, val);
		}
		return overall + (1.00 * pre[n]) - (1.00 * n * x) <= 0.0;
	};
	double lo = 1.00, hi = 1e5;
	for (int i = 0; i < 100; ++i) {
		double mid = (lo + hi) / 2.00;
		if (test(mid)) hi = mid;
		else lo = mid;
	}
	cout << fixed << setprecision(3);
	cout << lo << "\n";
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("sabotage.in", "r", stdin);
    freopen("sabotage.out", "w", stdout);
    int t = 1; 
//    cin >> t;
    while(t--) solve();
}
