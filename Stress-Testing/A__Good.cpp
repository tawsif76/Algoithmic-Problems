#include <bits/stdc++.h>

using namespace std;
using LL = long long;

// a-> 3, 5, 7, 9, 10, 15
// 4 15
const int N = 1e6 + 2;

int cnt[27][N];

void solve() {
  int n, q; cin >> n >> q;
  string s; cin >> s;
  for (int i = 1; i <= 26; ++i) {
    for (int j = 1; j <= n; ++j) cnt[i][j] = 0;
  }
  for (int i = 0; i < n; ++i) {
    cnt[s[i] - 'a' + 1][i + 1]++;
  }
  for (int i = 1; i <= 26; ++i) {
    for (int j = 1; j <= n; ++j) cnt[i][j] += cnt[i][j - 1];
  }
  while (q--) {
    int l, r; cin >> l >> r;
    int ans = 0;
    for (int i = 1; i <= 26; ++i) {
      if ((cnt[i][r] - cnt[i][l - 1]) & 1) ans++;
    }
    cout << ans << "\n";
  }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t = 1; 
    cin >> t;
    while(t--) solve();
}
