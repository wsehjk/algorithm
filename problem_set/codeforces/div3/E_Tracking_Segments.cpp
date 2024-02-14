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
#define maxnum 100000+100
int arr [maxnum];

void solve() {
    int n;
    int m;
    cin >> n >> m;
    vector<pii> vec(m);
    for(auto& [x, y] : vec) {
        cin >> x >> y;
    }
    int q;
    cin >> q;
    vector<int> query(q, 0);
    for(auto& a : query) {
        cin >> a;
    }
    auto check = [&](int m) -> bool{
        vector<int> nums(n, -1);
        for(int i = 0; i < m; ++i) {
          nums[query[i] - 1] = 1;
        }
        vector<int> presum(n+1, 0);
        for(int i = 0; i < n; ++i) {
            presum[i+1] = presum[i] + nums[i];
        }
        for(const auto&[l, r] : vec) {
            if (presum[r] - presum[l-1] > 0) {
                return true;
            }
        }
        return false;
    };
    int low = 1;
    int high = q+1;
    while (low < high) {
        int mid = (high-low)/2 + low;
        if(check(mid)){
            high = mid;
        }else{
            low = mid + 1;
        }
    }
    if (low == q+1) {
        cout << -1 << endl;
    } else {
        cout << low << endl;
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