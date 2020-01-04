/*
找出所有相加之和为 n 的 k 个数的组合。组合中只允许含有 1 - 9 的正整数，并且每种组合中不存在重复的数字。

说明：

所有数字都是正整数。
解集不能包含重复的组合。 
示例 1:

输入: k = 3, n = 7
输出: [[1,2,4]]
示例 2:

输入: k = 3, n = 9
输出: [[1,2,6], [1,3,5], [2,3,4]]

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/combination-sum-iii
----------------------------
Note: 回溯，需记录参与的个数以及剩余的目标target
*/
class Solution {
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        if (k <= 0 || n <= 0) {
            return vector<vector<int>>();
        }
        vector<vector<int>> res;
        vector<int> tmp;
        backtrace(n, k, 1, tmp, res);
        return res;
    }

    void backtrace(int target, int cnt, int cur, vector<int>& tmp, vector<vector<int>>& res) {
        if (target < 0) return;
        if (target == 0 && cnt == 0) {
            res.push_back(tmp);
            return;
        }

        for (int i = cur; i <= 9; ++i) {
            if (i > target) {
                break;
            }
            tmp.push_back(i);
            backtrace(target - i, cnt - 1, i+1, tmp, res);
            tmp.pop_back();
        }
    }
};
