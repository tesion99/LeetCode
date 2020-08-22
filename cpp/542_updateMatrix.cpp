/*
给定一个由 0 和 1 组成的矩阵，找出每个元素到最近的 0 的距离。

两个相邻元素间的距离为 1 。

示例 1: 
输入:

0 0 0
0 1 0
0 0 0
输出:

0 0 0
0 1 0
0 0 0
示例 2: 
输入:

0 0 0
0 1 0
1 1 1
输出:

0 0 0
0 1 0
1 2 1
注意:

给定矩阵的元素个数不超过 10000。
给定矩阵中至少有一个元素是 0。
矩阵中的元素只在四个方向上相邻: 上、下、左、右。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/01-matrix
*/
// bfs
// 利用广度优先搜索，在每个 1 处，按层序搜索，直到第一次遇到0为止
class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& matrix) {
        int direcs[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        int rows = matrix.size(), cols = matrix[0].size();
        for (int r = 0; r < rows; ++r) {
            for (int c = 0; c < cols; ++c) {
                if (matrix[r][c] == 0) continue;

                queue<pair<int, int>> q;
                int level = 0;
                bool found = false;
                q.push({r, c});
                while (!q.empty() && !found) {
                    size_t sz = q.size();
                    for (int i = 0; i < sz; ++i) {
                        auto p = q.front();
                        q.pop();
                        if (matrix[p.first][p.second] == 0) {
                            found = true;
                            break;
                        }
                        for (int j = 0; j < 4; ++j) {
                            int x = p.first + direcs[j][0];
                            int y = p.second + direcs[j][1];
                            if (x < 0 || x >= rows 
                                || y < 0 || y >= cols) {
                                continue;
                            }
                            q.push({x, y});
                        }
                    }
                    ++level;
                }
                matrix[r][c] = level - 1;
            }
        }
        return matrix;
    }
};
