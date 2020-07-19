/*
给定一个正整数 n，生成一个包含 1 到 n2 所有元素，且元素按顺时针顺序螺旋排列的正方形矩阵。

示例:

输入: 3
输出:
[
 [ 1, 2, 3 ],
 [ 8, 9, 4 ],
 [ 7, 6, 5 ]
]

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/spiral-matrix-ii
*/
// 顺时针一圈后，后续重复递归处理流程
class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> res(n, vector<int>(n, 0));
        int value = 1;
        int row = 0, column = 0;
        int start_row = 0, start_column = 0;

        while (start_row < n) {
            row = start_row;
            column = start_column;

            if (row == n - 1 && column == n - 1) {
                res[row][column] = value;
                break;
            }

            for (; column < n; ++column) {
                res[row][column] = value;
                ++value;
            }
            --column;
            ++row;

            for (; row < n; ++row) {
                res[row][column] = value;
                ++value;
            }
            --row;
            --column;

            for (; column >= start_column; --column) {
                res[row][column] = value;
                ++value;
            }
            ++column;
            --row;

            for (; row > start_row; --row) {
                res[row][column] = value;
                ++value;
            }
            // 更新下次开始行列号
            ++start_row;
            ++start_column;
            --n;
        }

        return res;
    }
};
