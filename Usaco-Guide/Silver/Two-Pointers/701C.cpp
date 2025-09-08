#include <bits/stdc++.h>

using namespace std;
using LL = long long;

void solve() {
	int n, ans = INT_MAX; cin >> n;
	string s; cin >> s;
	map<char, vector<int > > mp;
	vector<int> v[53];
	for (int i = 0; i < n; ++i) {
		if (islower(s[i])) v[s[i] - 'a'].push_back(i);
		else v[26 + (s[i] - 'A')].push_back(i);
	}
	for (int i = 0; i < n; ++i) {
		int left = i, rt = i, cur;
		if (islower(s[i])) cur = s[i] - 'a';
		else cur = 26 + (s[i] - 'A');
		for (int k = 0; k < 53; ++k) {
			if (k == cur or v[k].empty()) continue;
			int lb = lower_bound(v[k].begin(), v[k].end(), i) - v[k].begin();
//			cerr << k << " " << lb << endl;
			if (lb == (int) v[k].size()) left = min(left, v[k][(int) v[k].size() - 1]);
			else rt = max(rt, v[k][lb]); 
		}
		ans = min(ans, rt - left + 1);
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