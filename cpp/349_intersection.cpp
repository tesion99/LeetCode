/*
给定两个数组，编写一个函数来计算它们的交集。

示例 1:

输入: nums1 = [1,2,2,1], nums2 = [2,2]
输出: [2]
示例 2:

输入: nums1 = [4,9,5], nums2 = [9,4,9,8,4]
输出: [9,4]
说明:

输出结果中的每个元素一定是唯一的。
我们可以不考虑输出结果的顺序。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/intersection-of-two-arrays
*/
// 先排序，后查找到交集开始处，进行处理
class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        if (nums1.empty() || nums2.empty()) {
            return vector<int>();
        }
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());

        vector<int> res;
        if (nums1.back() < nums2.front() 
            || nums1.front() > nums2.back()) {
            return res;
        }

        auto it1 = nums1.begin();
        auto it2 = nums2.begin();
        while (it1 != nums1.end() && it2 != nums2.end()) {
            if (*it1 > *it2) {
                ++it2;
                continue;
            } 
            if (*it1 < *it2) {
                ++it1;
                continue;
            }

            if (res.empty() || res.back() != *it1) {
                res.push_back(*it1);
            }
            ++it1;
            ++it2;
        }
        return res;
    }
};
