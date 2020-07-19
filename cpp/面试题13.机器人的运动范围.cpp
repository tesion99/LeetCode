/*
地上有一个m行n列的方格，从坐标 [0,0] 到坐标 [m-1,n-1] 。

一个机器人从坐标 [0, 0] 的格子开始移动，它每次可以向左、右、上、下移动一格（不能移动到方格外），

也不能进入行坐标和列坐标的数位之和大于k的格子。

例如，当k为18时，机器人能够进入方格 [35, 37] ，因为3+5+3+7=18。

但它不能进入方格 [35, 38]，因为3+5+3+8=19。请问该机器人能够到达多少个格子？

示例 1：

输入：m = 2, n = 3, k = 1
输出：3
示例 1：

输入：m = 3, n = 1, k = 0
输出：1
提示：

1 <= n,m <= 100
0 <= k <= 20

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/ji-qi-ren-de-yun-dong-fan-wei-lcof
*/
// 先统计好0~99的数字位数和，避免重复计算
// 再做上下左右四个方向的dfs
class Solution {
public:
    map<int,int> mp;
    int movingCount(int m, int n, int k) {
        for (int i = 0; i < 100; ++i) {
            mp[i] = digitSum(i);
        }
        int direcs[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        vector<vector<int>> grid(m, vector<int>(n, 0));
        int res = 0;
        dfs(grid, direcs, 0, 0, k, res);
        return res;
    }
    int digitSum(int n) {
        int sum = 0;
        while (n) {
            sum += n % 10;
            n /= 10;
        }
        return sum;
    }
    void dfs(vector<vector<int>>& grid, int direcs[4][2], int r, int c, int k, int& res) {
        if (r < 0 || r >= grid.size() || c < 0 || c >= grid[0].size() || grid[r][c]) {
            return;
        }
        grid[r][c] = 1;
        if (mp[r] + mp[c] > k) {
            return;
        }
        ++res;
        for (int i = 0; i < 4; ++i) {
            int x = r + direcs[i][0];
            int y = c + direcs[i][1];
            dfs(grid, direcs, x, y, k, res);
        }
    }
};
