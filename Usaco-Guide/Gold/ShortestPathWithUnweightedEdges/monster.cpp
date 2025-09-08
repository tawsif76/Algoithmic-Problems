#include <bits/stdc++.h>

using namespace std;
using LL = long long;

const int inf = (int) 1e9;

char adj[1003][1003];
int disA[1003][1003], disM[1003][1003];
pair<int, int> par[1003][1003];
bool vis[1003][1003];

int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};
int n, m; 

void bfs(vector<pair<int, int > > &src, bool p) {
	queue<pair<int, int > > Q;
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= m; ++j) {
			if (p) disA[i][j] = inf;
			else disM[i][j] = inf;
			vis[i][j] = 0;
		}
	}
	for (auto [x, y] : src) {
		Q.push({x, y});
		vis[x][y] = 1;
		if (p) disA[x][y] = 0;
		else disM[x][y] = 0;
	}
	auto valid = [&] (int r, int c) {
		return r >= 1 and r <= n and c >= 1 and c <= m and adj[r][c] != '#' and vis[r][c] == 0;
	};

	while (!Q.empty()) {
		auto [r, c] = Q.front(); Q.pop();
		for (int i = 0; i < 4; ++i) {
			int nr = dx[i] + r, nc = dy[i] + c;
			if (!valid(nr, nc)) continue;
			if (p) disA[nr][nc] = disA[r][c] + 1;
			else disM[nr][nc] = disM[r][c] + 1;
			vis[nr][nc] = 1;
			if (p) par[nr][nc] = {r, c};
			Q.push({nr, nc});
		}
	}
}

void solve() {
	cin >> n >> m;
	pair<int, int> src, des = {-1, -1};
	vector<pair<int, int > > v;
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= m; ++j) {
			cin >> adj[i][j];
			if (adj[i][j] == 'A') v.push_back({i, j}), src = {i, j};
		}
	}
	bfs(v, 1);
	v.clear();
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= m; ++j) {
			if (adj[i][j] == 'M') v.push_back({i, j});
		}
	} 
	bfs(v, 0);
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= m; ++j) {
			if (i == 1 or j == 1 or i == n or j == m) {
				if (adj[i][j] == 'A') {
					cout << "YES\n";
					cout << "0\n";
					return;
				}
				if (adj[i][j] == '.' and (disA[i][j] < disM[i][j])) { 
					des = {i, j}; break; 
				}
			}
		}
	}
	if (des.first != -1) {
		cout << "YES\n";
		cout << disA[des.first][des.second] << "\n";
		string ans = "";
		pair<int, int> curR = par[des.first][des.second], prv = des;
		if (disA[des.first][des.second] == 0) return;
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
		cout << ans << "\n";
	} else cout << "NO\n";
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t = 1; 
 //   cin >> t;
    while(t--) solve();
}
