/*
在歌曲列表中，第 i 首歌曲的持续时间为 time[i] 秒。

返回其总持续时间（以秒为单位）可被 60 整除的歌曲对的数量。形式上，我们希望索引的数字 i 和 j 满足  i < j 且有 (time[i] + time[j]) % 60 == 0。

 

示例 1：

输入：[30,20,150,100,40]
输出：3
解释：这三对的总持续时间可被 60 整数：
(time[0] = 30, time[2] = 150): 总持续时间 180
(time[1] = 20, time[3] = 100): 总持续时间 120
(time[1] = 20, time[4] = 40): 总持续时间 60
示例 2：

输入：[60,60,60]
输出：3
解释：所有三对的总持续时间都是 120，可以被 60 整数。
 

提示：

1 <= time.length <= 60000
1 <= time[i] <= 500

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/pairs-of-songs-with-total-durations-divisible-by-60
*/
// 双层for循环的暴力破解法会导致超时，故考虑根据当前数，查找目标target的方式，需要使用到hash map
class Solution {
public:
    int numPairsDivisibleBy60(vector<int>& time) {
        if (time.empty()) {
            return 0;
        }

        map<int, vector<int>> m;
        for (int i = 0; i < time.size(); ++i) {
            m[time[i]].push_back(i);
        }

        int res = 0, max_val = m.rbegin()->first;
        for (auto it = m.begin(); it != m.end(); ++it) {
            int mul = it->first / 60;
            int mod = it->first % 60;
            int target = mul * 60 - mod;
            // 找到一个不小于当前数的，且能满足条件的target
            while (target < it->first) {
                target += 60;
            }
            
            int nums = it->second.size();
            if (target == it->first) {
                for (int i = nums - 1; i >= 1; --i) {
                    res += i;
                }
                target += 60;
            }

            while (target <= max_val) {
                auto iter = m.find(target);
                if (iter != m.end()) {
                    res += (iter->second.size() * nums);
                }
                target += 60;
            }
        }
        
        return res;
    }
};
