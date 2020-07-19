/*
给定一个整数数组  nums，求出数组从索引 i 到 j  (i ≤ j) 范围内元素的总和，包含 i,  j 两点。

示例：

给定 nums = [-2, 0, 3, -5, 2, -1]，求和函数为 sumRange()

sumRange(0, 2) -> 1
sumRange(2, 5) -> -1
sumRange(0, 5) -> -3
说明:

你可以假设数组不可变。
会多次调用 sumRange 方法。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/range-sum-query-immutable
*/
// 使用DP二维数组构造出所有的range组合，使sumRange方法直接返回
class NumArray {
public:
    NumArray(vector<int>& nums) {
        // NxN的矩阵，右上三角
        int sz = nums.size();
        dp_ = vector<vector<int>>(sz, vector<int>(sz, 0));
        // 构建对角线
        for (int i = 0; i < sz; ++i) {
            dp_[i][i] = nums[i];
        }
        for (int i = 0; i < sz; ++i) {
            for (int j = i + 1; j < sz; ++j) {
                dp_[i][j] = dp_[i][j - 1] + dp_[j][j];
            }
        }
    }
    
    int sumRange(int i, int j) {
        return dp_[i][j];
    }
private:
    vector<vector<int>> dp_;
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(i,j);
 */
