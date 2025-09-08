#include <bits/stdc++.h>

using namespace std;
using LL = long long;

const int N = (int) 1e5 + 5;
vector<int> adj[N];
bool vis[N];

struct point {
	int x, y;
};

int mnX, mxX, mnY, mxY;
int n, m; 
vector<point> cord;

void dfs(int node) {
	vis[node] = true;
	mnX = min(mnX, cord[node].x);
	mnY = min(mnY, cord[node].y);
	mxX = max(mxX, cord[node].x);
	mxY = max(mxY, cord[node].y);
	for (auto u : adj[node]) {
		if (!vis[u]) dfs(u);
	}
}

void solve() {
	cin >> n >> m;
	for (int i = 0; i < n; ++i) {
		int u, v; cin >> u >> v;
		cord.push_back({u, v});
	}
	for (int i = 1; i <= m; ++i) {
		int u, v; cin >> u >> v;
		--u, --v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	int ans = INT_MAX;
	for (int i = 0; i < n; ++i) {
		if (!vis[i]) {
			mnX = mnY = INT_MAX;
			mxX = mxY = INT_MIN;
			dfs(i);
			ans = min(ans, (2 * (mxX - mnX)) + (2 * (mxY - mnY))); 
		}
	}
	cout << ans << "\n";
} 

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("fenceplan.in", "r", stdin);
    freopen("fenceplan.out", "w", stdout);
    int t = 1; 
//    cin >> t;
    while(t--) solve();
}
