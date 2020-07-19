/*
一个机器人位于一个 m x n 网格的左上角 （起始点在下图中标记为“Start” ）。

机器人每次只能向下或者向右移动一步。机器人试图达到网格的右下角（在下图中标记为“Finish”）。

问总共有多少条不同的路径？

说明：m 和 n 的值均不超过 100。

示例 1:

输入: m = 3, n = 2
输出: 3
解释:
从左上角开始，总共有 3 条路径可以到达右下角。
1. 向右 -> 向右 -> 向下
2. 向右 -> 向下 -> 向右
3. 向下 -> 向右 -> 向右
示例 2:

输入: m = 7, n = 3
输出: 28

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/unique-paths
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

// 简答递归，运算超时
class Solution {
public:
    int uniquePaths(int m, int n) {
        if (m <= 0 || n <= 0) {
            return 0;
        }

        if (m == 1 || n == 1) {
            return 1;
        }
        
        return uniquePaths(m - 1, n) + uniquePaths(m, n - 1);
    }
};

// 使用一个类似数组，记录计算出的路径树，避免重复递归调用
class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> path(m + 1, vector<int>(n + 1, 0));
        return uniquePaths(m, n, path);
    }
    
    int uniquePaths(int m, int n, vector<vector<int>>& path) {
        if (m <= 0 || n <= 0) {
            return 0;
        }

        if (m == 1 || n == 1) {
            return 1;
        }

        // 查找记录表，避免重复计算
        if (path[m][n] != 0) {
            return path[m][n];
        }

        int down = uniquePaths(m - 1, n, path);
        int right = uniquePaths(m, n - 1, path);
        path[m - 1][n] = down;
        path[m][n - 1] = right;
        path[m][n] = down + right;
        return  down + right;
    }
};
