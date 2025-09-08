#include<bits/stdc++.h>
 
using namespace std;
 
int main() {
    int n, k; cin >> n >> k;
    vector<pair<int, int > > v;
    for (int i = 0; i < n; ++i) {
        int x, y; cin >> x >> y;
        v.push_back({x, y});
    }
    sort(v.begin(), v.end(), [&](pair<int, int> &x, pair<int, int> &y) {return x.second < y.second;});
//    for (auto [x, y] : v) cout << x << " " <<  y << endl;
    multiset<int> busy;
    int ans = 0;
    for (int i = 0; i < k; ++i) busy.insert(0);
    for (int i = 0; i < n; ++i) {
        auto take = busy.upper_bound(v[i].first);
        if (take == busy.begin()) continue;
        --take;
        ans++;
        busy.erase(take);
        busy.insert(v[i].second);
 
    }
    cout << ans << "\n";
}