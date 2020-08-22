/*
给定一个可能含有重复元素的整数数组，要求随机输出给定的数字的索引。 您可以假设给定的数字一定存在于数组中。

注意：
数组大小可能非常大。 使用太多额外空间的解决方案将不会通过测试。

示例:

int[] nums = new int[] {1,2,3,3,3};
Solution solution = new Solution(nums);

// pick(3) 应该返回索引 2,3 或者 4。每个索引的返回概率应该相等。
solution.pick(3);

// pick(1) 应该返回 0。因为只有nums[0]等于1。
solution.pick(1);


来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/random-pick-index
*/
// 使用map映射每个数对应的index集合
// 因需要保证同一个数的每个索引返回的概率相同，故使用轮询方式，保证按序返回索引
class Solution {
public:
    Solution(vector<int>& nums) {
        for (int i = 0; i < nums.size(); ++i) {
            rec[nums[i]].push_back(i);
        }
    }
    
    int pick(int target) {
        int idx = rec[target].front();
        rec[target].pop_front();
        rec[target].push_back(idx);
        return idx;
    }
private:
    map<int, deque<int>> rec;
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * int param_1 = obj->pick(target);
 */
