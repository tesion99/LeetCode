/*
给定一个矩阵 A， 返回 A 的转置矩阵。

矩阵的转置是指将矩阵的主对角线翻转，交换矩阵的行索引与列索引。

 

示例 1：

输入：[[1,2,3],[4,5,6],[7,8,9]]
输出：[[1,4,7],[2,5,8],[3,6,9]]
示例 2：

输入：[[1,2,3],[4,5,6]]
输出：[[1,4],[2,5],[3,6]]
 

提示：

1 <= A.length <= 1000
1 <= A[0].length <= 1000

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/transpose-matrix
*/
class Solution {
public:
    vector<vector<int>> transpose(vector<vector<int>>& A) {
        int rows = A.size(), columns = A[0].size();
        vector<vector<int>> res(columns, vector<int>(rows, 0));
        for (int c = 0; c < columns; ++c) {
            for (int r = 0; r < rows; ++r) {
                res[c][r] = A[r][c];
            }
        }
        return res;
    }
};
