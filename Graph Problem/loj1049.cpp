#include <bits/stdc++.h>

using namespace std;
using LL = long long;

const int N = 104;

vector<pair<int, int > > adj[N];
bool vis[N];
int cost, tc;

void dfs(int node) {
	vis[node] = 1;
	for (auto [u, w] : adj[node]) {
		if (!vis[u]) cost += w, dfs(u);
	}
}

void solve() {
	int n; cin >> n;
	for (int i = 1; i <= n; ++i) adj[i].clear(), vis[i] = 0;
	for (int i = 1; i <= n; ++i) {
		int u, v, w; cin >> u >> v >> w;
		adj[u].push_back({v, 0});
		adj[v].push_back({u, w});
	}
	int ans = INT_MAX;
	auto [curNode, wt] = adj[1].back();
	adj[1].pop_back();
	cost = 0;
	dfs(1);
	for (auto [u, w] : adj[curNode]) {
		if (u == 1) { cost += w; break; }
	}
	ans = min(ans, cost);
	memset(vis, 0, sizeof vis);
	int agNode = adj[1].back().first;
	adj[1].pop_back();
	adj[1].push_back({curNode, wt});
	cost = 0;
	dfs(1);
	for (auto [u, w] : adj[agNode]) {
		if (u == 1) { cost += w; break; }
	}
	ans = min(ans, cost);
	cout << "Case " << tc++ << ": " << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t = 1; 
    tc = 1;
    cin >> t;
    while(t--) solve();
}
