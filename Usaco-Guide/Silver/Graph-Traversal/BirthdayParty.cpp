#include <bits/stdc++.h>

using namespace std;
using LL = long long;

const int N = 105;

bool vis[N];
int to[N][N];
int n, m;

void dfs(int node) {
	vis[node] = true;
	for (int u = 0; u < n; ++u) {
		if (!vis[u] and to[node][u]) dfs(u);
	}
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
	while (cin >> n >> m) {
		if (n == 0 and m == 0) break;
		memset(to, 0, sizeof to);
		for (int i = 1; i <= m; ++i) {
			int u, v; cin >> u >> v;
			to[u][v] = 1;
			to[v][u] = 1;
		}
		bool ok = 1;
		for (int u = 0; u < n; ++u) {
			for (int v = 0; v < n; ++v) {
				if (!to[u][v]) continue;
				to[u][v] = 0;
				to[v][u] = 0;
				memset(vis, 0, sizeof vis);
				int cnt = 0;
				for (int i = 0; i < n; ++i) {
					if (!vis[i]) dfs(i), cnt++;
				}
				if (cnt > 1) {
					ok = 0; break;
				}
				to[u][v] = 1;
				to[v][u] = 1;
			}
		}
		if (ok) cout << "No\n";
		else cout << "Yes\n";
	}
}
