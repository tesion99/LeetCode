/*
给定不同面额的硬币 coins 和一个总金额 amount。编写一个函数来计算可以凑成总金额所需的最少的硬币个数。

如果没有任何一种硬币组合能组成总金额，返回 -1。

示例 1:

输入: coins = [1, 2, 5], amount = 11
输出: 3 
解释: 11 = 5 + 5 + 1
示例 2:

输入: coins = [2], amount = 3
输出: -1
说明:
你可以认为每种硬币的数量是无限的。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/coin-change
*/
// 动态规划
// 当前的最小个数DP(i) = 1 + min(DP(i - coins[0]), ..., DP(i - coins[n]))
// 即本次可从coins中任选一个coin，然后求剩余数量的选择方式中的最小的一个
class Solution {
public:
    map<int,int> m;
    int coinChange(vector<int>& coins, int amount) {
        // DP[i] = 1 + min(DP[i - coins[0]..., DP[i - coins[n - 1]])
        sort(coins.begin(), coins.end());
        return backtrace(coins, amount);;
    }

    int backtrace(vector<int>& coins, int rest) {
        if (rest == 0) {
            return 0;
        }
        // 查找已经记录的结果
        if (m.count(rest) > 0) {
            return m[rest];
        }

        int min_cnt = -1;
        for (int i = 0; i < coins.size(); ++i) {
            if (coins[i] > rest) {
                break;
            }
            int cur = backtrace(coins, rest - coins[i]);
            if (cur != -1) {
                min_cnt =  min_cnt == -1 ? cur + 1 : min(min_cnt, cur + 1);
            } 
            m[rest - coins[i]] = cur;
        }
        m[rest] = min_cnt;
        return min_cnt;
    }
};
