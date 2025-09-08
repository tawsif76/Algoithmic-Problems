#include <bits/stdc++.h>

using namespace std;
using LL = long long;

const int N = 40005;

vector<int> adj[N];
int dis[N], disFone[N], disFtwo[N];;

void bfs(int src) {
    queue<int> Q;
    Q.push(src);
    memset(dis, 0, sizeof dis);
    while (!Q.empty()) {
        auto node = Q.front(); Q.pop();
        for (int u : adj[node]) {
            if (dis[u] > 0 or u == src) continue; 
            dis[u] = dis[node] + 1;
            Q.push(u);
        }
    }
}

void solve() {
    int b, e, p, n, m; cin >> b >> e >> p >> n >> m;
    for (int i = 1; i <= m; ++i) {
        int u, v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    bfs(1);
    for (int i = 1; i <= n; ++i) disFone[i] = dis[i];
    bfs(2);
    for (int i = 1; i <= n; ++i) disFtwo[i] = dis[i];
    bfs(n);
    LL ans = (b * dis[1]) + (e * dis[2]);
    for (int i = 1; i <= n; ++i) {  
        ans = min(ans, 1LL * ((dis[i] * p) + (disFone[i] * b) + (disFtwo[i] * e)));
    }
    cout << ans << "\n";
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("piggyback.in", "r", stdin);
    freopen("piggyback.out", "w", stdout);
    int t = 1; 
 //   cin >> t;
    while(t--) solve();
}
