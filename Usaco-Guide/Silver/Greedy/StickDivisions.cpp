#include <bits/stdc++.h>

using namespace std;
using LL = long long;

void solve() {
	int stickLen, n; cin >> stickLen >> n;
	priority_queue<int> pq;
	for (int i = 0; i < n; ++i) {
		int x; cin >> x;
		pq.push(-1 * x);
	}
	LL ans = 0;
	while ((int) pq.size() > 1) {
		int mnOne = -1 * pq.top(); pq.pop();
		int mnTwo = -1 * pq.top(); pq.pop();
		cerr << mnOne << ' ' << mnTwo << endl;
		ans += mnOne + mnTwo; 
		pq.push(-1 * (mnOne + mnTwo));
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
