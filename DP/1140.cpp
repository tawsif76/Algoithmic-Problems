#include <bits/stdc++.h>

using namespace std;
using LL = long long;

const int N = (int) 4e5 + 20;

vector<pair<int, LL > > dt[N];
LL dp[N];
int n;

struct inf {
	int l, r;
	LL p;
};

struct ST {
  LL tree[4 * N];
  ST() {
    memset(tree, 0, sizeof tree);
  }
  void update(int node, int b, int e, int i, LL x) {
    if (b > i || e < i) return;
    if (b == e && b == i) {
      tree[node] = x; // update
      return;
    }
    int mid = (b + e) >> 1, l = node << 1, r = l | 1;
    update(l, b, mid, i, x);
    update(r, mid + 1, e, i, x);
    tree[node] = max(tree[l], tree[r]); // change this
  }
  LL query(int node, int b, int e, int i, int j) {
    if (b > j || e < i) return 0LL; // return appropriate value
    if (b >= i && e <= j) return tree[node];
    int mid = (b + e) >> 1, l = node << 1, r = l | 1;
    return max(query(l, b, mid, i, j), query(r, mid + 1, e, i, j)); // change this
  }
}t;

void solve() {
	cin >> n;
	vector<inf> v(n);
	vector<int> all;
	for (int i = 0; i < n; i++) {
		cin >> v[i].l >> v[i].r >> v[i].p;
		all.push_back(v[i].l);
		all.push_back(v[i].r);
	}
	sort(all.begin(), all.end());
	all.erase(unique(all.begin(), all.end()), all.end());

	auto compress = [&] (int X) {
		return lower_bound(all.begin(), all.end(), X) - all.begin() + 1;
	};

	for (auto [x, y, z] : v) dt[compress(x)].push_back({compress(y), z});

	for (int L = 2 * n; L >= 1; --L) {
		for (auto [R, P] : dt[L]) {
			dp[L] = max(dp[L], t.query(1, 1, 2 * n, R + 1, 2 * n) + P);
		}
		dp[L] = max(dp[L], t.query(1, 1, 2 * n, L, 2 * n));
		t.update(1, 1, 2 * n, L, dp[L]);
	}
	cout << dp[1] << "\n";
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t = 1; 
    // cin >> t;
    while(t--) solve();
}
