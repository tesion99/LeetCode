/*
给定一个非负整数数组 A， A 中一半整数是奇数，一半整数是偶数。

对数组进行排序，以便当 A[i] 为奇数时，i 也是奇数；当 A[i] 为偶数时， i 也是偶数。

你可以返回任何满足上述条件的数组作为答案。

 

示例：

输入：[4,2,5,7]
输出：[4,5,2,7]
解释：[4,7,2,5]，[2,5,4,7]，[2,7,4,5] 也会被接受。
 

提示：

2 <= A.length <= 20000
A.length % 2 == 0
0 <= A[i] <= 1000

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/sort-array-by-parity-ii
*/
// 计数排序 回写回结果集
class Solution {
public:
    vector<int> sortArrayByParityII(vector<int>& A) {
        if (A.empty()) {
            return vector<int>();
        }
        vector<int> res(A.size());
        vector<int> tmp(1001, 0);
        for (auto n : A) {
            ++tmp[n];
        }
        // 结果集中奇数、偶数位对应的索引
        int even = 0, odd = 1;
        for (int i = 0; i < tmp.size(); ++i) {
            if (tmp[i] == 0) {
                continue;
            }

            if (i & 1) {
                while (tmp[i]) {
                    res[odd] = i;
                    odd += 2;
                    --tmp[i];
                }
            } else {
                while (tmp[i]) {
                    res[even] = i;
                    even += 2;
                    --tmp[i];
                }
            }
        }
        return res;
    }
};
