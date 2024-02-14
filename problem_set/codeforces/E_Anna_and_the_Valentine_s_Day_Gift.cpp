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
// Anna 为了赢，会尽可能翻转末尾0多的数字
// Sasha 为了赢，会尽可能保留数字的位数，将末尾0多的数字和末尾不为0的数字合并
// num >= 10^m, num的位数至少为m+1, 如m=3, 任何3位数都小于1000，
[[maybe_unused]] const int mod = 1e9+7;
#define fi first;
#define se second
#define ll long long
#define pii pair<int,int>
#define pb push_back
#define all(a) a.being(), a.end()
#define int64 long long 
void solve() {
    int n, m;
    std::cin >> n >> m;
    std::vector<int> zeros;
    long long sum = 0;
    for(int i = 0; i < n; ++i) {
        int a;
        std::cin >> a;
        if (a%10 == 0) {
            zeros.push_back(a);
        } else {
            sum += std::to_string(a).size();
        }
    }
    auto get = [](int a) -> int{
        int num = 0;
        while(a%10 == 0) {
            num ++;
            a/=10;
        }
        return num;
    };
    sort(zeros.begin(), zeros.end(), [&](const int&a, const int& b)
        {
            return get(a) < get(b);
        });
    int i = 0;
    while(zeros.empty() == false) {
        int a = zeros.back();
        zeros.pop_back();
        if (i == 0) {
            while(a%10 == 0) {
                a/=10;
            }
        }
        sum += std::to_string(a).size();
        i ^= 1;
    }
    if (sum > m) {
        std::cout << "Sasha" << std::endl;
    } else{
        std::cout << "Anna" << std::endl;
    }
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