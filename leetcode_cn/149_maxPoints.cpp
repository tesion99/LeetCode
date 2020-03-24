/*
给定一个二维平面，平面上有 n 个点，求最多有多少个点在同一条直线上。

示例 1:

输入: [[1,1],[2,2],[3,3]]
输出: 3
解释:
^
|
|        o
|     o
|  o  
+------------->
0  1  2  3  4
示例 2:

输入: [[1,1],[3,2],[5,3],[4,1],[2,3],[1,4]]
输出: 4
解释:
^
|
|  o
|     o        o
|        o
|  o        o
+------------------->
0  1  2  3  4  5  6


来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/max-points-on-a-line
*/
class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        int res = 0;
        ostringstream oss;
        for (int i = 0; i < points.size(); ++i) {
            int dup = 0, cnt = 0;    // 记录重复点
            map<string, int> m;
            for (int j = i + 1; j < points.size(); ++j) {
                // 直线方程 y = ax + b，求a, b
                int delta_y = points[j][1] - points[i][1];
                int delta_x = points[j][0] - points[i][0];
                if (delta_y == 0 && delta_x == 0) {
                    ++dup;
                    continue;
                }
                int gcd_num = gcd(delta_y, delta_x);
                delta_y /= gcd_num;
                delta_x /= gcd_num;
                oss.str("");
                oss << delta_y << "@" << delta_x;
                string key = oss.str();
                ++m[key];
                cnt = max(cnt, m[key]);
            }
            res = max(res, cnt + dup + 1);
        }
        
        return res;
    }

    int gcd(int a, int b) {
        while (b != 0) {
            int r = a % b;
            a = b;
            b = r;
        }
        return a;
    }
};
