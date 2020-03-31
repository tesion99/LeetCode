/*
给定一副牌，每张牌上都写着一个整数。

此时，你需要选定一个数字 X，使我们可以将整副牌按下述规则分成 1 组或更多组：

每组都有 X 张牌。
组内所有的牌上都写着相同的整数。
仅当你可选的 X >= 2 时返回 true。

 

示例 1：

输入：[1,2,3,4,4,3,2,1]
输出：true
解释：可行的分组是 [1,1]，[2,2]，[3,3]，[4,4]
示例 2：

输入：[1,1,1,2,2,2,3,3]
输出：false
解释：没有满足要求的分组。
示例 3：

输入：[1]
输出：false
解释：没有满足要求的分组。
示例 4：

输入：[1,1]
输出：true
解释：可行的分组是 [1,1]
示例 5：

输入：[1,1,2,2,2,2]
输出：true
解释：可行的分组是 [1,1]，[2,2]，[2,2]

提示：

1 <= deck.length <= 10000
0 <= deck[i] < 10000

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/x-of-a-kind-in-a-deck-of-cards
*/
// 每张牌个数的因式分解后，是否有相同的部分
class Solution {
public:
    bool hasGroupsSizeX(vector<int>& deck) {
        if (deck.empty()) {
            return true;
        }
        // 索引计数
        int record[10000] = {0};
        for (auto n : deck) {
            ++record[n];
        }
        // 查找个数最少的牌的个数
        int min_cnt = INT_MAX;
        for (int i = 0; i < 10000; ++i) {
            if (record[i] == 0) continue;

            min_cnt = min(min_cnt, record[i]);
        }
        if (min_cnt == 1) {
            return false;
        }
        // 要想每组都能分为X张相同的牌，需要满足所有牌的个数因式分解后包含相同的因子
        set<int> factors;
        int n = min_cnt;
        for (int i = 2; i <= n; ++i) {
            if (n % i == 0) {
                factors.insert(i);
                while (n % i == 0) {
                    n /= i;
                }
            }
        }

        factors.insert(min_cnt);
        for (auto factor : factors) {
            bool flag = true;
            for (int i = 0; i < 10000; ++i) {
                if (record[i] % factor) {
                    flag = false;
                    break;
                }
            }
            if (flag) {
                return true;
            }
        }
        return false;
    }

};
