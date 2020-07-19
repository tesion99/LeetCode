/*
给定一个字符串 s，将 s 分割成一些子串，使每个子串都是回文串。

返回 s 所有可能的分割方案。

示例:

输入: "aab"
输出:
[
  ["aa","b"],
  ["a","a","b"]
]

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/palindrome-partitioning
*/
// 双回溯，临时数组存储回溯路径上复合条件的一组字符串
// 临时数组中所有满足条件的字符串长度和len，用于终止条件达到时，检测是否完全是回文
// 遍历临时字符串，长度从1到最大，当为回文时，递归后续剩余字符串
class Solution {
public:
    vector<vector<string>> partition(string s) {
        if (s.empty()) {
            return vector<vector<string>>();
        }
        vector<vector<string>> res;
        vector<string> tmp;
        int len = 0;
        backtrace(s, 0, s.size() - 1, len, tmp, res);
        
        return res;
    }

    bool isPalindrome(const string& str) {
        if (str.empty()) {
            return false;
        }

        int start = 0,  end = str.size() - 1;
        while (start <= end) {
            if (str[start] != str[end]) {
                return false;
            }
            ++start;
            --end;
        }
        return true;
    }

    void backtrace(string& s, int start, int end, int& len, vector<string>& tmp, vector<vector<string>>& res) {
        if (start > end) {
            if (len == s.size() && !tmp.empty()) {
                res.push_back(tmp);
            }
            return;
        }

        string str;
        for (int i = start; i <= end; ++i) {
            str.push_back(s[i]);
            if (isPalindrome(str)) {
                len += str.size();
                tmp.push_back(str);
                backtrace(s, i+1, end, len, tmp, res);
                len -= str.size();
                tmp.pop_back();
            }
        }    
    }
};
