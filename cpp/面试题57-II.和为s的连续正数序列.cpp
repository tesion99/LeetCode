/*
输入一个正整数 target ，输出所有和为 target 的连续正整数序列（至少含有两个数）。

序列内的数字由小到大排列，不同序列按照首个数字从小到大排列。

 

示例 1：

输入：target = 9
输出：[[2,3,4],[4,5]]
示例 2：

输入：target = 15
输出：[[1,2,3,4,5],[4,5,6],[7,8]]
 

限制：

1 <= target <= 10^5


来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/he-wei-sde-lian-xu-zheng-shu-xu-lie-lcof
*/
// 首先，考虑数据最少为2的情况，第一个数据mid = target / 2;
// 其次，根据起始数据从1~mid，数据个数n从2~mid进行下去，用等差数列求和公式解题
class Solution {
public:
    vector<vector<int>> findContinuousSequence(int target) {
        vector<vector<int>> res;
        if (target <= 1) {
            return res;
        }
        int mid = target / 2;
        for (int i = 1; i <= mid; ++i) {    // 确定起始数
            for (int n = 2; n <= mid; ++n) { // 确定数据个数
                int sum = n * i + n * (n - 1) / 2; // 等差求和公式，公差d = 1
                if (sum > target) {
                    break;
                }
                if (sum == target) {
                    vector<int> tmp;
                    tmp.reserve(n);
                    for (int start = i, end = i + n - 1; start <= end; ++start) {
                        tmp.push_back(start);
                    }
                    res.push_back(tmp);
                }
            }
        }
        return res;
    }
};
