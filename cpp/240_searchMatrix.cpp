/*
给定M×N矩阵，每一行、每一列都按升序排列，请编写代码找出某元素。

示例:

现有矩阵 matrix 如下：

[
  [1,   4,  7, 11, 15],
  [2,   5,  8, 12, 19],
  [3,   6,  9, 16, 22],
  [10, 13, 14, 17, 24],
  [18, 21, 23, 26, 30]
]
给定 target = 5，返回 true。

给定 target = 20，返回 false。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/sorted-matrix-search-lcci
*/
// 确定起始行结束行，起始列结束列
// 通过题目已序，调整起始/结束的行或列，从而缩小查找范围
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if (matrix.empty() || matrix[0].empty()) {
            return false;
        }

        int rows = matrix.size() - 1, cols = matrix[0].size() - 1;
        int sr = 0, sc = 0;
        while (sr <= rows && sc <= cols) {
            if (target < matrix[sr][sc] || target > matrix[rows][cols]) {
                return false;
            }
            if (target > matrix[sr][cols]) {
                ++sr;
                continue;
            } else if (target < matrix[sr][cols]) {
                --cols;
                continue;
            }
            if (target > matrix[rows][sc]) {
                ++sc;
                continue;
            } else if (target < matrix[rows][sc]) {
                --rows;
                continue;
            }
            return true;
        }
        return false;
    }
};
