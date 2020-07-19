/*
给定一个包含非负整数的 m x n 网格，请找出一条从左上角到右下角的路径，使得路径上的数字总和为最小。

说明：每次只能向下或者向右移动一步。

示例:

输入:
[
  [1,3,1],
  [1,5,1],
  [4,2,1]
]
输出: 7
解释: 因为路径 1→3→1→1→1 的总和最小。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/minimum-path-sum
*/
// 动态规划，记录已走过的路径，防止重复
class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        if (grid.empty() || grid[0].empty()) {
            return 0;
        }
        vector<vector<int>> dp(grid.size() + 1, vector<int>(grid[0].size() + 1, 0));

        return backtrace(grid, grid.size(), grid[0].size(), 0, 0, dp);
    }

    int backtrace(vector<vector<int>>& grid, int numRow, int numColumn, int row, int column, vector<vector<int>>& dp) {
        if (row < 0 || row >= numRow || column < 0 || column >= numColumn) {
            return -1;
        }

        if (dp[row][column] != 0) {
            return dp[row][column];
        }

        int right = backtrace(grid, numRow, numColumn, row, column + 1, dp);
        int down = backtrace(grid, numRow,numColumn, row + 1, column, dp);
        int value = 0;
        if (right == -1 && down == -1) {
            value = 0;
        } else if (right == -1) {
            dp[row + 1][column] = down;
            value = down;
        } else if (down == -1) {
            dp[row][column + 1] = right;
            value = right;
        } else {
            value = min(right, down);
        }
        dp[row][column] = grid[row][column] + value;
        return dp[row][column];
    }
};
