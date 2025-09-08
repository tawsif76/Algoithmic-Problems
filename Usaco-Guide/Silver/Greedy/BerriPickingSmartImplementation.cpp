#include <bits/stdc++.h>

using namespace std;
using LL = long long;

int mod;

bool cmp(int &a, int &b) {
	return ((a % mod) > (b % mod));
}

void solve() {
	int N, box, mx = -1, ans = 0; cin >> N >> box;
	vector<int> berrie(N);
	for (auto &u : berrie) cin >> u, mx = max(u, mx);
	for (int put = 1; put <= mx; ++put) {
		int amount = 0;
		for (auto u : berrie) amount += u / put;
		if (amount < box / 2) continue;
		if (amount >= box) {
			ans = max(ans, (box / 2) * put);
			continue;
		}
		int sumB = 0;
		sumB += (amount - (box / 2))* put;
		mod = put;
		sort(berrie.begin(), berrie.end(), cmp);
		for (int i = 0; i < N and amount + i < box; i++) {
			sumB += berrie[i] % put;
		}
		ans = max(ans, sumB);
	}
	cout << ans << "\n";
}

int main() {
	freopen("berries.in", "r", stdin);
	freopen("berries.out", "w", stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t = 1; 
//    cin >> t;
    while(t--) solve();
}
