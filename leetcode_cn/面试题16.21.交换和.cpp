/*
给定两个整数数组，请交换一对数值（每个数组中取一个数值），使得两个数组所有元素的和相等。

返回一个数组，第一个元素是第一个数组中要交换的元素，第二个元素是第二个数组中要交换的元素。

若有多个答案，返回任意一个均可。若无满足条件的数值，返回空数组。

示例:

输入: array1 = [4, 1, 2, 1, 1, 2], array2 = [3, 6, 3, 3]
输出: [1, 3]
示例:

输入: array1 = [1, 2, 3], array2 = [4, 5, 6]
输出: []
提示：

1 <= array1.length, array2.length <= 100000

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/sum-swap-lcci
*/
// 先分别求A, B之后，在分别遍历A,B每个元素，检测交换后是否相等，
// 时间复杂度O(N^2)
// WARN:执行超时
class Solution {
public:
    vector<int> findSwapValues(vector<int>& array1, vector<int>& array2) {
        int sum1 = 0, sum2 = 0;
        for (auto n : array1) {
            sum1 += n;
        }
        for (auto n : array2) {
            sum2 += n;
        }
        vector<int> res;
        for (int i = 0; i < array1.size(); ++i) {
            for (int j = 0; j < array2.size(); ++j) {
                if (sum1 - array1[i] + array2[j] == sum2 - array2[j] + array1[i]) {
                    res.insert(res.begin(), {array1[i], array2[j]});
                    return res;
                }
            }
        }
        return res;
    }
};

// 排序，根据比较结果调整 A B索引
// 类似这边比较逻辑
class Solution {
public:
    vector<int> findSwapValues(vector<int>& array1, vector<int>& array2) {
        int sum1 = 0, sum2 = 0;
        for (auto n : array1) {
            sum1 += n;
        }
        for (auto n : array2) {
            sum2 += n;
        }
        vector<int> res;
        sort(array1.begin(), array1.end());
        sort(array2.begin(), array2.end());
        int i = 0, j = 0;
        while (i < array1.size() && j < array2.size()) {
            // sum1 - array1[i] + array2[j] == sum2 - array2[j] + array1[i]
            int val1 = sum1 + 2 * array2[j];
            int val2 = sum2 + 2 * array1[i];
            if (val1 > val2) {
                // 说明交换的元素array1[i]小了，导致val2偏小，故递增i
                ++i;
            } else if (val1 < val2) {
                // 交换的元素array2[j]小了，导致val1偏小，故递增j
                ++j;
            } else {
                res.insert(res.begin(), {array1[i], array2[j]});
                return res;
            }
        }
        return res;
    }
};
