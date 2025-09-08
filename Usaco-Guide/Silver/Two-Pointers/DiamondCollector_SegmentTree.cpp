#include <bits/stdc++.h>

using namespace std;
using LL = long long;

const int N = 50006;

int n, k;
int can[N];

struct ST {
  int t[4 * N];
  static const int inf = 2e9;
  ST() {
    memset(t, 0, sizeof t);
  }
  void build(int n, int b, int e) {
    if (b == e) {
      t[n] = can[b];
      return;
    }
    int mid = (b + e) >> 1, l = n << 1, r = l | 1;
    build(l, b, mid);
    build(r, mid + 1, e);
    t[n] = max(t[l], t[r]); // change this
  }
  int query(int n, int b, int e, int i, int j) {
    if (b > j || e < i) return -inf; // return appropriate value
    if (b >= i && e <= j) return t[n];
    int mid = (b + e) >> 1, l = n << 1, r = l | 1;
    return max(query(l, b, mid, i, j), query(r, mid + 1, e, i, j)); // change this
  }
}t;


void solve() {
	cin >> n >> k;
	int ara[n + 1];
	for (int i = 1; i <= n; ++i) cin >> ara[i];
	sort(ara + 1, ara + n + 1);
	for (int i = 1; i <= n; ++i) {
		int mx = ara[i] + k;
		int ub = upper_bound(ara + i, ara + n + 1, mx) - ara;
		can[i] = ub - i;
	}
	// for (int i = 1; i <= n; ++i) cerr << can[i] << " \n"[i == n];
	t.build(1, 1, n);
	int ans = 0;
	for (int i = 1; i <= n; ++i) {
		int q = t.query(1, 1, n, can[i] + i, n);
		ans = max(ans, q + can[i]);
	}
	cout << ans << "\n";
}

int main() {
    freopen("diamond.in", "r", stdin);
    freopen("diamond.out", "w", stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int T = 1; 
//    cin >> t;
    while(T--) solve();
}
