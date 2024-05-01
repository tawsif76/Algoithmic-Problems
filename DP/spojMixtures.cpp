#include <bits/stdc++.h>

using namespace std;
using LL = long long;

const int mod = 100;
const int N = 105;

LL dp[N][N], cost[N][N];

int main() {
    int n; 
    while (scanf("%d", &n) != EOF) {
		LL ara[n + 1];
		for (int i = 1; i <= n; ++i) {
			scanf("%lld", &ara[i]);
		}

		for (int i = 0; i <= n; ++i) {
			for (int j = 0; j <= n; ++j) {
				dp[i][j] = (LL)1e15;
				cost[i][j] = 0;
				if (i == j) dp[i][i] = 0, cost[i][j] = ara[i];
			}
		}
		
		for (int l = n; l >= 1; --l) {
			for (int r = l; r <= n; ++r) {
				int point = -1;
				for (int seg = l; seg <= r - 1; ++seg) {
					LL cur = dp[l][seg] + dp[seg + 1][r] + (cost[l][seg] * cost[seg + 1][r]);
					if (dp[l][r] > cur) dp[l][r] = min(dp[l][r], cur), point = seg;
				}
				if (point != -1) cost[l][r] = (cost[l][point] + cost[point + 1][r]) % mod;
			}
		}

		cout << dp[1][n] << "\n";
    }
}
