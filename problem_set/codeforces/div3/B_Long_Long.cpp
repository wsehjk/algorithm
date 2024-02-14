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
const int mod = 1e9+7;
#define fi first;
#define se second
#define ll long long

void solve() {
    int n;
    cin >> n;
    long long ans = 0;
    vector<int> arr(n, 0);
    for(int i = 0; i < n; ++i) {
        cin >> arr[i];
        ans += abs(arr[i]);
    }
    long long cnt = 0;
    for(int i = 0; i < n; ) {
        if (arr[i] >= 0) {
            i++;
            continue;
        }
        int j = i;
        while (j < n && arr[j] <= 0) j ++;
        cnt ++;
        i = j;
    }
    cout << ans << " " << cnt << endl;
}

int main() {
    int T;
    cin >> T;
    while (T-- != 0) {
        solve();
    }
    return 0;
}
/*
8
-1 0 0 -2 1 0 -3 0
5
2 -1 0 -3 -7
5
0 -17 0 1 0
4
-1 0 -2 -1
*/
/*
7 2
13 1
18 1
4 1
*/