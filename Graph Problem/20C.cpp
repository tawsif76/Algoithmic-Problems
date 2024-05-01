#include <bits/stdc++.h>

using namespace std;
using LL = long long;

const int N = (int) 1e5 + 5;
const LL inf = (LL)1e12;

vector<pair<int, int > > adj[N];
LL dis[N];
int n, m, link[N]; 

void dijkstra() {
	for (int i = 1; i <= n; ++i) dis[i] = inf;
	dis[1] = 0;
	priority_queue<pair<LL, int>, vector<pair<LL, int > >, greater<pair<LL, int > > > pq;
	pq.push({0LL, 1});
	while (!pq.empty()) {
		auto [d, node] = pq.top(); pq.pop();
		if (dis[node] != d) continue;
		for (auto [u, wt] : adj[node]) {
			if (d + wt < dis[u]) {
				dis[u] = d + wt;
				link[u] = node;
				pq.push({dis[u], u});
			}
		}
	}
}

void solve() {
	cin >> n >> m;
	for (int i = 1; i <= m; ++i) {
		int u, v, w; cin >> u >> v >> w;
		adj[u].push_back({v, w});
		adj[v].push_back({u, w});
	}
	dijkstra();
	if (dis[n] == inf) {
		cout << "-1\n";
		return;
	}
	vector<int> path;
	int cur = n;
	while (cur != 1) path.push_back(cur), cur = link[cur];
	path.push_back(1);
	reverse(path.begin(), path.end());
	for (int u : path) cout << u << " ";
	cout << "\n";
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t = 1; 
//    cin >> t;
    while(t--) solve();
}
