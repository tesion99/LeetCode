/*
输入整数数组 arr ，找出其中最小的 k 个数。例如，输入4、5、1、6、2、7、3、8这8个数字，则最小的4个数字是1、2、3、4。

 

示例 1：

输入：arr = [3,2,1], k = 2
输出：[1,2] 或者 [2,1]
示例 2：

输入：arr = [0,1,2,1], k = 1
输出：[0]
 

限制：

0 <= k <= arr.length <= 1000
0 <= arr[i] <= 1000

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/zui-xiao-de-kge-shu-lcof
*/
class Solution {
public:
    vector<int> getLeastNumbers(vector<int>& arr, int k) {
        if (k == 0 || arr.empty()) {
            return vector<int>();
        }

        if (k == arr.size()) {
            return arr;
        }

        vector<int> res;
        int nums[10001] = {0};

        res.reserve(k);
        for (auto n : arr) {
            ++nums[n];
        }

        for (int i = 0; i <= 10000 && k > 0; ++i) {
            if (nums[i] == 0) continue;

            int rest = k >= nums[i] ? nums[i] : k;
            res.insert(res.end(), rest, i);
            k -= rest;
        }
        return res;
    }
};
