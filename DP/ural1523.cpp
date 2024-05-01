#include <bits/stdc++.h>

using namespace std;
using LL = long long;

const int N = (int) 2e4 + 1;
const int mod = (int) 1e9;

LL dp[N][11];
int n, k;

struct ST {
  LL tree[4 * N][11];
  static const int inf = 1e9;
  ST() {
    memset(tree, 0, sizeof tree);
  }
  void build(int node, int b, int e) {
    if (b == e) {
      for (int i = 1; i <= k; ++i) tree[node][i] = 0;
      return;
    }
    int mid = (b + e) >> 1, l = node << 1, r = l | 1;
    build(l, b, mid);
    build(r, mid + 1, e);
    for (int i = 1; i <= k; ++i) tree[node][i] = (tree[l][i] + tree[r][i]) % mod; // change this
  }
  void update(int node, int b, int e, int i, int x, int len) {
    if (b > i || e < i) return;
    if (b == e && b == i) {
      tree[node][len] = (tree[node][len] + x) % mod; // update
      return;
    }
    int mid = (b + e) >> 1, l = node << 1, r = l | 1;
    update(l, b, mid, i, x, len);
    update(r, mid + 1, e, i, x, len);
    tree[node][len] = (tree[l][len] + tree[r][len]) % mod; // change this
  }
  LL query(int node, int b, int e, int i, int j, int len) {
    if (b > j || e < i) return 0; // return appropriate value
    if (b >= i && e <= j) return tree[node][len] % mod;
    int mid = (b + e) >> 1, l = node << 1, r = l | 1;
    return ((query(l, b, mid, i, j, len) % mod) + (query(r, mid + 1, e, i, j, len) % mod)) % mod; // change this
  }
}t;

void solve() {
	cin >> n >> k;
	int ara[n + 1];
	t.build(1, 1, n);
	for (int i = 1; i <= n; ++i) cin >> ara[i];
	for (int i = n; i >= 1; --i) {
		dp[i][1] = 1;
		t.update(1, 1, n, ara[i], 1, 1);
		for (int len = 2; len <= min(k, ara[i]); ++len) {
			LL sum = t.query(1, 1, n, len - 1, ara[i] - 1, len - 1);
			dp[i][len] = sum % mod;
			t.update(1, 1, n, ara[i], dp[i][len], len);
		}
	}
	LL ans = 0;
	for (int i = 1; i <= n; ++i) ans = (ans + dp[i][k]) % mod;
	cout << ans << "\n";
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t = 1; 
    // cin >> t;
    while(t--) solve();
}
