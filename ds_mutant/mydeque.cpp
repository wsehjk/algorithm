#include <vector>
#include <iostream>
/*
1. push_head
2. pop_head， return element at head 
3. push_tail
4. pop_tail   return element at tail 
5. at(int idx) from head, get idx-th number
*/

class MyDeque {
private:
    int cap_;
    std::vector<int> que_;
    int num_{0};
    int head_{0};
    int tail_{0};
// keep the invariant: (tail_ - head_) == num_
    bool is_full() const {
        return tail_ - head_ == cap_;
    }
    bool is_empty() const {
        return tail_ == head_;
    }
    void resize() {
        int tmp_cap = cap_ << 1; // possible overflow
        std::vector<int> tmp(tmp_cap);
        for(int i = 0; i < cap_; ++i) {
            tmp[i] = que_[(head_ + i + cap_)%cap_];
            head_ ++;
        }
        cap_ = tmp_cap;
        que_.swap(tmp);
        head_ = 0;
        tail_ = cap_;
    }
public:
    MyDeque() = default;
    explicit MyDeque(int cap): cap_(cap), que_(cap_) {};
    bool push_head(int ele) {   // head_ -- 
        if (is_full()) {    // should resize 
            resize();
        }
        head_ --;
        que_[(head_+cap_)%cap_] = ele;
        return true;
    }
    std::optional<int> pop_head() {
        if (is_empty()) {   
            return {};
        }
        int ret = que_[(head_+cap_)%cap_];
        head_++;
        return ret;
    }

    bool push_tail(int ele) {
        if (is_full()) {    // should resize 
            //return false;
            resize();
        }
        que_[(tail_+cap_)%cap_] = ele;
        tail_ ++;
        return true;
    }
    std::optional<int> pop_tail() {
        if (is_empty()) {
            return {};
        }
        tail_ --;
        int ret = que_[(tail_+cap_)%cap_];
        return ret;
    }
    std::optional<int> at(int idx) {
        if (idx < 0 || idx >= (tail_ - head_)) {
            return {};
        }
        return que_[(head_ + idx + cap_)%cap_];
    }
};

int main() {
    {
        MyDeque que(5);
        que.push_head(10);
        que.push_tail(-1);
        auto ret = que.at(1);
        if (ret.has_value() == false) {
            std::cout << "error\n";
        }
        std::cout << ret.value() << std::endl;
        que.push_head(15);
        ret = que.at(1);
        if (ret.has_value() == false) {
            std::cout << "error\n";
        }
        std::cout << ret.value() << std::endl;

        ret = que.pop_head();
        if (ret.has_value() == false) {
            std::cout << "error\n";
        }
        std::cout << ret.value() << std::endl;
        ret = que.pop_tail();
        if (ret.has_value() == false) {
            std::cout << "error\n";
        }
        std::cout << ret.value() << std::endl;
    }
}