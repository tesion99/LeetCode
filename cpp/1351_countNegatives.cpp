/*
给你一个 m * n 的矩阵 grid，矩阵中的元素无论是按行还是按列，都以非递增顺序排列。 

请你统计并返回 grid 中 负数 的数目。

 

示例 1：

输入：grid = [[4,3,2,-1],[3,2,1,-1],[1,1,-1,-2],[-1,-1,-2,-3]]
输出：8
解释：矩阵中共有 8 个负数。
示例 2：

输入：grid = [[3,2],[1,0]]
输出：0
示例 3：

输入：grid = [[1,-1],[-1,-1]]
输出：3
示例 4：

输入：grid = [[-1]]
输出：1
 

提示：

m == grid.length
n == grid[i].length
1 <= m, n <= 100
-100 <= grid[i][j] <= 100

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/count-negative-numbers-in-a-sorted-matrix
*/
// 因为行与列有序，可考虑从左下角或右上角出发
// 根据当前值的大小，递增行号或列号
class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        if (grid.empty() || grid[0].empty()) {
            return 0;
        }

        int res = 0;
        int rows = grid.size() - 1, cols = grid[0].size() - 1;
        int r = 0, c = cols;
        // 从右上角开始遍历
        while (r <= rows && c >= 0) {
            if (grid[r][c] < 0) {
                res += rows - r + 1;
                --c;
            } else {
                ++r;
            }
        }
        return res;
    }
};
