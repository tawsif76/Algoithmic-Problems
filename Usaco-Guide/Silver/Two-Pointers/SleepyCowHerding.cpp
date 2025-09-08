#include <bits/stdc++.h>

using namespace std;
using LL = long long;

const int N = (int) 1e5 + 4;

int n;
int ara[N];

int searchOne() {
	int i = 1, j = 1, best = INT_MAX;
	while (i <= n and j <= n) {
		while (j + 1 <= n and ara[j + 1] - ara[i] + 1 <= n) j++;
		best = min(best, n - (j - i + 1));
		i++;
	}	
	return best;
}

void solve() {
	cin >> n;
	for (int i = 1; i <= n; ++i) cin >> ara[i];
	sort(ara + 1, ara + n + 1);
	int mn = INT_MAX;
	if (ara[n - 1] - ara[1] == n - 2 and ara[n] - ara[n - 1] > 2) mn = 2;
	else if (ara[n] - ara[2] == n - 2 and ara[2] - ara[1] > 2) mn = 2;
	else mn = min(mn, searchOne());
	int totGap = 0;
	for (int i = 1; i <= n - 1; ++i) totGap += (ara[i + 1] - ara[i] - 1);
	cout << mn << "\n" << max(totGap - (ara[2] - ara[1] - 1), totGap - (ara[n] - ara[n - 1] - 1)) << "\n";
}

int main() {
    freopen("herding.in", "r", stdin);
    freopen("herding.out", "w", stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int T = 1; 
//    cin >> t;
    while(T--) solve();
}
