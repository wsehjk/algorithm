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
    int n;
    cin >> n;
    vector<int> arr(n,0);
    for(int i = 0; i < n; ++i)  {
        cin >> arr[i];
    }
    sort(arr.begin(), arr.end());
    int ans = 0;
    for(int l = 0, r = n-1; l < r; ++l, --r) {
        ans += arr[r] - arr[l];
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