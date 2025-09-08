#include <bits/stdc++.h>

using namespace std;
using LL = long long;

void solve() {
	int n, ans = 0, box; cin >> n >> box;
	int ara[n + 1], mx = -1;
	for (int i = 1; i <= n; ++i) cin >> ara[i], mx = max(mx, ara[i]);
	for (int put = 1; put <= mx; ++put) {
		multiset<int> berrie(ara + 1, ara + n + 1);
		//- - put - - -
		//sister
		bool ok = 1;
		for (int i = 1; i <= box / 2; ++i) {
			if (berrie.empty()) {
				ok = 0;
				break;
			}
			auto take = prev(berrie.end());
			if (*take >= put) {
				berrie.erase(take);
				if (*take - put > 0) berrie.insert(*take - put);
			} else { ok = 0; break; }
		}
		if (!ok) continue;
		//berrie
		int sumB = 0;
		for (int i = box / 2 + 1; i <= box; ++i) {
			if (berrie.empty()) {
				ok = 0;
				break;
			}
			auto take = prev(berrie.end());
			int actual = min(*take, put);
			sumB += actual;
			berrie.erase(take);
			if (*take > put) berrie.insert(*take - put);
		}
		if (ok) ans = max(ans, sumB);
	}
	cout << ans << "\n";
}

int main() {
	freopen("berries.in", "r", stdin);
	freopen("berries.out", "w", stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t = 1; 
    while(t--) solve();
}
