/*
 你有一个用于表示一片土地的整数矩阵land，该矩阵中每个点的值代表对应地点的海拔高度。
 若值为0则表示水域。由垂直、水平或对角连接的水域为池塘。池塘的大小是指相连接的水域的个数。
 编写一个方法来计算矩阵中所有池塘的大小，返回值需要从小到大排序。

示例：

输入：
[
  [0,2,1,0],
  [0,1,0,1],
  [1,1,0,1],
  [0,1,0,1]
]
输出： [1,2,4]
提示：

0 < len(land) <= 1000
0 < len(land[i]) <= 1000


来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/pond-sizes-lcci
*/
// 有题意只，水域面积计算由当前点，扩散至上下左右，以及左上、左下、右上、右下等八个方向
// 遍历矩阵中的0，该点出发，递归遍历8个发现坐标点的值
// 需要注意的是对已遍历过的0，需要记录，这里使用设置为一个特殊值-1的方式来标记
class Solution {
public:
    vector<int> pondSizes(vector<vector<int>>& land) {
        if (land.empty() || land[0].empty()) {
            return vector<int>();
        }

        vector<int> res;
        int direcs[8][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}, {-1, -1}, {1, 1}, {-1, 1}, {1, -1}};
        for (int i = 0; i < land.size(); ++i) {
            for (int j = 0; j < land[0].size(); ++j) {
                if (land[i][j] != 0 || land[i][j] == -1) {
                    continue;
                }
                int ret = backtrace(land, direcs, i, j);
                res.push_back(ret);
            }
        }
        sort(res.begin(), res.end());
        return res;
    }
    int backtrace(vector<vector<int>>& land, int direcs[8][2], int x, int y) {
        if (x < 0 || x >= land.size() || y < 0 || y >= land[0].size()) {
            return 0;
        }
        if (land[x][y] != 0 || land[x][y] == -1) {
            return 0;
        }
        int cnt = 1;
        land[x][y] = -1;
        for (int i = 0; i < 8; ++i) {
            cnt += backtrace(land, direcs, x + direcs[i][0], y + direcs[i][1]);
        }
        return cnt;
    }

};
