#include <iostream>
#include <vector>
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> vec(n);
    vector<int> prefix;
    prefix.push_back(0);
    for(auto&a : vec)  {
        cin >> a ;
        int b = prefix.back();
        prefix.push_back(b^a); 
    }
    string s;
    cin >> s;
    int a = 0;
    int b = 0;
    for(int i = 0; i < n; ++i) {
        if (s[i] == '0') {
            a ^= vec[i];
        }
        else {
            b ^= vec[i];
        }
    }
    int q;
    cin >> q;
    while (q -- != 0) {
        int i;
        cin >> i;
        if (i == 2) {
            int g;
            cin >> g ;
            if (g == 0) {
                cout << a << " ";
            }
            else  {
                cout << b << " ";
            }
        } else {
            int l;
            int r;
            cin >> l >> r ;
            int ss = prefix[r] ^ prefix[l-1];
            a ^= ss;
            b ^= ss;
        }
    }
    cout << endl;
}

int main() {
    int t;
    cin >> t;
    while(t -- !=0) {
        solve();
    }
}