/*
在一个 XY 坐标系中有一些点，我们用数组 coordinates 来分别记录它们的坐标，

其中 coordinates[i] = [x, y] 表示横坐标为 x、纵坐标为 y 的点。

请你来判断，这些点是否在该坐标系中属于同一条直线上，是则返回 true，否则请返回 false。

输入：coordinates = [[1,2],[2,3],[3,4],[4,5],[5,6],[6,7]]
输出：true

输入：coordinates = [[1,1],[2,2],[3,4],[4,5],[5,6],[7,7]]
输出：false

提示：

2 <= coordinates.length <= 1000
coordinates[i].length == 2
-10^4 <= coordinates[i][0], coordinates[i][1] <= 10^4
coordinates 中不含重复的点


来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/check-if-it-is-a-straight-line
*/
// 确定第一个点，判断后续点与该点组成的直线的斜率是否一致
class Solution {
public:
    bool checkStraightLine(vector<vector<int>>& coordinates) {
        if (coordinates.size() == 2) {
            return true;
        }

        int rows = coordinates.size() - 1;

        bool flag = false;
        int x = 0, y = 0;
        for (int r = 1; r <= rows; ++r) {
            int delta_y = coordinates[r][1] - coordinates[0][1];
            int delta_x = coordinates[r][0] - coordinates[0][0];
            int g = gcd(delta_y, delta_x);
            delta_y /= g;
            delta_x /= g;
            if (!flag) {
                flag = true;
                x = delta_x;
                y = delta_y;
                continue;
            }
            if (x == 0 && coordinates[r][0] != coordinates[0][0]) {
                return false;
            }
            if (y == 0 && coordinates[r][1] != coordinates[0][1]) {
                return false;
            }

            if (x != 0 && y != 0) {
                double k = y * 1.0 / x;
                double cur = delta_y * 1.0 / delta_x;
                if (cur != k) return false;
            }
        }
        return true;
    }
};
