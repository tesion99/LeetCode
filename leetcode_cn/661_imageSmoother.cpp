/*
包含整数的二维矩阵 M 表示一个图片的灰度。你需要设计一个平滑器来让每一个单元的灰度成为平均灰度 (向下舍入) ，

平均灰度的计算是周围的8个单元和它本身的值求平均，如果周围的单元格不足八个，则尽可能多的利用它们。

示例 1:

输入:
[[1,1,1],
 [1,0,1],
 [1,1,1]]
输出:
[[0, 0, 0],
 [0, 0, 0],
 [0, 0, 0]]
解释:
对于点 (0,0), (0,2), (2,0), (2,2): 平均(3/4) = 平均(0.75) = 0
对于点 (0,1), (1,0), (1,2), (2,1): 平均(5/6) = 平均(0.83333333) = 0
对于点 (1,1): 平均(8/9) = 平均(0.88888889) = 0
注意:

给定矩阵中的整数范围为 [0, 255]。
矩阵的长和宽的范围均为 [1, 150]。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/image-smoother
*/
// BFS
class Solution {
public:
    vector<vector<int>> imageSmoother(vector<vector<int>>& M) {
        if (M.empty() || M[0].empty()) return M;

        int direcs[8][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}, 
                            {-1, -1}, {1, -1}, {-1, 1}, {1, 1}};
        int row = M.size() - 1;
        int col = M[0].size() - 1;
        vector<vector<int>> res(M);

        for (int r = 0; r <= row; ++r) {
            for (int c = 0; c <= col; ++c) {
                int sum = M[r][c];
                int cnt = 1;
                for (int i = 0; i < 8; ++i) {
                    int x = r + direcs[i][0];
                    int y = c + direcs[i][1];
                    if (x < 0 || x > row || y < 0 || y > col) continue;
                    sum += M[x][y];
                    ++cnt;
                }
                res[r][c] = sum / cnt;
            }
        }
        return res;
    }
};
