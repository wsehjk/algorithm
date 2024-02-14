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
    long long n;
    std::cin >> n;
    std::vector<long long> vec(n, 0);
    long long sum = 0;
    for(int i = 0; i < n; ++i) {
        std::cin >> vec[i];
        sum += vec[i];
    }
    long long avg = sum/n;
    long long pre = 0;
    for(int i = 0; i < n; ++i) {
        if (vec[i] > avg) {
            pre += vec[i] - avg;
        } else if (vec[i] < avg) {
            if (vec[i] + pre < avg) {
                std::cout << "NO" << std::endl;
                return;
            }
            pre += vec[i] - avg;
        }
    }
    std::cout << "YES" << std::endl;
}
int main() {
    int T;
    std::cin >> T;
    while (T-- != 0) {
        solve();
    }
    return 0;
}