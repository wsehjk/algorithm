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
// https://codeforces.com/problemset/problem/1931/E
// 提交的代码使用std::unordered_map，没有通过system test
// 要使用std::map, 或者提供哈希函数 
[[maybe_unused]] const int mod = 1e9+7;
#define fi first;
#define se second
#define ll long long
#define pii pair<int,int>
#define pb push_back
#define all(a) a.being(), a.end()
#define int64 long long 
void solve() {
    int n, x, y;
    std::cin >> n >> x >> y;
    std::map<int, std::map<int,long long>> mp;
    long long ans = 0;
    while(n--) {
        int a;
        std::cin >> a;
        //scanf("%d", &a);
        int i = a%y;
        int j = a%x;
        int k = (x-j)%x;
        if (mp.count(i) != 0 && mp[i].count(k) != 0) {
            ans += mp[i][k];
        }
        mp[i][j] ++;
    }
    std::cout << ans << std::endl;
}
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int T;
    std::cin >> T;
    while (T-- != 0) {
        solve();
    }
    return 0;
}