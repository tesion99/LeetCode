/*
在大小为 2N 的数组 A 中有 N+1 个不同的元素，其中有一个元素重复了 N 次。

返回重复了 N 次的那个元素。

 

示例 1：

输入：[1,2,3,3]
输出：3
示例 2：

输入：[2,1,2,5,3,2]
输出：2
示例 3：

输入：[5,1,5,2,5,3,5,4]
输出：5
 

提示：

4 <= A.length <= 10000
0 <= A[i] < 10000
A.length 为偶数

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/n-repeated-element-in-size-2n-array
*/
// 先排序，在查找中间值
// 注意可能的异常情况
class Solution {
public:
    int repeatedNTimes(vector<int>& A) {
        sort(A.begin(), A.end());
        // 区分该数出现在前半部分，还是后半部分, [1,1,2,3]或[1,2,3,3]或[1,2,2,3]
        size_t sz = A.size();
        int mid = A[sz / 2];
        int pre = A[sz / 2 - 1];

        if (mid == pre) {
            return mid;
        }

        int cnt = count(A.begin(), A.end(), mid);
        return (cnt == sz / 2) ? mid : pre;
    }
};
