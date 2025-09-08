#include <bits/stdc++.h>

using namespace std;
using LL = long long;

void solve() {
	int n; cin >> n;
	vector<int> elsieF, elsieS, bessieF, bessieS, used(2 * n + 1);
	for (int i = 1; i <= n; ++i) {
		int x; cin >> x;
		used[x] = 1;
		if (i <= n / 2) elsieF.push_back(x);
		else elsieS.push_back(x);
	}
	for (int i = 2 * n; i >= 1; --i) {
		if (used[i]) continue;
		if ((int) bessieF.size() < n / 2) bessieF.push_back(i);
		else bessieS.push_back(i);
	}
	sort(elsieF.begin(), elsieF.end());
	sort(bessieF.begin(), bessieF.end());
	// for (auto u : elsieF) cerr << u << " ";
	// cerr << endl;
	// for (auto u : bessieF) cerr << u << ' ';
	// cerr << endl;
	int i = (int) elsieF.size() - 1, j = (int) bessieF.size() - 1, ans = 0;
	while (i >= 0) {
		if (bessieF[j] > elsieF[i]) j--, ans++;
		i--;
	}
	sort(elsieS.begin(), elsieS.end());
	sort(bessieS.begin(), bessieS.end());
	// for (auto u : elsieS) cerr << u << " ";
	// cerr << endl;
	// for (auto u : bessieS) cerr << u << " ";
	i = 0, j = 0;
	while (i < (int) elsieS.size()) {
		if (bessieS[j] < elsieS[i]) ans++, j++;
		i++;
	}
	cout << ans << "\n";
}

int main() {
	freopen("cardgame.in", "r", stdin);
	freopen("cardgame.out", "w", stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t = 1; 
//    cin >> t;
    while(t--) solve();
}
