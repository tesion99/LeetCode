/*
给定一个无重复元素的数组 candidates 和一个目标数 target ，找出 candidates 中所有可以使数字和为 target 的组合。

candidates 中的数字可以无限制重复被选取。

说明：

所有数字（包括 target）都是正整数。
解集不能包含重复的组合。 
示例 1:

输入: candidates = [2,3,6,7], target = 7,
所求解集为:
[
  [7],
  [2,2,3]
]


来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/combination-sum
*/

class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        if (candidates.empty()) {
            return res;
        }
        vector<int> tmp;
        auto min_val = min_element(candidates.begin(), candidates.end());
        backtrace(candidates, *min_val, target, 0, tmp, res);
        return res;
    }

    void backtrace(vector<int>& candidates, int min_val, int target, int sum, vector<int>& tmp, vector<vector<int>>& res) {
        // 终止条件
        if (min_val + sum > target) {
            return;
        }

        for (int i = 0,  sz = candidates.size(); i < sz; ++i) {
            int val = sum + candidates[i];
            if (val > target) {
                continue;
            } else if (val < target) {
                tmp.push_back(candidates[i]);
                backtrace(candidates, min_val, target, val, tmp, res);
                tmp.pop_back();
            } else {
                vector<int> bak(tmp); // 不要使用tmp, 防止sort后改变元素顺序, 产生副作用
                bak.push_back(candidates[i]);
                sort(bak.begin(), bak.end());   // 比较去重
                bool dup = false;
                for (int j = 0; j < res.size(); ++j) {
                  if (bak.size() != res[j].size()) continue;
                  int k = 0;
                  for (k = 0; k < bak.size(); ++k) {
                      if (bak[k] != res[j][k]) {
                          break;
                      }
                  }
                  if (k == bak.size()) dup = true;
                }

                if (!dup) {
                    res.push_back(move(bak));
                }

            }
        }
    }
};
