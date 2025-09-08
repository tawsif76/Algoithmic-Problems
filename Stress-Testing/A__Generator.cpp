#include <bits/stdc++.h>

using namespace std;
using ll = unsigned long long;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
 
ll rand(ll l, ll r) {
    return uniform_int_distribution<ll>(l, r) (rng);
}

char ch_rand(char l, char r) {
    return uniform_int_distribution<char>(l, r) (rng);
}


int main(int argc, char* argv[]) {
    int t = 4;
    cout << t << "\n";
    while(t--) {
        int n = rand(1, 50);
        int q = rand(1, 10);
        cout << n << " " << q << "\n";
        string s = "";
        for (int i = 0; i < n; ++i) s += ch_rand('a', 'z');
        cout << s << "\n";
        while (q--) {
            int l = rand(1, n), r = rand(1, n);
            cout << min(l, r) << " " << max(l, r) << "\n";
        }
    }
} 
