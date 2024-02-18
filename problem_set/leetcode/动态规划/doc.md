- [相同分数的最大操作数目](#相同分数的最大操作数目)

## [相同分数的最大操作数目](https://leetcode.cn/problems/maximum-number-of-operations-with-the-same-score-ii/description/)
看到本题我就想到区间动态规划的解法，写下这样的代码
```cpp
class Solution {
public:
    int maxOperations(vector<int>& nums) {
        int n = nums.size();
        std::unordered_map<int, std::unordered_map<int,int>> mp;
        std::function<void(int,int)> dfs = [&](int l, int r) {
            auto cur = l * n + r; 
            if (mp.count(cur)) {
                return;
            }
            if (l >= r) {
                mp[cur] = {};
                return;
            }
            int a1 = nums[l] + nums[l+1]; 
            dfs(l+2, r);
            mp[cur][a1] = max(1 + mp[(l+2)*n + r][a1], mp[cur][a1]);
            
            int a2 = nums[l] + nums[r];
            dfs(l+1, r-1);
            mp[cur][a2] = max(1 + mp[(l+1)*n + r-1][a2], mp[cur][a2]);
            
            int a3 = nums[r-1] + nums[r];
            dfs(l, r-2);
            mp[cur][a3] = max(1 + mp[l*n + r-2][a3], mp[cur][a3]);
        }; 
        dfs(0, n-1);
        int ans = -1;
        auto tot = nums.size() - 1;
        for(const auto&[s, ops] : mp[tot]) {
            ans = max(ans, ops);
        }
        return ans; 
    }
};
```
`dfs`函数表示的意义是给定区间`[l,r]`得到区间上可能得操作分数`v`以及相应的次数

`t = mp[k][v]`表示在某个区间上操作分数为`v`的操作有`t`种。
代码复杂度为`O(n^2)`。但是测试超时。

之后考虑给定区间`[l,r]`和目标操作分数`target`，计算相应的次数。整个数组的目标操作分数`target`只有三个，所以需要三个区间dp即可
```c++
class Solution {
public:
    int maxOperations(vector<int>& nums) {
        int n = nums.size();
        int memo[n][n];
        std::function<int(int,int,int)> dfs = [&](int l, int r, int target) {
            if (l >= r) {
                return 0;
            }
            int& a = memo[l][r];
            if (a != -1) {
                return a; 
            }
            a = 0;
            int a1 = nums[l] + nums[l+1]; 
            if (a1 == target) {
                a = max(a, 1+dfs(l+2, r, tar));
            }

            int a2 = nums[l] + nums[r];
            if (a2 == target) {
                a = max(a, 1+dfs(l+1, r-1, tar));
            }
            
            int a3 = nums[r-1] + nums[r];
            if (a3 == target) {
                a = max(a, 1+dfs(l, r-2, tar));
            }
            return a;
        }; 
        memset(memo, -1, sizeof(memo));
        int a1 = dfs(0, n-1, nums[0] + nums[1]);

        memset(memo, -1, sizeof(memo));
        int a2 = dfs(0, n-1, nums[0] + nums[n-1]);

        memset(memo, -1, sizeof(memo));
        int a3 = dfs(0, n-1, nums[n-2] + nums[n-1]);
        return max(max(a1, a2), a3); 
    }
};
```
1. 虽然`dfs`的结果存放在`memo`数组中，但是`caller`要避免访问`callee`的`memo`，因为有可能越界
   比如
   ```cpp
    if (a1 == tar) {
        a = max(a, 1+dfs(l+2, r, tar)); // 避免写成 a = max(a, 1+memo[l+2][r])
    }
   ```
   需要`dfs`返回有效的结果
2. `target`进行了很多有效的剪枝
3. 观察到目标分数`target`再`dfs`中属于不变量，可以写出简洁的代码
```c++
class Solution {
public:
    int maxOperations(vector<int>& nums) {
        int n = nums.size();
        int memo[n][n];
        auto helper = [&](int tar) ->int{
            memset(memo, -1, sizeof(memo));

            std::function<int(int,int)> dfs = [&](int l, int r) {
                if (l >= r) {
                    return 0;
                }
                int& a = memo[l][r];
                if (a != -1) {
                    return a; 
                }
                a = 0;
                int a1 = nums[l] + nums[l+1]; 
                if (a1 == tar) {
                    a = max(a, 1+dfs(l+2, r));
                }

                int a2 = nums[l] + nums[r];
                if (a2 == tar) {
                    a = max(a, 1+dfs(l+1, r-1));
                }
                
                int a3 = nums[r-1] + nums[r];
                if (a3 == tar) {
                    a = max(a, 1+dfs(l, r-2));
                }
                return a;
            };
            return dfs(0,n-1);
        };
        int ans = -1;
        ans = max(ans, helper(nums[0] + nums[1])); 
        ans = max(ans, helper(nums[0] + nums[n-1])); 
        ans = max(ans, helper(nums[n-2] + nums[n-1])); 
        return ans;
    }
};
```