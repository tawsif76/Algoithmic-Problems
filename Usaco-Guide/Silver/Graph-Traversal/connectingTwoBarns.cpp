#include <bits/stdc++.h>

using namespace std;
using LL = long long;

const int N = (int) 1e5 + 5;

bool vis[N];
vector<int> adj[N];
int comp[N];

void dfs(int node, int cId) {
	vis[node] = 1;
	comp[node] = cId;
	// cerr << node << " " << cId << endl;
	for (auto u : adj[node]) {
		if (not vis[u]) dfs(u, cId);
	}
}

void solve() {
	int n, m; cin >> n >> m;
	for (int i = 1; i <= n; ++i) adj[i].clear(), vis[i] = 0;
	for (int i = 1; i <= m; ++i) {
		int u, v; cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	dfs(1, 1); 
	if (!vis[n]) dfs(n, n);
	for (int i = 2; i < n; ++i) {
		if (!vis[i]) dfs(i, i);
	}
	if (comp[1] == comp[n]) {
		cout << "0\n";
		return;
	}
	vector<int> compOne, compN, srcDis(n + 1, (int) 1e9), desDis(n + 1, (int) 1e9);
	for (int i = 1; i <= n; ++i) {
		if (comp[i] == 1) compOne.push_back(i);
		if (comp[i] == n) compN.push_back(i);
	}
	sort(compOne.begin(), compOne.end());
	sort(compN.begin(), compN.end());
	for (int i = 1; i <= n; ++i) {
		int nearSrc = lower_bound(compOne.begin(), compOne.end(), i) - compOne.begin();
		if (nearSrc >= (int) compOne.size()) --nearSrc;
		srcDis[comp[i]] = min(srcDis[comp[i]], abs(compOne[nearSrc] - i));
		if (nearSrc - 1 >= 0) srcDis[comp[i]] = min(srcDis[comp[i]], abs(compOne[nearSrc - 1] - i));
		int nearDes = lower_bound(compN.begin(), compN.end(), i) - compN.begin();
		if (nearDes >= (int) compN.size()) --nearDes;
		desDis[comp[i]] = min(desDis[comp[i]], abs(compN[nearDes] - i));
		if (nearDes - 1 >= 0) desDis[comp[i]] = min(desDis[comp[i]], abs(compN[nearDes - 1] - i));
	}
	LL ans = (LL) 1e16;
	for (int i = 1; i <= n; ++i) ans = min(ans, 1LL * srcDis[i] * srcDis[i] + 1LL * desDis[i] * desDis[i]);
	cout << ans << "\n";
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t = 1; 
    cin >> t;
    while(t--) solve();
}
