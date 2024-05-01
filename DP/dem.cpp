#include <bits/stdc++.h>

using namespace std;
using LL = long long;

void solve() {
	int sum = 0;
	for (int i = 1; i <= 6; ++i) {
		for (int j = 1; j <= 6; ++j) {
			for (int k = 1; k <= 6; ++k) sum += ((i + j + k) < 9);
		}
	}
	cerr << sum << '\n';
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t = 1; 
//    cin >> t;
    while(t--) solve();
}
