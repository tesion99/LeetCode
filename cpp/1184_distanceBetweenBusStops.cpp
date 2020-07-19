/*
环形公交路线上有 n 个站，按次序从 0 到 n - 1 进行编号。我们已知每一对相邻公交站之间的距离，

distance[i] 表示编号为 i 的车站和编号为 (i + 1) % n 的车站之间的距离。

环线上的公交车都可以按顺时针和逆时针的方向行驶。

返回乘客从出发点 start 到目的地 destination 之间的最短距离。

提示：

1 <= n <= 10^4
distance.length == n
0 <= start, destination < n
0 <= distance[i] <= 10^4

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/distance-between-bus-stops
*/
// 先计算所有路径总和sum
// 计算start~destination之间的路径和cur
// 取sum - cur与cur之间的最小值
// Note: 由于是环线，需要注意start > destination的情况
class Solution {
public:
    int distanceBetweenBusStops(vector<int>& distance, int start, int destination) {
        int sum = 0;
        if (start == 0 && destination == distance.size() - 1) {
            return distance.back();
        }

        for (auto n : distance) {
            sum += n;
        }
        
        int i = start, j = destination;
        if (start >= destination) {
            i = destination;
            j = start;
        }
        int cur = 0;
        while (i < j) {
            cur += distance[i];
            ++i;
        }
        return min(sum - cur, cur);
    }
};
