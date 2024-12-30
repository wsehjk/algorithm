#include <iostream>
#include <vector>
#include <set>
#include <queue>
#include <stack>
/*
    实现一个类，内部是个栈数组，每个栈有固定的capacity
    1. push: 找到最左边（下标）最小的栈，插入元素
    2. pop: 找到最右边（下标最大）的非空栈，取出元素
    3. pop(idx): 找到下标为 idx的栈，取出元素

// every stack has 3 possible states
    1. empty
    2. full
    3. neither empty nor full 
*/
class Mystack {
private:
    std::vector<std::stack<int>> stacks;
    int cap;
    std::set<int> full_set;
    std::set<int> empty_set;
    std::set<int> not_empty_or_full_set;

    int SmallestStackForPush() {  // for push 
        int a = empty_set.empty() ? 1e9 : *empty_set.begin();
        int b = not_empty_or_full_set.empty() ? 1e9 : *not_empty_or_full_set.begin();
        return std::min(a, b); 
    }

    int LargestStackForPop() {  // for pop
        int a = full_set.empty() ? -1 : *full_set.rbegin();
        int b = not_empty_or_full_set.empty() ? -1 : *not_empty_or_full_set.rbegin();
        return std::max(a,b);
    }
public:
    Mystack(int cap):cap(cap){}
    // push to the left most available stack

    void push(int val) {
        int idx = SmallestStackForPush();
        if (idx == 1e9) {
            stacks.push_back(std::stack<int>());
            stacks.back().push(val);
            idx = stacks.size() - 1;
        }

        if (empty_set.count(idx)) {
            empty_set.erase(idx);
        } else {
            not_empty_or_full_set.erase(idx);
        }

        stacks[idx].push(val);
        if (stacks[idx].size() == cap) {
            full_set.insert(idx);
        } else {
            not_empty_or_full_set.insert(idx);
        }
    }

    // right most no-empty stack
    int pop() {
        int idx = LargestStackForPop();
        return pop(idx);
    }

    int pop(int idx) {
        if (idx < 0 || idx >= stacks.size() || stacks[idx].empty() ) {
            return -1;
        }

        int ans = stacks[idx].top();
        stacks[idx].pop();
        if (full_set.count(idx)) {
            full_set.erase(idx); 
        } else {
            not_empty_or_full_set.erase(idx);
        }

        if (stacks[idx].size() == 0) {
            empty_set.insert(idx);
        } else {
            not_empty_or_full_set.erase(idx); 
        }
        return ans;
    }
};


// feasibility or efficiency
// use std::
// 在写之前 解释每个函数的思路
// 理清楚 每个变量的含义，每个函数对这个变量状态的影响