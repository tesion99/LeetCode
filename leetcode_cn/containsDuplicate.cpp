/*
给定一个整数数组，判断是否存在重复元素。

如果任何值在数组中出现至少两次，函数返回 true。如果数组中每个元素都不相同，则返回 false。

示例 1:

输入: [1,2,3,1]
输出: true
示例 2:

输入: [1,2,3,4]
输出: false
示例 3:

输入: [1,1,1,3,3,4,3,2,4,2]
输出: true
--------------------------------
Note:
    考虑用map或者bitset来记录某个值出现的次数
*/
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        int sz = nums.size();

        if (sz <= 1) return false;

        map<int, int> vm;

        for (int i = 0; i < sz; ++i) {
            if (vm.end() != vm.find(nums[i])) {
                return true;
            } else {
                ++vm[nums[i]];
            }
        }

        return false;
    }
};

/*
 * 使用sort排序后，在比对相邻元素
 */
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        for (int i = 0, sz = nums.size(); i < sz - 1; ++i) {
                if (nums[i] == nums[i+1]) return true;
        }

        return false;
    }
};
