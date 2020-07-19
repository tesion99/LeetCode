/*
给你一个 m * n 的矩阵，矩阵中的数字 各不相同 。请你按 任意 顺序返回矩阵中的所有幸运数。

幸运数是指矩阵中满足同时下列两个条件的元素：

在同一行的所有元素中最小
在同一列的所有元素中最大
 

示例 1：

输入：matrix = [[3,7,8],[9,11,13],[15,16,17]]
输出：[15]
解释：15 是唯一的幸运数，因为它是其所在行中的最小值，也是所在列中的最大值。
示例 2：

输入：matrix = [[1,10,4,2],[9,3,8,7],[15,16,17,12]]
输出：[12]
解释：12 是唯一的幸运数，因为它是其所在行中的最小值，也是所在列中的最大值。
示例 3：

输入：matrix = [[7,8],[1,2]]
输出：[7]
 

提示：

m == mat.length
n == mat[i].length
1 <= n, m <= 50
1 <= matrix[i][j] <= 10^5
矩阵中的所有元素都是不同的

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/lucky-numbers-in-a-matrix
*/
class Solution {
public:
    vector<int> luckyNumbers (vector<vector<int>>& matrix) {
        if (matrix.empty() || matrix[0].empty()) {
            return {};
        }

        int rows = matrix.size() - 1, cols = matrix[0].size() - 1;
        vector<int> row_mins(rows + 1, INT_MAX);
        vector<int> col_maxs(cols + 1, INT_MIN);
        for (int r = 0; r <= rows; ++r) {
            row_mins[r] = *min_element(matrix[r].begin(), matrix[r].end());
        }
        for (int c = 0; c <= cols; ++c) {
            for (int r = 0; r <= rows; ++r) {
                if (col_maxs[c] < matrix[r][c]) {
                    col_maxs[c] = matrix[r][c];
                }
            }
        }
        vector<int> res;
        for (int r = 0; r <= rows; ++r) {
            for (int c = 0; c <= cols; ++c) {
                if (row_mins[r] == col_maxs[c]) {
                    res.push_back(matrix[r][c]);
                }
            }
        }
        return res;
    }
};
