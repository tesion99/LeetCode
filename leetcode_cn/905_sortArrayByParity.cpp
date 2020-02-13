/*
给定一个非负整数数组 A，返回一个数组，在该数组中， A 的所有偶数元素之后跟着所有奇数元素。

你可以返回满足此条件的任何数组作为答案。

 

示例：

输入：[3,1,2,4]
输出：[2,4,3,1]
输出 [4,2,3,1]，[2,4,1,3] 和 [4,2,1,3] 也会被接受。
 

提示：

1 <= A.length <= 5000
0 <= A[i] <= 5000

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/sort-array-by-parity
*/
// 双指针
// 从首部开始扫描，遇到第一个奇数停止
// 从尾部扫描，遇到第一个偶数停止
// 交换以上位置的元素
class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& A) {
        int left = 0, right = A.size() - 1;
        while (left <= right) {
            while (left <= right && (A[left] & 1) == 0) {
                ++left;
            }

            while (right >= left && (A[right] & 1)) {
                --right;
            }

            if (left < right) {
                swap(A[left], A[right]);
            }
        }
        return A;
    }
};
