/*
编写函数，实现许多图片编辑软件都支持的「颜色填充」功能。

待填充的图像用二维数组 image 表示，元素为初始颜色值。初始坐标点的横坐标为 sr 纵坐标为 sc。需要填充的新颜色为 newColor 。

「周围区域」是指颜色相同且在上、下、左、右四个方向上存在相连情况的若干元素。

请用新颜色填充初始坐标点的周围区域，并返回填充后的图像。

 

示例：

输入：
image = [[1,1,1],[1,1,0],[1,0,1]] 
sr = 1, sc = 1, newColor = 2
输出：[[2,2,2],[2,2,0],[2,0,1]]
解释: 
初始坐标点位于图像的正中间，坐标 (sr,sc)=(1,1) 。
初始坐标点周围区域上所有符合条件的像素点的颜色都被更改成 2 。
注意，右下角的像素没有更改为 2 ，因为它不属于初始坐标点的周围区域。
 

提示：

image 和 image[0] 的长度均在范围 [1, 50] 内。
初始坐标点 (sr,sc) 满足 0 <= sr < image.length 和 0 <= sc < image[0].length 。
image[i][j] 和 newColor 表示的颜色值在范围 [0, 65535] 内。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/color-fill-lcci
*/
// BFS
class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        if (image.empty() || image[0].empty()) return {};

        int rows = image.size() - 1;
        int cols = image[0].size() - 1;
        vector<vector<int>> visited(rows + 1, vector<int>(cols + 1, 0));
        int direcs[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        queue<pair<int, int>> q;
        int value = image[sr][sc];

        q.push(make_pair(sr, sc));

        while (!q.empty()) {
            auto& p = q.front();
            for (int i = 0; i < 4; ++i) {
                int x = p.first + direcs[i][0];
                int y = p.second + direcs[i][1];
                if (x < 0 || x > rows || y < 0 || y > cols
                    || visited[x][y] || image[x][y] != value) continue;

                q.push(make_pair(x, y));
            }
            visited[p.first][p.second] = 1;
            image[p.first][p.second] = newColor;
            q.pop();
        }
        return image;
    }
};
