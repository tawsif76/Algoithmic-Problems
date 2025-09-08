#include <bits/stdc++.h>

using namespace std;
using LL = long long;

void solve() {
	int n; cin >> n;
	vector<pair<int, int > > inf(n);
	for (int i = 0; i < n; ++i) cin >> inf[i].first;
	for (int i = 0; i < n; ++i) cin >> inf[i].second;

	sort(inf.begin(), inf.end());
//	for (auto [u, v] : inf) cout << u << " " << v << endl;
	double lo = 0, hi = 1e9;

	auto test = [&] (double cand) {
		double lo = 1, hi = inf[n - 1].first;
		for (int i = 0; i < 100; ++i) {
			double mid = (lo + hi) / 2.00;
			bool bad = 0;
			for (int j = 0; j < n; ++j) {
				double cover = abs(inf[j].first - mid);
				double needTime = cover / (1.00 * inf[j].second);
				if (needTime - cand > 0.00) {
					if (inf[j].first - mid >= 0.00) { lo = mid; bad = 1; break; }
					else if (inf[j].first - mid < 0.00) {hi = mid; bad = 1; break; }
				}
			}
			if (!bad) return true;
		}
		return false;
	};

	for (int i = 0; i < 100; ++i) {
		double mid = (lo + hi) / 2.00;
		if (test(mid)) hi = mid;
		else lo = mid;
	}
	cout << fixed << setprecision(6);
	cout << hi << "\n";
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t = 1; 
//    cin >> t;
    while(t--) solve();
}

// 1 2 3 4 5 6 7