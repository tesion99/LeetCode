/*
给定一个含有 M x N 个元素的矩阵（M 行，N 列），请以对角线遍历的顺序返回这个矩阵中的所有元素，对角线遍历如下图所示。

 

示例:

输入:
[
 [ 1, 2, 3 ],
 [ 4, 5, 6 ],
 [ 7, 8, 9 ]
]

输出:  [1,2,4,7,5,3,6,8,9]

说明:

给定矩阵中的元素总数不会超过 100000 。


来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/diagonal-traverse
*/
// 确定对角线个数 = 行长度 + 列长度 - 1
// 同一条对角线上 行号 + 列号等于一个相同的数
// 遍历超过最大行或列时，证明有列或行全部遍历，需对其实列或行号进行调整
class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& matrix) {
        if (matrix.empty() || matrix[0].empty()) {
            return vector<int>();
        }
        int rows = matrix.size() - 1, columns = matrix[0].size() - 1;
        int start_row = 0, start_column = 0;
        int turn = 0, max_turn = rows + columns + 1;
        vector<int> res;
        while (turn < max_turn) {
            // 本轮turn超过最大列时，证明有一行的数据已经全部加入
            if (turn > columns) {
                ++start_row;
            }
            // 当本轮turn超过最大行时，证明有一列的数据已经全部加入
            if (turn > rows) {
                ++start_column;
            }
            // 根据对角线先 r + c = turn进行对角线元素插入
            if (turn & 1) {
                for (int r = start_row, c = turn - start_row; r <= rows && c >= start_column; ++r, --c) {
                    res.push_back(matrix[r][c]);
                }
            } else {
                for (int r = turn - start_column, c = start_column; r >= start_row && c <=  columns; --r, ++c) {
                    res.push_back(matrix[r][c]);
                }
            }
            ++turn;
        }
        return res;
    }
};
