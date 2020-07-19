/*
给你个整数数组 arr，其中每个元素都 不相同。

请你找到所有具有最小绝对差的元素对，并且按升序的顺序返回。

 

示例 1：

输入：arr = [4,2,1,3]
输出：[[1,2],[2,3],[3,4]]
示例 2：

输入：arr = [1,3,6,10,15]
输出：[[1,3]]
示例 3：

输入：arr = [3,8,-10,23,19,-4,-14,27]
输出：[[-14,-10],[19,23],[23,27]]
 

提示：

2 <= arr.length <= 10^5
-10^6 <= arr[i] <= 10^6

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/minimum-absolute-difference
*/
// 排序 + 2次扫描
// 第一次扫描，确定最小距离
// 第二次扫描，用于保存满足条件的结果
class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        if (arr.size() <= 1) {
            return vector<vector<int>>();
        }
        vector<vector<int>> res;
        if (arr.size() == 2) {
            res.push_back(arr);
            return res;
        }

        sort(arr.begin(), arr.end());
        int min_diff = INT_MAX;
        for (int i = 0; i < arr.size(); ++i) {
            if (i > 0 && min_diff > arr[i] - arr[i-1]) {
                min_diff = arr[i] - arr[i-1];
            }
        }
        for (int i = 0; i < arr.size(); ++i) {
            if (i > 0 && min_diff == arr[i] - arr[i-1]) {
                res.push_back(vector<int>{arr[i-1], arr[i]});
            }
        }

        return res;
    }
};
