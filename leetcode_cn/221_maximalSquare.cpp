/*
在一个由 0 和 1 组成的二维矩阵内，找到只包含 1 的最大正方形，并返回其面积。

示例:

输入: 

1 0 1 0 0
1 0 1 1 1
1 1 1 1 1
1 0 0 1 0

输出: 4

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/maximal-square
*/
class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        if (matrix.empty() || matrix[0].empty()) {
            return 0;
        }
        int rows = matrix.size() - 1;
        int cols = matrix[0].size() - 1;
        int res = 0;

        for (int r = 0; r <= rows; ++r) {
            for (int c = 0; c <= cols; ++c) {
                if (matrix[r][c] == '0') continue;
                // 以左上角的点为顶点，比对对角线坐标所在行和列的值是否全为1
                int tmp = bfs(matrix, r, c, r, c, 0);
                res = max(res, tmp);
            }
        }
        return res * res;
    }

    // sr, sc为左对角线上第一个点的坐标
    int bfs(vector<vector<char>>& matrix, int sr, int sc, int r, int c,  int level) {
        if (r >= matrix.size() || c >= matrix[0].size()) {
            return level;
        }
        // 比对左对角线点的所在行坐标所有点是否为全1
        for (int col = sc; col <= c; ++col) {
            if (matrix[r][col] == '0') {
                return level;
            }
        }
        // 比对左对角线点的所在列坐标所有点是否全为1
        for (int row = sr; row <= r; ++row) {
            if (matrix[row][c] == '0') {
                return level;
            }
        }
        return bfs(matrix, sr, sc, r + 1, c + 1, level + 1);
    }
};
