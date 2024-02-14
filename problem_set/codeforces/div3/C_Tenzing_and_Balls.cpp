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

[[maybe_unused]] const int mod = 1e9+7;
#define fi first;
#define se second
#define ll long long
#define pii pair<int,int>
#define pb push_back
#define all(a) a.being(), a.end()
#define int64 long long 
[[maybe_unused]] const int maxnum = 1e6+7;
void solve() {
    int n;
    cin >> n;
    int memo[n+1];
    int arr[n];
    int dp[n+1];
    dp[0] = 0;
    for(int i = 1; i<=n; ++i) {
        memo[i] = mod;
        cin >> arr[i-1];
    }
    for(int i = 0; i < n; ++i) {
        dp[i+1] = min(dp[i]+1, memo[arr[i]]);
        memo[arr[i]] = min(memo[arr[i]], dp[i]);
    }
    cout << n - dp[n] << endl;
}
int main() {
    int T;
    cin >> T;
    while (T-- != 0) {
        solve();
    }
    return 0;
}