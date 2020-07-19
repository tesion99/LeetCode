/*
给定两个没有重复元素的数组 nums1 和 nums2 ，其中nums1 是 nums2 的子集。找到 nums1 中每个元素在 nums2 中的下一个比其大的值。

nums1 中数字 x 的下一个更大元素是指 x 在 nums2 中对应位置的右边的第一个比 x 大的元素。如果不存在，对应位置输出-1。

示例 1:

输入: nums1 = [4,1,2], nums2 = [1,3,4,2].
输出: [-1,3,-1]
解释:
    对于num1中的数字4，你无法在第二个数组中找到下一个更大的数字，因此输出 -1。
    对于num1中的数字1，第二个数组中数字1右边的下一个较大数字是 3。
    对于num1中的数字2，第二个数组中没有下一个更大的数字，因此输出 -1。
示例 2:

输入: nums1 = [2,4], nums2 = [1,2,3,4].
输出: [3,-1]
解释:
    对于num1中的数字2，第二个数组中的下一个较大数字是3。
    对于num1中的数字4，第二个数组中没有下一个更大的数字，因此输出 -1。
注意:

nums1和nums2中所有元素是唯一的。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/next-greater-element-i
-----------------------------
Note: 使用栈，结合hashmap记录中间筛选出的结果，遍历nums2
*/
class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        if (nums2.empty() || nums1.empty()) {
            return vector<int>();
        }

        int sz = nums2.size();
        map<int, int> m;
        stack<int> st;
        for (int i = 0; i < sz; ++i) {
            if (st.empty()) {
                st.push(nums2[i]);
            } else {
                while (!st.empty() && nums2[i] > st.top()) {
                    m[st.top()] = nums2[i];
                    st.pop();
                }
                st.push(nums2[i]);
            }
        }

        vector<int> res;
        int val = 0;
        for (int i = 0, sz = nums1.size(); i < sz; ++i) {
            auto it = m.find(nums1[i]);
            val = (it == m.end()) ? -1 : it->second;
            res.push_back(val);
        }

        return res;
    }
};

// 改进，节省hashmap大小空间
class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        if (nums2.empty() || nums1.empty()) {
            return vector<int>();
        }

        // 因元素唯一，故以下操作合法
        map<int, int> m;
        for (int i = 0, sz = nums1.size(); i < sz; ++i) {
            m[nums1[i]] = -1;
        }

        stack<int> st;
        for (int i = 0, sz = nums2.size(); i < sz; ++i) {
            while (!st.empty() && nums2[i] > st.top()) {
                // 只检查目标数据
                if (m.find(st.top()) != m.end()) {
                    m[st.top()] = nums2[i];
                }
                st.pop();
            }
            st.push(nums2[i]);
        }

        vector<int> res;
        res.reserve(nums1.size());
        for (int i = 0, sz = nums1.size(); i < sz; ++i) {
            res.push_back(m[nums1[i]]);
        }

        return res;
    }
};
