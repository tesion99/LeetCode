/*
给你一个整数数组 arr，请你检查是否存在两个整数 N 和 M，满足 N 是 M 的两倍（即，N = 2 * M）。

更正式地，检查是否存在两个下标 i 和 j 满足：

i != j
0 <= i, j < arr.length
arr[i] == 2 * arr[j]
 

示例 1：

输入：arr = [10,2,5,3]
输出：true
解释：N = 10 是 M = 5 的两倍，即 10 = 2 * 5 。
示例 2：

输入：arr = [7,1,14,11]
输出：true
解释：N = 14 是 M = 7 的两倍，即 14 = 2 * 7 。
示例 3：

输入：arr = [3,1,7,11]
输出：false
解释：在该情况下不存在 N 和 M 满足 N = 2 * M 。
 

提示：

2 <= arr.length <= 500
-10^3 <= arr[i] <= 10^3

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/check-if-n-and-its-double-exist
*/
// 索引计数
// 区分负数区域，0，正数区域的不同
class Solution {
public:
    bool checkIfExist(vector<int>& arr) {
        if (arr.size() < 2) {
            return false;
        }
        int nums[2001] = {0};
        for (auto n : arr) {
            ++nums[1000 + n];
        }
        // 对负数部分处理
        for (int i = 999; i >= 0; --i) {
            if (nums[i] == 0) {
                continue;
            }
            int ori = i - 1000;
            int target = 1000 + 2 * ori;
            if (target < 0) {
                break;
            }
            if (nums[target] != 0) {
                return true;
            }
        }
        // 对剩余部分处理
        for (int i = 1000; i < 2001; ++i) {
            if (nums[i] == 0) {
                continue;
            }
            int ori = i - 1000;
            if (ori == 0) {
                if (nums[i] >= 2) {
                    return true;
                }
            } else {
                int target = 1000 + 2 * ori;
                if (target >= 2001) {
                    break;
                }
                if (nums[target] != 0) {
                    return true;
                }
            }
        }
        
        return false;
    }
};
