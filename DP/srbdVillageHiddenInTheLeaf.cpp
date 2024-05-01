#include <bits/stdc++.h>

using namespace std;
using LL = long long;

const int N = 1e5 + 5;
const int NAX = (int) 1e7 + 1;

bool is_com[NAX];
vector<int> prime;

void sieve() {
	for (int i = 2; i < NAX; ++i) {
		if (!is_com[i]) {
			prime.push_back(i); 
		}
		for (int j = 0; j < (int) prime.size() and 1LL * prime[j] * i < NAX; ++j) {
			is_com[prime[j] * i] = true;
			if (i % prime[j] == 0) break; 
		}
	}
	prime.push_back(NAX);
}

struct ST {
  int tree[4 * N];
  static const int inf = 1e9;
  ST() {
    memset(tree, 0, sizeof tree);
  }
  void build(int node, int b, int e) {
    if (b == e) {
      tree[node] = 0;
      return;
    }
    int mid = (b + e) >> 1, l = node << 1, r = l | 1;
    build(l, b, mid);
    build(r, mid + 1, e);
    tree[node] = tree[l] + tree[r]; // change this
  }
  void update(int node, int b, int e, int i, int x) {
    if (b > i || e < i) return;
    if (b == e && b == i) {
      tree[node] += x; // update
      return;
    }
    int mid = (b + e) >> 1, l = node << 1, r = l | 1;
    update(l, b, mid, i, x);
    update(r, mid + 1, e, i, x);
    tree[node] = tree[l] + tree[r]; // change this
  }
  int query(int node, int b, int e, int i, int j) {
    if (b > j || e < i) return 0; // return appropriate value
    if (b >= i && e <= j) return tree[node];
    int mid = (b + e) >> 1, l = node << 1, r = l | 1;
    return (query(l, b, mid, i, j) + query(r, mid + 1, e, i, j)); // change this
  }
  int find(int node, int b, int e, int k) {
  	if (b == e) return b;
    int mid = (b + e) >> 1, l = node << 1, r = l | 1;
    if (k <= tree[l]) return find(l, b, mid, k);
    else return find(r, mid + 1, e, k - tree[l]); // change this
  }
}t;


void solve() {
	int n, q; cin >> n >> q;
	int ara[n + 1];
	t.build(1, 1, n);
	for (int i = 1; i <= n; ++i) {
		cin >> ara[i];
		if (*lower_bound(prime.begin(), prime.end(), ara[i]) == ara[i]) t.update(1, 1, n, i, 1);
	}
	while (q--) {
		int typ; cin >> typ;
		if (typ == 1) {
			int pos; cin >> pos;
			int sum = t.query(1, 1, n, 1, pos - 1);
			int is = (sum != 0);
			int ltPos = t.find(1, 1, n, sum);
			if (t.query(1, 1, n, pos + 1, n) >= 1) sum += 1 + t.query(1, 1, n, pos, pos);
			else {
				cout << max(pos - ltPos - is, 0) + (n - pos) << "\n";
				continue;
			}
			int rtPos = t.find(1, 1, n, sum);
			cout << max(pos - ltPos - is, 0) + max(rtPos - pos - 1, 0) << "\n";
		} else {
			int pos, val; cin >> pos >> val;
			if (*lower_bound(prime.begin(), prime.end(), ara[pos]) == ara[pos]) t.update(1, 1, n, pos, -1);
			if (*lower_bound(prime.begin(), prime.end(), val) == val) t.update(1, 1, n, pos, 1);
			ara[pos] = val;
		}
	}
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t = 1; 
    sieve();
    cerr << prime.size();
    // cin >> t;
    // while(t--) solve();
}
