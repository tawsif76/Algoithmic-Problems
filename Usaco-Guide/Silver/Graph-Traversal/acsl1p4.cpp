#include <bits/stdc++.h>

using namespace std;
using LL = long long;

const int N = 25;

vector<int> adj[N];
bool vis[N];
int st;

bool dfs(int node) {
	vis[node] = 1;
	bool ok = 0;
	for (auto u : adj[node]) {
		if (!vis[u]) ok |= dfs(u);
		else if (u == st) return true;
	}
	return ok;
}

void solve() {
	int n, m; cin >> n >> m;
	for (int i = 1; i <= m; ++i) {
		int u, v, a, b; cin >> u >> v >> a >> b;
		if (a > b) adj[u].push_back(v);
		else adj[v].push_back(u); 
	}
	int ans = 0;
	for (int i = 1; i <= n; ++i) {
		memset(vis, 0, sizeof vis);
		st = i;
		ans += dfs(i) == true;
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
