#include <bits/stdc++.h>

using namespace std;
using LL = long long;

const int N = (int) 1e5 + 5;

int n, m;
vector<pair<int, int > > adj[N];
int vis[N], wt[N], who[N], peakWt;
vector<int> curPos, curCow;

void dfs(int node) {
	vis[node] = 1;
	curPos.push_back(node);
	curCow.push_back(who[node]);
	for (auto [u, w] : adj[node]) {
		if (!vis[u] and w >= peakWt) dfs(u);
	}
}

void solve() {
	cin >> n >> m;
	bool need = 0;
	for (int i = 1; i <= n; ++i) cin >> who[i], need |= (who[i] != i);
	for (int i = 1; i <= m; ++i) {
		int u, v; cin >> u >> v >> wt[i];
		adj[u].push_back({v, wt[i]});
		adj[v].push_back({u, wt[i]});
	}

	if (!need) {
		cout << "-1\n";
		return;
	}
	
	sort(wt + 1, wt + m + 1);

	int lo = 0, hi = m;

	while (lo < hi) {
		int mid = (lo + hi + 1) >> 1;
		peakWt = wt[mid];
		memset(vis, 0, sizeof vis);
		bool nok = 0;
		for (int i = 1; i <= n; ++i) {
			if (!vis[i]) {
				curCow.clear();
				curPos.clear();
				dfs(i);
				sort(curPos.begin(), curPos.end());
				sort(curCow.begin(), curCow.end());
				for (int k = 0; k < (int) curCow.size(); k++) nok |= (curCow[k] != curPos[k]);
			}
		}
		if (!nok) lo = mid;
		else hi = mid - 1;
	}

	cout << wt[lo] << "\n";
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("wormsort.in", "r", stdin);
    freopen("wormsort.out", "w", stdout);
    int t = 1; 
//    cin >> t;
    while(t--) solve();
}
