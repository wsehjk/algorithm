#include <algorithm>
#include<iostream>
#include <ratio>
#include <vector>
using namespace std;
const int maxnum = 1e7+ 1;
vector<int> isprime(maxnum, 1);
vector<int> primes;
int init = []() {
    for(int i = 2; i < maxnum; ++i) {
        if (isprime[i]) {
            primes.push_back(i);
        }
        for(const auto& p : primes) {
            if (p >= maxnum/i)  {
                break;
            }
            isprime[p*i] = 0;
            if (i%p == 0)
                break;
        }
    }
    return 0;
}();
void solve() {
    int l;
    int r;
    cin >> l >> r;
    int o = r - r%2; // 偶数
    if (o < l) { // l == r and l 是奇数
        if (l <= 3) {
            cout << -1 << endl;
            return ;
        }
        auto it = lower_bound(primes.begin(), primes.end(), l);
        if (*it == l) {
            cout << -1 << endl;
            return ;
        }
        for(const auto& a : primes) {
            if (l%a == 0 && l != a) {
                int k = l/a;
                cout << a << " " << a*(k-1) << endl;
                return ;
            }
        }
    }else { // o <= r
        if (o == 2) {
            cout << -1 << endl;
        }
        else {
            o /= 2;
            cout << 2 << " " << 2*(o-1) << endl;
        }
    }
}
int main() {
    int t;
    cin >> t;
    while (t -- != 0) {
        solve();
    }
}