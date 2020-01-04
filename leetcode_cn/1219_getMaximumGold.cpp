/*
你要开发一座金矿，地质勘测学家已经探明了这座金矿中的资源分布，并用大小为 m * n 的网格 grid 进行了标注。每个单元格中的整数就表示这一单元格中的黄金数量；如果该单元格是空的，那么就是 0。

为了使收益最大化，矿工需要按以下规则来开采黄金：

每当矿工进入一个单元，就会收集该单元格中的所有黄金。
矿工每次可以从当前位置向上下左右四个方向走。
每个单元格只能被开采（进入）一次。
不得开采（进入）黄金数目为 0 的单元格。
矿工可以从网格中 任意一个 有黄金的单元格出发或者是停止。
 

示例 1：

输入：grid = [[0,6,0],[5,8,7],[0,9,0]]
输出：24
解释：
[[0,6,0],
 [5,8,7],
 [0,9,0]]
一种收集最多黄金的路线是：9 -> 8 -> 7。


来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/path-with-maximum-gold
*/

// 定义上下左右方向，从每个非零节点开始回溯查找
class Solution {
public:
    int getMaximumGold(vector<vector<int>>& grid) {
        if (grid.empty() || grid[0].empty()) {
            return 0;
        }

        int directions[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

        int max_gold = 0;
        int row = grid.size() - 1, column = grid[0].size() - 1;
        vector<int> path;
        int sum = 0;
        for (int i = 0; i <= row; ++i) {
            for (int j = 0; j <= column; ++j) {
                if (grid[i][j] == 0) {
                    continue;
                }
                sum = 0;
                path.clear();
                dfs(grid, i, j, directions, sum, path, max_gold);
            }
        }
        //dfs(grid, 0, 0, directions, sum, path, max_gold);
        return max_gold;
    }

    void dfs(vector<vector<int>>& grid, int row, int column, int directions[4][2], int& sum,  vector<int>& path, int& max_gold) {
        if (row < 0 || row >= grid.size() || column < 0 || column >= grid[0].size()) {
            return;
        }
        if (grid[row][column] == 0 && !path.empty()) {
            return;
        }

        int tmp = grid[row][column];
        if (tmp != 0) {
            grid[row][column] = 0;  // 标记为0，避免后续重复操作
            sum += tmp;
            path.push_back(tmp);
            if (sum > max_gold) {
                max_gold = sum;
            }
        }
        // 递归访问上下左右
        for (int i = 0; i < 4; ++i) {
            int x = row + directions[i][0];
            int y = column + directions[i][1];
            dfs(grid, x, y, directions, sum, path, max_gold);
        }

        if (tmp != 0) {
            path.pop_back();
            sum -= tmp;
            grid[row][column] = tmp;
        }
    }
};
