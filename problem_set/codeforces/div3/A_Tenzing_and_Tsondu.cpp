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
class t {
    public:
        t(int r1, int r2) {
            R1 = r1;
            R2 = r2;
        }
        void print() {
            cout << "R1 is " << R1 << ", R2 is " << R2 << endl;
        }
        void print() const {
            cout << "R1 is " << R1 << ", R2 is " << R2 << endl;
        }
    private:
        int R1;
        int R2;
};
int main() {
    t a(8,6);
    const t b(85, 58);
    b.print();
}