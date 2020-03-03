/*
给定N个人的出生年份和死亡年份，第i个人的出生年份为birth[i]，死亡年份为death[i]，实现一个方法以计算生存人数最多的年份。

你可以假设所有人都出生于1900年至2000年（含1900和2000）之间。

如果一个人在某一年的任意时期都处于生存状态，那么他们应该被纳入那一年的统计中。

例如，生于1908年、死于1909年的人应当被列入1908年和1909年的计数。

如果有多个年份生存人数相同且均为最大值，输出其中最小的年份。

示例：

输入：
birth = {1900, 1901, 1950}
death = {1948, 1951, 2000}
输出： 1901
提示：

0 < birth.length == death.length <= 10000
birth[i] <= death[i]

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/living-people-lcci
*/
// 统计年份区间min_year ~ max_year
// 类似计数排序，使用索引代表年份
// 将每个人从birth~death的年份对应的数组索引加一
class Solution {
public:
    int maxAliveYear(vector<int>& birth, vector<int>& death) {
        // 获取出生中的最小年份
        int min_year = *min_element(birth.begin(), birth.end());
        // 获取死亡中的最大年份
        int max_year = *max_element(death.begin(), death.end());
        // 创建一个年份数组，从最小年份~最大年份
        vector<int> human(max_year - min_year + 1, 0);
        for (int i = 0; i < birth.size(); ++i) {
            int start = birth[i], end = death[i];
            while (start <= end) {
                ++human[start - min_year];
                ++start;
            }
        }
        // 寻找人数最多的年份
        int cnt = 0, offset = 0;
        for (int i = 0; i < human.size(); ++i) {
            if (i == 0) {
                cnt = human[i];
                offset = i;
                continue;
            }
            if (human[i] > cnt) {
                cnt = human[i];
                offset = i;
            }
        }
        return min_year + offset;
    }
};
