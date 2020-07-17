/*
给你一个非递减的 有序 整数数组，已知这个数组中恰好有一个整数，它的出现次数超过数组元素总数的 25%。

请你找到并返回这个整数

 

示例：

输入：arr = [1,2,2,6,6,6,6,7,10]
输出：6
 

提示：

1 <= arr.length <= 10^4
0 <= arr[i] <= 10^5

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/element-appearing-more-than-25-in-sorted-array
*/
class Solution {
public:
    int findSpecialInteger(vector<int>& arr) {
        map<int, int> m;
        for (auto n : arr) {
            ++m[n];
        }

        int res = 0;
        for (auto& p : m) {
            if (p.second * 4 > arr.size()) {
                res = p.first;
                break;
            }
        }
        return res;
    }
};
