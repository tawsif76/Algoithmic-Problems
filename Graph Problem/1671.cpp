#include <bits/stdc++.h>

//https://cses.fi/problemset/task/1671/

using namespace std;
using LL = long long;

const int N = (int) 1e5 + 5;
const LL inf = (LL)1e15;

vector<pair<int, int > > adj[N];
LL dis[N];
int n, m;

void dijkstra() {
	dis[1] = 0;
	for (int i = 2; i <= n; ++i) dis[i] = inf;
	priority_queue<pair<LL, int>, vector<pair<LL, int > >, greater<pair<LL, int > > > pq;
	pq.push({0LL, 1});
	while (!pq.empty()) {
		auto [d, node] = pq.top(); pq.pop();
		if (dis[node] != d) continue;
		for (auto [u, wt] : adj[node]) {
			if (d + wt < dis[u]) {
				dis[u] = d + wt;
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
	}
	dijkstra();
	for (int i = 1; i <= n; ++i) cout << dis[i] << " \n"[i == n];
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t = 1; 
//    cin >> t;
    while(t--) solve();
}
