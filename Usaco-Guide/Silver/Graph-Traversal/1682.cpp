#include <bits/stdc++.h>

using namespace std;
using LL = long long;

const int N = (int) 1e5 + 5;

vector<int> adj[2][N];
bool vis[N];

void dfs(int node, int x) {
	vis[node] = 1;
	for (auto u : adj[x][node]) {
		if (!vis[u]) dfs(u, x);
	}
}

void solve() {
	int n, m; cin >> n >> m;
	for (int i = 1; i <= m; ++i) {
		int u, v; cin >> u >> v;
		adj[0][u].push_back(v);
		adj[1][v].push_back(u); // reverse graph 
	}
	dfs(1, 0);
	for (int i = 2; i <= n; ++i) {
		if (not vis[i]) {
			cout << "NO\n";
			cout << "1 " << i << "\n";
			return;
		}
	}
	memset(vis, 0, sizeof vis);
	dfs(1, 1);
	for (int i = 2; i <= n; ++i) {
		if (!vis[i]) {
			cout << "NO\n";
			cout << i << " 1\n";
			return;
		}
	}
	cout << "YES\n";
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t = 1; 
//    cin >> t;
    while(t--) solve();
}
