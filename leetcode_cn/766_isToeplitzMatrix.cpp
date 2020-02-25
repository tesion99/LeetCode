/*
如果一个矩阵的每一方向由左上到右下的对角线上具有相同元素，那么这个矩阵是托普利茨矩阵。

给定一个 M x N 的矩阵，当且仅当它是托普利茨矩阵时返回 True。

示例 1:

输入: 
matrix = [
  [1,2,3,4],
  [5,1,2,3],
  [9,5,1,2]
]
输出: True
解释:
在上述矩阵中, 其对角线为:
"[9]", "[5, 5]", "[1, 1, 1]", "[2, 2, 2]", "[3, 3]", "[4]"。
各条对角线上的所有元素均相同, 因此答案是True。
示例 2:

输入:
matrix = [
  [1,2],
  [2,2]
]
输出: False
解释: 
对角线"[1, 2]"上的元素不同。
说明:

 matrix 是一个包含整数的二维数组。
matrix 的行数和列数均在 [1, 20]范围内。
matrix[i][j] 包含的整数在 [0, 99]范围内。
进阶:

如果矩阵存储在磁盘上，并且磁盘内存是有限的，因此一次最多只能将一行矩阵加载到内存中，该怎么办？
如果矩阵太大以至于只能一次将部分行加载到内存中，该怎么办？

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/toeplitz-matrix
*/
class Solution {
public:
    bool isToeplitzMatrix(vector<vector<int>>& matrix) {
        if (matrix.empty() || matrix[0].empty()) {
            return false;
        }
        int rows = matrix.size() - 1, cols = matrix[0].size() - 1;
        int sr = rows, sc = 0, cnt = 0;
        int turn = 0, max_turn = rows + cols + 1;
        bitset<100> bs;
        while (turn < max_turn) {
            cnt = 0;
            bs.reset();
            if (turn > rows) {
                ++sc;
            }
            for (int r = sr, c = sc; r <= rows && c <= cols; ++r, ++c) {
                ++cnt;
                bs[matrix[r][c]] = 1;
            }
            // 对角线上所有元素都相等
            if (bs.count() != 1) {
                return false;
            }
            ++turn;
            sr = sr > 0 ? sr - 1 : 0;
        }
        return true;
    }
};

// 改用记录每条对角线第一个元素与后续对比
class Solution {
public:
    bool isToeplitzMatrix(vector<vector<int>>& matrix) {
        if (matrix.empty() || matrix[0].empty()) {
            return false;
        }
        int rows = matrix.size() - 1, cols = matrix[0].size() - 1;
        int sr = rows, sc = 0;
        int turn = 0, max_turn = rows + cols + 1;
        while (turn < max_turn) {
            if (turn > rows) {
                ++sc;
            }
            bool flag = false;
            int pre;
            for (int r = sr, c = sc; r <= rows && c <= cols; ++r, ++c) {
                if (!flag) {
                    pre = matrix[r][c];
                    flag = true;
                    continue;
                }
                if (pre != matrix[r][c]) {
                    return false;
                }
            }
            ++turn;
            sr = sr > 0 ? sr - 1 : 0;
        }
        return true;
    }
};

// 优化，解决进阶问题
class Solution {
public:
    bool isToeplitzMatrix(vector<vector<int>>& matrix) {
        if (matrix.empty() || matrix[0].empty()) {
            return false;
        }
        int rows = matrix.size() - 1, cols = matrix[0].size() - 1;
        map<pair<int,int>, bitset<100>> m;
        for (int r = 0; r <= rows; ++r) {
            for (int c = 0; c <= cols; ++c) {
                int d = min(r, c);
                m[make_pair(r - d, c - d)][matrix[r][c]] = 1;
            }
        }

        for (auto& p : m) {
            if (p.second.count() != 1) {
                return false;
            }
        }
        return true;
    }
};
