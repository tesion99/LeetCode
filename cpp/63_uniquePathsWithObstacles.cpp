/*
一个机器人位于一个 m x n 网格的左上角 （起始点在下图中标记为“Start” ）。

机器人每次只能向下或者向右移动一步。机器人试图达到网格的右下角（在下图中标记为“Finish”）。

现在考虑网格中有障碍物。那么从左上角到右下角将会有多少条不同的路径？
网格中的障碍物和空位置分别用 1 和 0 来表示。

说明：m 和 n 的值均不超过 100。

示例 1:

输入:
[
  [0,0,0],
  [0,1,0],
  [0,0,0]
]
输出: 2
解释:
3x3 网格的正中间有一个障碍物。
从左上角到右下角一共有 2 条不同的路径：
1. 向右 -> 向右 -> 向下 -> 向下
2. 向下 -> 向下 -> 向右 -> 向右

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/unique-paths-ii
*/
// 同62，增加了障碍物
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        if (obstacleGrid.empty() || obstacleGrid[0].empty()) {
            return 0;
        }
        int row = obstacleGrid.size();
        int column = obstacleGrid[0].size();
        // 使用long，否则int类型提交溢出
        vector<vector<long>> dp(row, vector<long>(column, 0));
        // 每行最后一列，只有向下走一种方式
        for (int i = row - 1; i >= 0; --i) {
            if (obstacleGrid[i][column - 1] == 0) {
                dp[i][column - 1] = 1;
            } else {
                break;
            }
        }
        // 最后一行每一列，只有向右走一种方式
        for (int i = column - 1; i >= 0; --i) {
            if (obstacleGrid[row - 1][i] == 0) {
                dp[row - 1][i] = 1;
            } else {
                break;
            }
        }

        // DP[i, j] = DP[i-1, j] + DP[i, j-1];
        for (int i = row - 2; i >= 0; --i) {
            for (int j = column - 2; j >= 0; --j) {
                if (obstacleGrid[i][j] == 0) {
                    dp[i][j] = dp[i + 1][j] + dp[i][j+1];
                } else {
                    dp[i][j] = 0;
                }
            }
        }
        return dp[0][0];
    }
};
