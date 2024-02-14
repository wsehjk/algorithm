#include <algorithm>
#include <iostream>
#include <iterator>
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
void solve() {
    vector<int> st[3];
    int n;
    int x;
    cin >> n >> x;
    // cout << "*********" << endl;
    for(auto & i : st) {
        for(int j = 0; j < n; ++j) {
            int a = 0;
            cin >> a;
            i.push_back(a);
        }
        reverse(i.begin(), i.end());
    }
    // cout << "*********" << endl;
    int y = x;
    unordered_set<int> stt;
    unordered_set<int> ori;
    int i = 0;
    while (y != 0) { // 记录 x 的位
        if (y%2 == 1) {
            stt.insert(i);
            ori.insert(i);
        }
        y /= 2;
        i ++;
    }
    while (stt.empty() == false) {
        bool flag = false;
        // flag: 栈顶是否有满足条件的数
        for(auto & i : st) {
            if (i.empty()) {
                continue;
            }
            int a = i.back();
            int j = 0;
            while (a != 0) {
                if (a%2 == 1) { // 栈顶元素有x中不存在的bit
                    if (ori.count(j) == 0) {
                        break;
                    }
                }
                a /= 2;
                j ++;
            }
            if (a == 0) {
                a = i.back();
                i.pop_back();
                flag = true;
                int j = 0;
                while (a != 0) {
                    if (a%2 == 1 && stt.count(j) != 0) {
                        stt.erase(j);
                    }
                    a /= 2;
                    j ++;
                }
            }
        }
        if (flag == false) {
            cout << "No" << endl;
            return;
        }
    }
    cout << "Yes" << endl;
}

int main() {
    int T;
    cin >> T;
    while (T-- != 0) {
        solve();
    }
    return 0;
}