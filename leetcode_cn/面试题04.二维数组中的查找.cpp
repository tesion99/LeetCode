// 同 240题
class Solution {
public:
    bool findNumberIn2DArray(vector<vector<int>>& matrix, int target) {
        if (matrix.empty() || matrix[0].empty()) {
            return false;
        }
        int rows = matrix.size() - 1, cols = matrix[0].size() - 1;
        int r = rows, c = 0;
        while (r >= 0 && c <= cols) {
            if (matrix[r][c] > target) {
                --r;
            } else if (matrix[r][c] < target) {
                ++c;
            } else {
                return true;
            }
        }
        return false;
    }
};
