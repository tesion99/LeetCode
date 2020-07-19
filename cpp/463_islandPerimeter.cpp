/*
给定一个包含 0 和 1 的二维网格地图，其中 1 表示陆地 0 表示水域。

网格中的格子水平和垂直方向相连（对角线方向不相连）。

整个网格被水完全包围，但其中恰好有一个岛屿（或者说，一个或多个表示陆地的格子相连组成的岛屿）。

岛屿中没有“湖”（“湖” 指水域在岛屿内部且不和岛屿周围的水相连）。

格子是边长为 1 的正方形。网格为长方形，且宽度和高度均不超过 100 。计算这个岛屿的周长。
 

示例 :

输入:
[[0,1,0,0],
 [1,1,1,0],
 [0,1,0,0],
 [1,1,0,0]]

输出: 16


来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/island-perimeter
*/
// 当一个点，向4个方向遍历时，有两种情况：
// 1. 下一个点操作边界 或者下一个点为0，此时表明需要增加一条边，即周长 + 1
// 2. 否则检测是否为之前遍历过的点，如是，则退出，否则更新当前点为2，表明已访问
// 从该点继续dfs遍历
class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        if (grid.empty() || grid[0].empty()) {
            return 0;
        }

        int perimeter = 0;
        int direcs[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        for (int r = 0; r < grid.size(); ++r) {
            for (int c = 0; c < grid[0].size(); ++c) {
                if (grid[r][c] == 0) continue;

                dfs(grid, direcs, r, c, perimeter);
                return perimeter;
            }
        }
        return perimeter;
    }

    void dfs(vector<vector<int>>& grid, int direcs[4][2], int r, int c, int& perimeter) {
        if (r < 0 || r >= grid.size() || c < 0 || 
            c >= grid[0].size() || grid[r][c] == 0) {
            ++perimeter;
            return;
        }

        if (grid[r][c] == 2) {
            return;
        }

        grid[r][c] = 2;
        for (int i = 0; i < 4; ++i) {
            int x = r + direcs[i][0];
            int y = c + direcs[i][1];
            dfs(grid, direcs, x, y, perimeter);
        }
    }
};
