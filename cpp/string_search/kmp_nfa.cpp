#include <string>
#include <vector>
class KMP {
   private:
    std::string pat_;
    std::vector<int> next_;
    void GetNext() {
        int n = pat_.size();
        for (int i = 1; i < n; ++i) {
            int k = next_[i - 1];
            while (k && pat_[k] != pat_[i]) {
                k = next_[k - 1];
            }
            // if (pat_[k] == pat_[i]) {
            //     k ++;
            // }
            k += pat_[k] == pat_[i];  // 避免 branch
            next_[i] = k;
        }
    }

   public:
    KMP(const std::string& pat) : pat_(pat), next_(pat.size(), 0) {
        GetNext();
    }
    // 给定文本串，返回模式串在文本串中出现的位置
    std::vector<int> Search(const std::string& txt) {
        std::vector<int> pos;
        int m = txt.size();
        int c = 0;  //对于i, c
                    //表示已经匹配的字符数，或者和txt[i]比较的模式串字符下标
        for (int i = 0; i < m; ++i) {
            while (c && pat_[c] != txt[i]) {
                c = next_[c - 1];
            }
            // if (pat_[c] == txt[i]) {
            //     c ++;
            // }
            c += pat_[c] == txt[i];
            if (c == pat_.size()) {
                pos.push_back(i - c + 1);
                c = next_[c-1];  // 回退到字符串的前后缀匹配的位置
            }
        }
        return pos;
    }
};
