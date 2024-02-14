#include <iostream>
#include <vector>
#include <queue>
using namespace std;

void solve() {
   int n;
   cin >> n;
   vector<int> f(n);
   vector<int> inc(n, 0);
   for(int i = 0; i < n; ++i) { // 
    int b;
    cin >> b;
    f[i] = b - 1;
    inc[b-1] ++;
   } 
   vector<int> c(n);
   for(auto& b : c) {
    cin >> b;
   } 
   queue<int> que;
   for(int i = 0; i < n; ++i) {
    if (inc[i] == 0) {
        que.push(i);
    }
   }
   vector<int> flag(n, 0);
   while (!que.empty()) {
    int a = que.front();
    flag[a] = 1;
    que.pop();
    cout << a+1 << " ";
    int b = f[a];
    inc[b] --;
    if (inc[b] == 0) {
        que.push(b);
    }
   }
   for(int i = 0; i < n; ++i) {
    if (flag[i] == 1) {
        continue;
    }
    //环
    //寻找环中c最小的节点
    int minc = c[i];
    flag[i] = 1;
    int index = i;
    int t = f[i];
    while (t != i) {
        flag[t] = 1;
        if (c[t] < minc) {
            minc = c[t];
            index = t;
        }
        t = f[t];
    }
    t = f[index];
    while (t != index) {
        cout << t+1 << " ";
        t = f[t];
    }
    cout << index+1 << " ";
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