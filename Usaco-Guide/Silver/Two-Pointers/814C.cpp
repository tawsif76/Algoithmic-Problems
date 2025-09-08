#include <bits/stdc++.h>

using namespace std;
using LL = long long;

const int N = (int) 2e5 + 1;
int fre[27][N];

void solve() {
	int n; cin >> n;
	memset(fre, 0, sizeof fre);
	string s; cin >> s;
	for (int ch = 0; ch < 26; ++ch) {
		int cnt = 0;
		for (int i = n - 1; i >= 0; --i) {
			if ((s[i] - 'a') == ch) cnt++;
			else cnt = 0;
			fre[ch][i] = cnt;
			//cerr << char(ch + 'a') << "  " << i << " " << fre[ch][i] << endl;;
		}
	}
	int q; cin >> q;
	while (q--) {
		int m, ans = 0; char fav; cin >> m >> fav;
		int i = 0, j = 0, usedCol = 0;
		while (i < n and j < n) {
			while (usedCol < m and j < n) {
				if (s[j] != fav) usedCol++;
				j++; 
			}
			if (j == n) ans = max(ans, j - i + min(i, m - usedCol));
			else ans = max(ans, j - i + fre[fav - 'a'][j]);
			if (s[i] != fav) usedCol--;
			i++;
		}
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
