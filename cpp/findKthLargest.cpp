/*
在未排序的数组中找到第 k 个最大的元素。请注意，你需要找的是数组排序后的第 k 个最大的元素，而不是第 k 个不同的元素。

示例 1:

输入: [3,2,1,5,6,4] 和 k = 2
输出: 5
示例 2:

输入: [3,2,3,1,2,4,5,5,6] 和 k = 4
输出: 4
说明:

你可以假设 k 总是有效的，且 1 ≤ k ≤ 数组的长度。
--------------------------------
Note:
    使用map来对每个值出现的次数进行统计，在逆序查找
*/
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        map<int, int> vm;

        for (int i = 0; i < nums.size(); ++i) {
            ++vm[nums[i]];
        }

        auto iter = vm.rbegin();
        int countor = 0;
        while (iter != vm.rend()) {
            if (countor + iter->second >= k) {
                break;
            }

            countor += iter->second;
            ++iter;
        }
        return iter->first;
    }
};
