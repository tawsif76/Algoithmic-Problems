#include <bits/stdc++.h>

using namespace std;
using LL = long long;

void solve() {
    int n, t; cin >> n >> t;
    int ara[n + 1];
    for (int i = 1; i <= n; ++i) cin >> ara[i];
    int u = 1, v = 1, sum = 0, ans = 0;
    while (u <= n and v <= n) {
        while (v <= n and sum + ara[v] <= t) sum += ara[v++];
        ans = max(ans, v - u);
        sum -= ara[u++];
    }
    cout << ans << "\n";
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t = 1; 
//    cin >> t;
    while(t--) solve();
}
