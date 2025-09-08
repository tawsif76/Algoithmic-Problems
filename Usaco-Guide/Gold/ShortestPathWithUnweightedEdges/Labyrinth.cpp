#include <bits/stdc++.h>

using namespace std;
using LL = long long;

char adj[1002][1002];
bool vis[1002][1002];
pair<int, int> par[1002][1002];

int dx[] = {-1, +1, 0, 0};
int dy[] = {0, 0, +1, -1};

void solve() {
	int n, m; cin >> n >> m;
	pair<int, int> src, des;
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= m; ++j) {
			cin >> adj[i][j];
			if (adj[i][j] == 'A') src = {i, j};
			if (adj[i][j] == 'B') des = {i, j};
		}
	}

	queue<pair<int, int > > Q;
	Q.push(src);
	vis[src.first][src.second] = 1;

	auto valid = [&] (int r, int c) {
		return r >= 1 and r <= n and c >= 1 and c <= m and adj[r][c] != '#' and vis[r][c] == 0;
	};

	while (!Q.empty()) {
		auto [r, c] = Q.front(); Q.pop();
		for (int i = 0; i < 4; ++i) {
			int nr = dx[i] + r, nc = dy[i] + c;
			if (valid(nr, nc)) {
				Q.push({nr, nc});
				par[nr][nc] = {r, c};
				vis[nr][nc] = 1;
			}
		} 
	}

	if (vis[des.first][des.second] == 0) cout << "NO\n";
	else {
		string ans = "";
		pair<int, int> curR = par[des.first][des.second], prv = des;

		auto chk = [&] (int r, int c, int x, int y) {
			if (r < c) ans += "D";
			else if (r > c) ans += "U";
			else if (x < y) ans += "R";
			else ans += "L";
		};

		while (curR != src) {
			chk(curR.first, prv.first, curR.second, prv.second);
			prv = curR;
			curR = par[curR.first][curR.second];
		}
		chk(curR.first, prv.first, curR.second, prv.second);
		reverse(ans.begin(), ans.end());
		cout << "YES\n";
		cout << (int) ans.size() << "\n";
		cout << ans << "\n";
	}
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t = 1; 
//    cin >> t;
    while(t--) solve();
}
