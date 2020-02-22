/*
给定一个 n × n 的二维矩阵表示一个图像。

将图像顺时针旋转 90 度。

说明：

你必须在原地旋转图像，这意味着你需要直接修改输入的二维矩阵。请不要使用另一个矩阵来旋转图像。

示例 1:

给定 matrix = 
[
  [1,2,3],
  [4,5,6],
  [7,8,9]
],

原地旋转输入矩阵，使其变为:
[
  [7,4,1],
  [8,5,2],
  [9,6,3]
]


示例 2:

给定 matrix =
[
  [ 5, 1, 9,11],
  [ 2, 4, 8,10],
  [13, 3, 6, 7],
  [15,14,12,16]
], 

原地旋转输入矩阵，使其变为:
[
  [15,13, 2, 5],
  [14, 3, 4, 1],
  [12, 6, 8, 9],
  [16, 7,10,11]
]

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/rotate-image
*/
// 先旋转最外层，逐步深入到内层
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int rows = matrix.size() - 1;
        int columns = rows;
        int r = 0, c = 0;
        
        while (r <= rows && c <= columns) {
            if (r == rows && c == columns) {
                break;
            }
            int cur_r = r, cur_c = c;
            // 第一行和第一列交换
            while (cur_c <= columns) {
                swap(matrix[r][cur_c], matrix[cur_c][r]);
                ++cur_c;
            }
            // 第一列与最后一行交换
            cur_c = columns;
            while (cur_r <= rows) {
                swap(matrix[cur_r][c], matrix[rows][cur_c]);
                ++cur_r;
                --cur_c;
            }
            // 最后一行与最后一列
            cur_r = rows;
            cur_c = c;
            while (cur_c <= columns) {
                swap(matrix[rows][cur_c], matrix[cur_c][columns]);
                ++cur_c;
            }
            // 对称交换第一列与最后一列
            int i = r, j = rows;
            while (i < j) {
                swap(matrix[i][c], matrix[j][c]);
                swap(matrix[i][columns], matrix[j][columns]);
                ++i;
                --j;
            }
            // 对称交换第一行与最后一行其余未交换的元素
            i = c + 1;
            j = columns - 1;
            while (i < j) {
                swap(matrix[r][i], matrix[r][j]);
                swap(matrix[rows][i], matrix[rows][j]);
                ++i;
                --j;
            }
            ++c;
            ++r;
            --rows;
            --columns;
        }
    }
};
