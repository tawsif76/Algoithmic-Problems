#include <bits/stdc++.h>

using namespace std;
using LL = long long;

int convert(char c) {
	if (islower(c)) return (c - 'a');
	else return 26 + (c - 'A');
}

void solve() {
	int n, pockemon = 0, ans = INT_MAX; cin >> n;
	string s; cin >> s;
	int fre[53]{};
	for (auto u : s) fre[convert(u)]++;
	for (int i = 0; i < 53; ++i) pockemon += (fre[i] > 0);
	int i = 0, j = 0, sz = 0;
	memset(fre, 0, sizeof fre);
	while (i < n and i <= j) {
		while (j < n and sz != pockemon) {
			if (fre[convert(s[j])] == 0) sz++;
			fre[convert(s[j])]++;
			j++;
		}
		if (sz == pockemon) {
			if (j == n - 1) ans = min(ans, j - i + 1);
			else ans = min(ans, j - i);

		}
		if (fre[convert(s[i])] == 1) sz--;
		fre[convert(s[i])]--;
		i++;
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
