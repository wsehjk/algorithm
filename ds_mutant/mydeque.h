#include <vector>
#include <iostream>
#include <optional>

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
    #ifdef TEST
    int resize_num{0};
    #endif
// keep the invariant: (tail_ - head_) == num_
    bool is_full() const {
        return tail_ - head_ == cap_;
    }
    bool is_empty() const {
        return tail_ == head_;
    }
    void resize() {
        #ifdef TEST
        resize_num ++;
        #endif
        int tmp_cap = cap_ << 1; // possible overflow
        std::vector<int> tmp(tmp_cap);
        for(int i = 0; i < cap_; ++i) {
            tmp[i] = que_[(head_ + i + cap_)%cap_];
        }
        head_ = 0;
        tail_ = cap_;
        cap_ = tmp_cap;
        que_.swap(tmp);
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
    int size() const {
        return tail_ - head_; 
    }
    // for test 
    #ifdef TEST
    int get_head() const {
        return head_;
    }
    int get_tail() const {
        return tail_;
    }
    int get_resize_num() const {
        return resize_num;
    }
    #endif
};

