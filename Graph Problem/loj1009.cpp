#include <bits/stdc++.h>

using namespace std;
using LL = long long;

const int N = (int) 2e4 + 5;

vector<int> adj[N];
bool col[N], vis[N], cyc;
int tc, one, tot, least;

void dfs(int node, bool c) {
	vis[node] = 1;
	col[node] = c;
	tot++;
	if (col[node] == 1) one++;
	for (int u : adj[node]) {
		if (!vis[u]) least = 1, dfs(u, !c);
		else if (vis[u] and col[u] == col[node]) cyc = 1;
	}
}
void solve() {
	int n; cin >> n;
	for (int i = 1; i <= N - 5; ++i) adj[i].clear(), vis[i] = 0, col[i] = 0;
	for (int i = 1; i <= n; ++i) {
		int u, v; cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	int ans = 0;
	for (int i = 1; i <= N - 5; ++i) {
		if (!vis[i]) {
			tot = 0, one = 0, cyc = 0, least = 0;
			dfs(i, 0);
			if (least) ans += max(tot - one, one);
			assert(!cyc);
		}
	}
	cout << "Case " << tc++ << ": " << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t = 1; 
    cin >> t;
    tc = 1;
    while(t--) solve();
}
