#include <bits/stdc++.h>

using namespace std;
using LL = long long;

//https://atcoder.jp/contests/dp/tasks/dp_g?lang=en

const int N = (int) 2e5 + 5;

vector<int> adj[N];
bool vis[N];
int dp[N];

void dfs(int node) { 
	vis[node] = 1;
	vector<int> child;
	for (auto u : adj[node]) {
		if (!vis[u]) dfs(u);
		child.push_back(u);
	}
	if (child.empty()) dp[node] = 1;
	else {
		for (int u : child) dp[node] = max(dp[node], dp[u] + 1);
	}
}

void solve() {
	int n, m; cin >> n >> m;
	for (int i = 1; i <= m; ++i) {
		int u, v; cin >> u >> v;
		adj[u].push_back(v);
	}
	for (int i = 1; i <= n; ++i) {
		if (!vis[i]) dfs(i);
	}
	int ans = -1;
	for (int i = 1; i <= n; ++i) ans = max(ans, dp[i] - 1);

	cout << ans << "\n";
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t = 1; 
    // cin >> t;
    while(t--) solve();
}
