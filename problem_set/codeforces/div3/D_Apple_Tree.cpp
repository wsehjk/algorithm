#include <algorithm>
#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <stack>
#include <queue>
#include <functional>

using namespace std;
[[maybe_unused]]const int mod = 1e9+7;
#define fi first;
#define se second
#define ll long long
void solve() {
    int n;
    cin >> n;
    vector<int> edge[n+1];
    int u;
    int v;
    for(int i = 1; i < n; ++i) { // n-1
        cin >> v >> u;
        edge[u].push_back(v);
        edge[v].push_back(u);
    }
    vector<ll> arr(n+1, 0);
    std::function<void(int, int)> dfs = [&](int f, int last) {
        // cout << __PRETTY_FUNCTION__ << endl;
        int ans = 0;
        for(const auto& a : edge[f]) {
            if (a == last) {
                continue;
            }
            dfs(a, f);
            ans += arr[a];
        }
        if (ans == 0) {
            ans = 1;
        }
        arr[f] = ans;
        return ;
    };
    dfs(1, -1);
    int q;
    cin >> q;
    while (q -- != 0) {
        int x;
        int y;
        cin >> x >> y;
        cout << arr[x]*arr[y] << endl;
    }
}
int main() {
    int T;
    cin >> T;
    while (T-- != 0) {
        solve();
    }
    return 0;
}