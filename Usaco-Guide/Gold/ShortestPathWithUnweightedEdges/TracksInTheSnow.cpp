#include <bits/stdc++.h>

using namespace std;
using LL = long long;

const int inf = (int) 1e9;

int dx[] = {-1, +1, 0, 0};
int dy[] = {0, 0, +1, -1};

char adj[4002][4002];
int dis[4002][4002];

void solve() {
	int n, m; cin >> n >> m;
	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= m; ++j) cin >> adj[i][j], dis[i][j] = inf;
	deque<pair<int , int > > dq;
	dq.push_front({1, 1});
	dis[1][1] = 1;

	auto valid = [&] (int r, int c) {
		return r >= 1 and r <= n and c >= 1 and c <= m and adj[r][c] != '.';
	};

	int ans = 0;

	while (!dq.empty()) {
		auto [r, c] = dq.front(); dq.pop_front();
		ans = max(ans, dis[r][c]);
		//cerr << r << " " << c << endl;
		for (int i = 0; i < 4; ++i) {
			int nr = dx[i] + r, nc = dy[i] + c;
			if (!valid(nr, nc)) continue;
			int wt;
			if (adj[nr][nc] == adj[r][c]) {
				wt = 0;
			} else wt = 1;
			if (dis[r][c] + wt < dis[nr][nc]) {
				dis[nr][nc] = wt + dis[r][c];
				if (wt == 0) dq.push_front({nr, nc});
				else dq.push_back({nr, nc});
			}
		}
	}
	cout << ans << "\n";
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t = 1; 
//    cin >> t;
    while(t--) solve();
}
