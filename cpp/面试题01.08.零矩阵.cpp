/*
编写一种算法，若M × N矩阵中某个元素为0，则将其所在的行与列清零。

 

示例 1：

输入：
[
  [1,1,1],
  [1,0,1],
  [1,1,1]
]
输出：
[
  [1,0,1],
  [0,0,0],
  [1,0,1]
]
示例 2：

输入：
[
  [0,1,2,0],
  [3,4,5,2],
  [1,3,1,5]
]
输出：
[
  [0,0,0,0],
  [0,4,5,0],
  [0,3,1,0]
]

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/zero-matrix-lcci
*/
// 为避免检测判断时直接修改原矩阵，影响后续判断
// 对为0的行和列分别先记录下来
// 扫描矩阵完毕后，在对行和列置零
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        if (matrix.empty() || matrix[0].empty()) {
            return;
        }
        int rows = matrix.size() - 1;
        int cols = matrix[0].size() - 1;
        vector<int> zero_rows(rows + 1, 0);
        vector<int> zero_cols(cols + 1, 0);
        for (int r = 0; r <= rows; ++r) {
            for (int c = 0; c <= cols; ++c) {
                if (matrix[r][c] == 0) {
                    zero_rows[r] = 1;
                    zero_cols[c] = 1;
                }
            }
        }
        for (int r = 0; r <= rows; ++r) {
            if (zero_rows[r] == 0) {
                continue;
            }
            for (int c = 0; c <= cols; ++c) {
                matrix[r][c] = 0;
            }
        }
        for (int c = 0; c <= cols; ++c) {
            if (zero_cols[c] == 0) {
                continue;
            }
            for (int r = 0; r <= rows; ++r) {
                matrix[r][c] = 0;
            }
        }
    }
};
