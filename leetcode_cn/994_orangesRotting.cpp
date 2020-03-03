/*
在给定的网格中，每个单元格可以有以下三个值之一：

值 0 代表空单元格；
值 1 代表新鲜橘子；
值 2 代表腐烂的橘子。
每分钟，任何与腐烂的橘子（在 4 个正方向上）相邻的新鲜橘子都会腐烂。

返回直到单元格中没有新鲜橘子为止所必须经过的最小分钟数。如果不可能，返回 -1。


示例 1：
输入：[[2,1,1],[1,1,0],[0,1,1]]
输出：4
示例 2：

输入：[[2,1,1],[0,1,1],[1,0,1]]
输出：-1
解释：左下角的橘子（第 2 行， 第 0 列）永远不会腐烂，因为腐烂只会发生在 4 个正向上。
示例 3：

输入：[[0,2]]
输出：0
解释：因为 0 分钟时已经没有新鲜橘子了，所以答案就是 0 。
 

提示：

1 <= grid.length <= 10
1 <= grid[0].length <= 10
grid[i][j] 仅为 0、1 或 2


来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/rotting-oranges
*/
// 每次记录上一次腐烂橘子的坐标，遍历坐标，从该坐标的上下左右4个方向，获取下一轮腐烂橘子的坐标
// 当下一轮没有橘子腐烂时，退出
class Solution {
public:
    int rows, cols;
    int orangesRotting(vector<vector<int>>& grid) {
        if (grid.empty() || grid[0].empty()) {
            return -1;
        }

        int direcs[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        set<pair<int, int>> pos;
        rows = grid.size() - 1;
        cols = grid[0].size() - 1;

        // 预先加入腐烂的节点坐标
        int total = 0;
        for (int r = 0; r <= rows; ++r) {
            for (int c = 0; c <= cols; ++c) {
                if (grid[r][c] == 2) {
                    pos.insert(make_pair(r, c));
                }
                if (grid[r][c] != 0) {
                    ++total;
                }
            }
        }

        if (total == pos.size()) {
            return 0;
        }

        int minute = -1, orages = 0;
        while (!pos.empty()) {
            orages += pos.size();
            set<pair<int, int>> cur;
            check(grid, pos, cur, direcs);
            pos.swap(cur);
            ++minute;
        }
        
        return total != orages ? -1 : minute;
    }

    void check(vector<vector<int>>& grid, set<pair<int, int>>& pos, set<pair<int, int>>& cur, int direcs[4][2]) {
        for (auto& p : pos) {
            for (int i = 0; i < 4; ++i) {
                int x = p.first + direcs[i][0];
                int y = p.second + direcs[i][1];
                if (x >= 0 && x <= rows && y >= 0 && y <= cols) {
                    if (grid[x][y] == 1) {
                        cur.insert(make_pair(x, y));
                        grid[x][y] = 2;
                    }
                }
            }
        }
    }
};
