/*
给你一个由 '1'（陆地）和 '0'（水）组成的的二维网格，请你计算网格中岛屿的数量。

岛屿总是被水包围，并且每座岛屿只能由水平方向和/或竖直方向上相邻的陆地连接形成。

此外，你可以假设该网格的四条边均被水包围。

示例 1:

输入:
11110
11010
11000
00000
输出: 1
示例 2:

输入:
11000
11000
00100
00011
输出: 3
解释: 每座岛屿只能由水平和/或竖直方向上相邻的陆地连接而成。


来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/number-of-islands
*/
class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        if (grid.empty() || grid[0].empty()) {
            return 0;
        }

        int res = 0;
        int rows = grid.size() - 1;
        int cols = grid[0].size() - 1;
        int direcs[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        for (int r = 0; r <= rows; ++r) {
            for (int c = 0; c <= cols; ++c) {
                if (grid[r][c] == '1') {
                    dfs(grid, direcs, r, c);
                    ++res;
                }
            }
        }
        return res;
    }

    void dfs(vector<vector<char>>& grid, int direcs[4][2], int r, int c) {
        if (r < 0 || r >= grid.size() || c < 0 || c >= grid[0].size() || grid[r][c] != '1') {
            return;
        }

        grid[r][c] = '2';
        for (int i = 0; i < 4; ++i) {
            int x = r + direcs[i][0];
            int y = c + direcs[i][1];
            dfs(grid, direcs, x, y);
        }
    }
};
