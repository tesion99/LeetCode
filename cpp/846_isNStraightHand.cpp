/*
爱丽丝有一手（hand）由整数数组给定的牌。 

现在她想把牌重新排列成组，使得每个组的大小都是 W，且由 W 张连续的牌组成。

如果她可以完成分组就返回 true，否则返回 false。

 

示例 1：

输入：hand = [1,2,3,6,2,3,4,7,8], W = 3
输出：true
解释：爱丽丝的手牌可以被重新排列为 [1,2,3]，[2,3,4]，[6,7,8]。
示例 2：

输入：hand = [1,2,3,4,5], W = 4
输出：false
解释：爱丽丝的手牌无法被重新排列成几个大小为 4 的组。
 

提示：

1 <= hand.length <= 10000
0 <= hand[i] <= 10^9
1 <= W <= hand.length


来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/hand-of-straights
*/
class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int W) {
        if (W == 1) return true;

        if (hand.size() % W) return false;

        map<int, int> m;
        for (auto& n : hand) {
            ++m[n];
        }
        int i = 0, val = 0;
        while (i < W && !m.empty()) {
            if (i == 0) {
                val = m.begin()->first;
            } else {
                ++val;
            }
            auto it = m.find(val);
            if (it == m.end()) {
                return false;
            }
            --it->second;
            if (it->second == 0) {
                m.erase(it);
            }

            ++i;
            if (i == W) {
                i = 0;
            }
        }
        return m.empty() ? true : false;
    }
};
