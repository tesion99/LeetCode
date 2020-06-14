/*
给你一个 m * n 的矩阵，矩阵中的元素不是 0 就是 1，

请你统计并返回其中完全由 1 组成的 正方形 子矩阵的个数。

示例 1：

输入：matrix =
[
  [0,1,1,1],
  [1,1,1,1],
  [0,1,1,1]
]
输出：15
解释： 
边长为 1 的正方形有 10 个。
边长为 2 的正方形有 4 个。
边长为 3 的正方形有 1 个。
正方形的总数 = 10 + 4 + 1 = 15.
示例 2：

输入：matrix = 
[
  [1,0,1],
  [1,1,0],
  [1,1,0]
]
输出：7
解释：
边长为 1 的正方形有 6 个。 
边长为 2 的正方形有 1 个。
正方形的总数 = 6 + 1 = 7.
 

提示：

1 <= arr.length <= 300
1 <= arr[0].length <= 300
0 <= arr[i][j] <= 1

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/count-square-submatrices-with-all-ones
*/
// 以每一个1的点作为正方向的左上角顶点，进行广度优先搜索
class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
        if (matrix.empty() || matrix[0].empty()) {
            return 0;
        }

        int res = 0;
        int rows = matrix.size() - 1, cols = matrix[0].size() - 1;
        for (int r = 0; r <= rows; ++r) {
            for (int c = 0; c <= cols; ++c) {
                if (matrix[r][c] == 0) continue;

                bfs(matrix, r, c, r, c, res);
            }
        }
        return res;
    }

    void bfs(vector<vector<int>>& matrix, int sr, int sc, int r, int c, int& res) {
        if (r < 0 || r >= matrix.size() || c < 0 || c >= matrix[0].size()) {
            return;
        }
        for (int col = sc; col <= c; ++col) {
            if (matrix[r][col] == 0) return;
        }
        for (int row = sr; row <= r; ++row) {
            if (matrix[row][c] == 0) return;
        }
        ++res;
        bfs(matrix, sr, sc, r + 1, c + 1, res);
    }
};
