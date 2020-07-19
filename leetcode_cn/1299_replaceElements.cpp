/*
给你一个数组 arr ，请你将每个元素用它右边最大的元素替换，如果是最后一个元素，用 -1 替换。

完成所有替换操作后，请你返回这个数组。

 

示例：

输入：arr = [17,18,5,4,6,1]
输出：[18,6,6,6,1,-1]
 

提示：

1 <= arr.length <= 10^4
1 <= arr[i] <= 10^5

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/replace-elements-with-greatest-element-on-right-side
*/
// 反向扫描，记录最大值
class Solution {
public:
    vector<int> replaceElements(vector<int>& arr) {
        if (arr.empty()) {
            return arr;
        }
        int rmax = -1, sz = arr.size();
        for (int i = sz - 1; i >= 0; --i) {
            int cur = arr[i];
            arr[i] = rmax;
            rmax = (i == sz - 1) ? cur : max(rmax, cur);
        }
        return arr;
    }
};
