/*
给你两个数组，arr1 和 arr2，

arr2 中的元素各不相同
arr2 中的每个元素都出现在 arr1 中
对 arr1 中的元素进行排序，使 arr1 中项的相对顺序和 arr2 中的相对顺序相同。未在 arr2 中出现过的元素需要按照升序放在 arr1 的末尾。

 

示例：

输入：arr1 = [2,3,1,3,2,4,6,7,9,2,19], arr2 = [2,1,4,3,9,6]
输出：[2,2,2,1,4,3,3,9,6,7,19]
 

提示：

arr1.length, arr2.length <= 1000
0 <= arr1[i], arr2[i] <= 1000
arr2 中的元素 arr2[i] 各不相同
arr2 中的每个元素 arr2[i] 都出现在 arr1 中

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/relative-sort-array
*/
// 计数排序，索引计数
class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        if (arr2.empty()) {
            sort(arr1.begin(), arr1.end());
            return arr1;
        }

        int arr[1001] = {0};
        for (auto n : arr1) {
            ++arr[n];
        }
        vector<int> res;
        res.reserve(arr1.size());
        for (auto n : arr2) {
            res.insert(res.end(), arr[n], n);
            arr[n] = 0;
        }
        // 处理剩余未出现在arr2中的数
        for (int i = 0; i <= 1000; ++i) {
            if (arr[i] == 0) {
                continue;
            }
            res.insert(res.end(), arr[i], i);
        }
        return res;
    }
};
