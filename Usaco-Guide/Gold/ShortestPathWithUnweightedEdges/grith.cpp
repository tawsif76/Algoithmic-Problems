#include <bits/stdc++.h>

using namespace std;
using LL = long long;

const int N = 2503;
const int inf = (int) 1e9;

vector<int> adj[N];
bool vis[N];
int dis[N];
int n, m, cyc; 

void bfs(int src) {
	memset(vis, 0, sizeof vis);
	for (int i = 1; i <= n; ++i) dis[i] = inf;
	queue<int> Q;
	Q.push(src);
	vis[src] = 1;
	dis[src] = 0;
	while (!Q.empty()) {
		int node = Q.front(); Q.pop();
		for (auto u : adj[node]) {
			if (!vis[u]) {
				vis[u] = 1;
				Q.push(u);
				dis[u] = dis[node] + 1;
			} else if (dis[node] <= dis[u]) cyc = min(cyc, 1 + dis[node] + dis[u]);
		}
	}
}

void solve() {
	cyc = INT_MAX;
	cin >> n >> m;
	vector<pair<int, int > > edge;
	for (int i = 1; i <= m; ++i) {
		int u, v; cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	for (int i = 1; i <= n; ++i) bfs(i);
	if (cyc == INT_MAX) cyc = -1;
	cout << cyc << "\n";
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t = 1; 
 //   cin >> t;
    while(t--) solve();
}
