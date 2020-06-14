/*
给定一个包含了一些 0 和 1 的非空二维数组 grid 。

一个 岛屿 是由一些相邻的 1 (代表土地) 构成的组合，

这里的「相邻」要求两个 1 必须在水平或者竖直方向上相邻。

你可以假设 grid 的四个边缘都被 0（代表水）包围着。

找到给定的二维数组中最大的岛屿面积。(如果没有岛屿，则返回面积为 0 。)

 

示例 1:

[[0,0,1,0,0,0,0,1,0,0,0,0,0],
 [0,0,0,0,0,0,0,1,1,1,0,0,0],
 [0,1,1,0,1,0,0,0,0,0,0,0,0],
 [0,1,0,0,1,1,0,0,1,0,1,0,0],
 [0,1,0,0,1,1,0,0,1,1,1,0,0],
 [0,0,0,0,0,0,0,0,0,0,1,0,0],
 [0,0,0,0,0,0,0,1,1,1,0,0,0],
 [0,0,0,0,0,0,0,1,1,0,0,0,0]]
对于上面这个给定矩阵应返回 6。注意答案不应该是 11 ，因为岛屿只能包含水平或垂直的四个方向的 1 。

示例 2:

[[0,0,0,0,0,0,0,0]]
对于上面这个给定的矩阵, 返回 0。

 

注意: 给定的矩阵grid 的长度和宽度都不超过 50。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/max-area-of-island
*/
// 与统计岛屿个数类似，统计每个岛屿中1的个数，即为面积，比较获得最大面积即可
class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        if (grid.empty() || grid[0].empty()) return 0;

        int res = 0;
        int direcs[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        for (int r = 0; r < grid.size(); ++r) {
            for (int c = 0; c < grid[0].size(); ++c) {
                if (grid[r][c] != 1) {
                    continue;
                }
                int area = 0;
                dfs(grid, direcs, r, c, area);
                res = max(res, area);
            }
        }
        return res;
    }

    void dfs(vector<vector<int>>& grid, int direcs[4][2], int r, int c, int& area) {
        if (r < 0 || r >= grid.size() || 
            c < 0 || c >= grid[0].size() || grid[r][c] != 1) {
            return;
        }
        ++area;
        grid[r][c] = 2;
        for (int i = 0; i < 4; ++i) {
            int x = r + direcs[i][0];
            int y = c + direcs[i][1];
            dfs(grid, direcs, x, y, area);
        }
    }
};
