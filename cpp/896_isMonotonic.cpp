/*
如果数组是单调递增或单调递减的，那么它是单调的。

如果对于所有 i <= j，A[i] <= A[j]，那么数组 A 是单调递增的。 如果对于所有 i <= j，A[i]> = A[j]，那么数组 A 是单调递减的。

当给定的数组 A 是单调数组时返回 true，否则返回 false。

 

示例 1：

输入：[1,2,2,3]
输出：true
示例 2：

输入：[6,5,4,4]
输出：true
示例 3：

输入：[1,3,2]
输出：false

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/monotonic-array
*/
// 先查找到第一个不同的数，预测是升序还是降序
// 接着以升序或降序检验后续的数
class Solution {
public:
    bool isMonotonic(vector<int>& A) {
        if (A.size() <= 1) {
            return true;
        }

        int i = 0;
        for (i = 0; i < A.size(); ++i) {
            if (i > 0 && A[i] != A[i - 1]) {
                break;
            }
        }

        // 所有数均相等
        if (i == A.size()) {
            return true;
        }
        bool flag = A[i] >= A[i - 1] ? true : false;

        for (int j = i; j < A.size(); ++j) {
            if (flag) {
                if (A[j] < A[j - 1]) {
                    return false;
                }
            } else {
                if (A[j] > A[j - 1]) {
                    return false;
                }
            }
        }
        return true;
    }
};
