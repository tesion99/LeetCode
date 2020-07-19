/*
设计一个算法，找出数组中最小的k个数，并从小到大排序后输出。

示例：

输入： [1,3,5,7,2,4,6,8]
输出： [1,2,3,4]
提示：

0 <= len(array) <= 100000
0 <= k <= min(100000, len(array))


来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/smallest-k-lcci
*/
// 使用hash表做最小K个数排序，计数
// 当新的数小于hash中的最大数时，新数计数加一，最大数个数减一，
// 当最大数个数为0时，从hash中删除该最大数
class Solution {
public:
    vector<int> smallestK(vector<int>& arr, int k) {
        if (k == 0) {
            return vector<int>();
        }

        if (k == arr.size()) {
            sort(arr.begin(), arr.end());
            return arr;
        }

        map<int, int> m;
        int cnt = 0;
        for (auto n : arr) {
            if (cnt < k) {
                ++m[n];
                ++cnt;
                continue;
            }
            auto last = m.rbegin();
            if (n < last->first) {
                ++m[n];
                --last->second;
                if (last->second <= 0) {
                    m.erase(last->first);
                }
            }
        }
        
        vector<int> res;
        for (auto& p : m) {
            res.insert(res.end(), p.second, p.first);
        }
        return res;
    }
};
