/*
给定由一些正数（代表长度）组成的数组 A，返回由其中三个长度组成的、面积不为零的三角形的最大周长。

如果不能形成任何面积不为零的三角形，返回 0。

 

示例 1：

输入：[2,1,2]
输出：5
示例 2：

输入：[1,2,1]
输出：0
示例 3：

输入：[3,2,3,4]
输出：10
示例 4：

输入：[3,6,2,3]
输出：8

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/largest-perimeter-triangle
*/
// 排序，从尾部开始反向遍历
class Solution {
public:
    int largestPerimeter(vector<int>& A) {
        if (A.size() < 3) {
            return 0;
        }
        sort(A.begin(), A.end());
        int start = 0, end = A.size() - 1;
        // 倒数第二 + 倒数第三 < 倒数第一，表明最后一个数过大
        while (end >= 2 && A[end - 1] + A[end - 2] <= A[end]) {
            --end;
        }
        // 剩余不足3个数
        if (end < 2) {
            return 0;
        }
        return A[end] + A[end - 1] + A[end - 2];
    }
};
