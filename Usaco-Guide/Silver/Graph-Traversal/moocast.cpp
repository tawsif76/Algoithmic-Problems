#include <bits/stdc++.h>

using namespace std;
using LL = long long;

const int N = 1005;

vector<int> adj[N];
bool vis[N];

struct point {
	int x, y;
};

void dfs(int node) {
	vis[node] = 1;
	for (auto u : adj[node]) {
		if (!vis[u]) dfs(u);
	}
}

void solve() {
	int n; cin >> n;
	vector<point> points(n);
	for (auto &[x, y] : points) cin >> x >> y;

	auto build = [&] (int cost) {
		for (int i = 1; i <= n; ++i) adj[i].clear();
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < n; ++j) {
				if (i == j) continue;
				int dis = abs(points[i].x - points[j].x) * abs(points[i].x - points[j].x) + abs(points[i].y - points[j].y) * abs(points[i].y - points[j].y);
				if (dis <= cost) {
					adj[i + 1].push_back(j + 1);
				}
			}
		}
	};

	int lo = 0, hi = (int) 1e9;
	while (lo < hi) {
		int mid = lo + hi >> 1;
		build(mid);
		memset(vis, 0, sizeof vis);
		int cnt = 0;
		for (int i = 1; i <= n; ++i) if (!vis[i]) dfs(i), cnt++;
		if (cnt == 1) hi = mid;
		else lo = mid + 1;
	} 
	cout << hi << "\n";
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("moocast.in", "r", stdin);
    freopen("moocast.out", "w", stdout);
    int t = 1; 
//    cin >> t;
    while(t--) solve();
}
