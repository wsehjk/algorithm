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
void solve() {
    int n; 
    cin >> n;
    string ans;
    while (n != 0) {
        int m = min(n, 4);
        for(int i = 0; i < m; ++i) {
            ans.push_back(i+'a');
        }
        n -= m;
    }
    cout << ans << endl;
}
int main() {
    int T;
    //cin >> T;
    T = 1;
    while (T-- != 0) {
        solve();
    }
    return 0;
}