/*
给定一个整数数组，编写一个函数，找出索引m和n，只要将索引区间[m,n]的元素排好序，整个数组就是有序的。
注意：n-m尽量最小，也就是说，找出符合条件的最短序列。函数返回值为[m,n]，若不存在这样的m和n（例如整个数组是有序的），请返回[-1,-1]。

示例：

输入： [1,2,4,7,10,11,7,12,6,7,16,18,19]
输出： [3,9]
提示：

0 <= len(array) <= 1000000

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/sub-sort-lcci
*/
// 排序数组，首尾对比，找出乱序区间
class Solution {
public:
    vector<int> subSort(vector<int>& array) {
        vector<int> tmp(array);
        sort(tmp.begin(), tmp.end());
        int i = 0, sz = tmp.size();
        for (i = 0; i < sz; ++i) {
            if (tmp[i] != array[i]) break;
        }

        if (i == sz) {
            return vector<int>(2, -1);
        }

        int j = tmp.size() - 1;
        for (; j >= 0; --j) {
            if (tmp[j] != array[j]) break;
        }
        return {i, j};
    }
};
