#include<iostream>
#include<numeric>
using namespace std;
void solve() {
    int n, x, y;
    cin >> n >> x >> y;
    int a = n/x;
    int b = n/y;
    int c = (1LL*n)/((1LL*x*y)/std::gcd(x,y));
    long long ans = 0;
    if (a >= c) {
        int l = a - c;
        ans += (1LL*(n - l + 1 + n)*l)/2;
    }
    int l = b - c;
    ans -= (1LL*(l+1)*l)/2;
    cout << ans << endl;
}

int main() {
    int t;
    cin >> t;
    while (t --) {
        solve();
    }
}