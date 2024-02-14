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
    std::cin >> n;
    std::vector<int> vec(n, 0);
    std::unordered_map<int, std::vector<int>> mp;
    for(int i = 0; i < n; ++i) {
        std::cin >> vec[i];
        if (mp.count(vec[i]) == 0) {
            mp[vec[i]].push_back(-1);
        }
        mp[vec[i]].push_back(i);
    }
    int ans = n+1;
    for(auto&[a, pos] : mp) {
        //std::cout << a << std::endl;
        pos.push_back(n);
        int left = -1;
        int right = n;
        for(int i = 1; i < pos.size(); ++i) {
            if (pos[i] > pos[i-1] + 1) {
                break;
            }
            left = pos[i];
        }
        for(int i = pos.size() - 2; i >= 0; --i) {
            if (pos[i] < pos[i+1] - 1) {
                break;
            }
            right = pos[i];
        }
        ans = std::min(right-left-1, ans);
    }
    ans = std::max(ans, 0);
    std::cout << ans << std::endl;
    return ;
}
int main() {
    int T;
    std::cin >> T;
    while (T-- != 0) {
        solve();
    }
    return 0;
}