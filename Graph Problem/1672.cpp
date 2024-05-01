#include <bits/stdc++.h>

using namespace std;
using LL = long long;

const int N = 505;
const LL inf = (LL) 1e5;

int adj[N][N];
LL dis[N][N];

void solve() {
	int n, m, q; cin >> n >> m >> q;
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= n; ++j) {
			if (i == j) dis[i][j] = 0;
			else dis[i][j] = inf;
		}
	}
	for (int i = 1; i <= m; ++i) {
		int u, v, w; cin >> u >> v >> w;
		dis[u][v] = w;
		dis[v][u] = w;
	}
	for (int k = 1; k <= n; ++k) {
		for (int i = 1; i <= n; ++i) {
			for (int j = 1; j <= n; ++j) {
				dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
			}
		}
	}
	while (q--) {
		int u, v; cin >> u >> v;
		if (dis[u][v] == inf) cout << "-1\n";
		else cout << dis[u][v] << "\n";
	}
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t = 1; 
   // cin >> t;
    while(t--) solve();
}
