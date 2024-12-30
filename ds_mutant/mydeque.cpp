#include <vector>

class MyDeque {
private:
    int head_;
    int tail_;
    std::vector<int> que_;
    int cap_;
    int num_;
public:
    MyDeque() = default;
};