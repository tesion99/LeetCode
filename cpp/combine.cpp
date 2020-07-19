/*
给定两个整数 n 和 k，返回 1 ... n 中所有可能的 k 个数的组合。

示例:

输入: n = 4, k = 2
输出:
[
  [2,4],
  [3,4],
  [2,3],
  [1,2],
  [1,3],
  [1,4],
]

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/combinations
*/
class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        if (n <= 0 || k <= 0) {
            return vector<vector<int>>();
        }

        vector<vector<int>> res;
        vector<int> tmp;
        backtrace(1, n, k, tmp, res);
        return res;
    }

    void backtrace(int cur, int n, int k, vector<int>& tmp, vector<vector<int>>& res) {
        if (0 == k) {
            res.push_back(tmp);
            return;
        }

        for (int i = cur; i <= n; ++i) {
            tmp.push_back(i);
            backtrace(i+1, n, k - 1, tmp, res);
            tmp.pop_back();
        }
    }
};

// 根据一个元素选与不选做回溯递归
// WARN: 该方式效率较上一种低
class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        if (n <= 0 || k <= 0) {
            return vector<vector<int>>();
        }

        vector<vector<int>> res;
        vector<int> tmp;
        backtrace(1, n, k, tmp, res);
        return res;
    }

    void backtrace(int cur, int n, int k, vector<int>& tmp, vector<vector<int>>& res) {
        if (k == 0) {
            res.push_back(tmp);
            return;
        }
        
        if (cur > n) {
            return;
        }
        // 选择本元素
        tmp.push_back(cur);
        backtrace(cur+1, n, k - 1, tmp, res);
        tmp.pop_back();
        // 不选择本元素
        backtrace(cur+1, n, k, tmp, res);
    }
};
