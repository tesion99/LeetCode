/*
给定一个循环数组（最后一个元素的下一个元素是数组的第一个元素），输出每个元素的下一个更大元素。数字 x 的下一个更大的元素是按数组遍历顺序，这个数字之后的第一个比它更大的数，这意味着你应该循环地搜索它的下一个更大的数。如果不存在，则输出 -1。

示例 1:

输入: [1,2,1]
输出: [2,-1,2]
解释: 第一个 1 的下一个更大的数是 2；
数字 2 找不到下一个更大的数； 
第二个 1 的下一个最大的数需要循环搜索，结果也是 2。
注意: 输入数组的长度不会超过 10000。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/next-greater-element-ii
-----------------------------
Note: 参考I，但因为有重复元素，所以考虑使用索引来区分，但需记录已匹配的元素索引，防止重复入栈
*/
class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        if (nums.empty()) {
            return vector<int>();
        }
        pair<int, int> p;
        int sz = nums.size();
        map<int, int> m;
        // 根据题目判断，理论上每个元素都能找到下一个更大元素，除了最大的元素
        int max_val = *max_element(nums.begin(), nums.end());
        stack<pair<int, int>> st;
        vector<int> res(nums.size(), -1);
        int i = 0, target = sz; // target指定res中未匹配的个数
        while (target > 0) {
            if (i == sz) i = 0;

            while (!st.empty() && st.top().second < nums[i]) {
                m[st.top().first] = nums[i];
                st.pop();
                --target;
            }

            // 避免重复插入索引
            if (m.find(i) == m.end()) {
                if (nums[i] != max_val) {
                    p.first = i;
                    p.second = nums[i];
                    st.push(p);
                } else {
                    --target;
                    m[i] = -1;
                }
            }
            ++i;
        }

        for (auto it = m.begin(); it != m.end(); ++it) {
            res[it->first] = it->second;
        }
        return res;
    }
};

// 改进，stack中只存储索引
class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        if (nums.empty()) {
            return vector<int>();
        }
        
        int sz = nums.size();
        map<int, int> m;
        // 根据题目判断，理论上每个元素都能找到下一个更大元素，除了最大的元素
        int max_val = *max_element(nums.begin(), nums.end());
        stack<int> st;
        vector<int> res(nums.size(), -1);
        int i = 0, target = sz; // target指定res中未匹配的个数
        while (target > 0) {
            if (i == sz) i = 0;

            while (!st.empty() && nums[st.top()] < nums[i]) {
                m[st.top()] = nums[i];
                st.pop();
                --target;
            }
            // 避免重复插入索引
            if (m.find(i) == m.end()) {
                if (nums[i] != max_val) {
                    st.push(i);
                } else {
                    --target;
                    m[i] = -1;
                }
            }
            ++i;
        }

        for (auto it = m.begin(); it != m.end(); ++it) {
            res[it->first] = it->second;
        }
        return res;
    }
};
