#include <bits/stdc++.h>

using namespace std;
using LL = long long;

void solve() {
	int x1, y1, x2, y2; cin >> x1 >> y1 >> x2 >> y2;
	int n; cin >> n;
	string s; cin >> s;
	int preX[n + 1]{}, preY[n + 1]{};

	for (int i = 0; i < n; ++i) {
		if (s[i] == 'U') preY[i + 1] = 1 + preY[i], preX[i + 1] = preX[i];
		else if (s[i] == 'D') preY[i + 1] = -1 + preY[i], preX[i + 1] = preX[i];
		else if (s[i] == 'R') preX[i + 1] = 1 + preX[i], preY[i + 1] = preY[i];
		else preX[i + 1] = -1 + preX[i], preY[i + 1] = preY[i];
	}

	LL lo = 0, hi = (LL) 1e15;

	auto test = [&] (LL days) {
		LL cycle = days / n, rem = days % n;
		LL curX = cycle * preX[n] + preX[rem] + x1;
		LL curY = cycle * preY[n] + preY[rem] + y1;
		return abs(curX - x2) + abs(curY - y2) <= days;
	};

	while (lo < hi) {
		LL mid = lo + hi >> 1; 
		if (test(mid)) hi = mid;
		else lo = mid + 1;
	}

	if (hi >= (LL) 1e15) hi = -1;
	cout << hi << "\n";
} 

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t = 1; 
//    cin >> t;
    while(t--) solve();
}

