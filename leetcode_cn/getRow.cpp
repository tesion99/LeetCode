/*
给定一个非负索引 k，其中 k ≤ 33，返回杨辉三角的第 k 行。

在杨辉三角中，每个数是它左上方和右上方的数的和。

示例:

输入: 3
输出: [1,3,3,1]
进阶：

你可以优化你的算法到 O(k) 空间复杂度吗？

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/pascals-triangle-ii
*/
// 使用一个数组存储每次上一行的值，轮询到指定的行后
// 数组存储结果即为第n行的结果
class Solution {
public:
    vector<int> getRow(int rowIndex) {
        if (rowIndex < 0) {
            return vector<int>();
        }
        
        vector<int> res(rowIndex + 1, 1); // 第N行有N+1个元素
        for (int row = 2; row <= rowIndex; ++row) {
            int pre = 1;
            for (int column = 1; column < row; ++column) {
                int cur = res[column];  // 避免覆盖当前值的原始值
                res[column] += pre;
                pre = cur;
            }
        }
        return res;
    }
};
