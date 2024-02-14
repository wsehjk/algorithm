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
const int mod = 1e9+7;
#define fi first;
#define se second
#define ll long long
void solve() {
    ll n;
    cin >> n;
    long long ans = 1;
    while (n != 1) {
        ans += n;
        n /= 2;
    }
    cout << ans << endl;
}

int main() {
    int T;
    cin >> T;
    while (T-- != 0) {
        solve();
    }
    return 0;
}