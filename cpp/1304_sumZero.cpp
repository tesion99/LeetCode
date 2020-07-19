/*
给你一个整数 n，请你返回 任意 一个由 n 个 各不相同 的整数组成的数组，并且这 n 个数相加和为 0 。

 

示例 1：

输入：n = 5
输出：[-7,-1,1,3,4]
解释：这些数组也是正确的 [-5,-1,1,2,3]，[-3,-1,2,-2,4]。
示例 2：

输入：n = 3
输出：[-1,0,1]
示例 3：

输入：n = 1
输出：[0]
 

提示：

1 <= n <= 1000

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/find-n-unique-integers-sum-up-to-zero
*/
// 类似回文做对称
class Solution {
public:
    vector<int> sumZero(int n) {
        if (n <= 0) {
            return vector<int>();
        }
        vector<int> res(n, 1);
        int start = 0, end = n - 1;
        while (start <= end) {
            if (start == end) {
                res[start] = 0;
                break;
            }

            res[start] = -n/2;
            res[end] = -res[start];
            ++start;
            --end;
            n -= 2;
        }

        return res;
    }
};
