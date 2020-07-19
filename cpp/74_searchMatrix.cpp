/*
编写一个高效的算法来判断 m x n 矩阵中，是否存在一个目标值。该矩阵具有如下特性：

每行中的整数从左到右按升序排列。
每行的第一个整数大于前一行的最后一个整数。
示例 1:

输入:
matrix = [
  [1,   3,  5,  7],
  [10, 11, 16, 20],
  [23, 30, 34, 50]
]
target = 3
输出: true
示例 2:

输入:
matrix = [
  [1,   3,  5,  7],
  [10, 11, 16, 20],
  [23, 30, 34, 50]
]
target = 13
输出: false

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/search-a-2d-matrix
*/
// 先确定对应的行， 然后对该行进行二分查找
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if (matrix.empty() || matrix[0].empty()) {
            return false;
        }

        int rows = matrix.size() - 1;
        int columns = matrix[0].size() - 1;
        for (int i = 0; i <= rows; ++i) {
            if (target > matrix[i][columns]) {
                continue;
            }
            int left = 0, right = columns;
            while (left <= right) {
                int mid = (left + right) / 2;
                if (matrix[i][mid] == target) {
                    return true;
                } else if (matrix[i][mid] > target) {
                    right = mid - 1;
                } else {
                    left = mid + 1;
                }
            }
            break;
        }

        return false;
    }
};

// 先对行进行二分查找，使用该行最大值比对target，确定target大致的行
// 在对特定行，进行二分查找
// 双重查找后，效率进一步提高
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if (matrix.empty() || matrix[0].empty()) {
            return false;
        }

        int rows = matrix.size() - 1;
        int columns = matrix[0].size() - 1;
        int lr = 0, rr = rows;
        while (lr <= rr) {
            int mr = (lr + rr) / 2;
            if (target > matrix[mr][columns]) {
                lr = mr + 1;
            } else if (target < matrix[mr][columns]){
                rr = mr - 1;
            } else {
                return true;
            }
        }

        if (lr > rows) {
            return false;
        }

        int left = 0, right = columns;
        while (left <= right) {
            int mid = (left + right) / 2;
            if (matrix[lr][mid] == target) {
                return true;
            } else if (matrix[lr][mid] > target) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }

        return false;
    }
};
