/*
你正在使用一堆木板建造跳水板。有两种类型的木板，其中长度较短的木板长度为shorter，长度较长的木板长度为longer。
你必须正好使用k块木板。编写一个方法，生成跳水板所有可能的长度。

返回的长度需要从小到大排列。

示例：

输入：
shorter = 1
longer = 2
k = 3
输出： {3,4,5,6}
提示：

0 < shorter <= longer
0 <= k <= 100000

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/diving-board-lcci
*/
// 需注意shorter == longer时，排除相同的元素
class Solution {
public:
    vector<int> divingBoard(int shorter, int longer, int k) {
        if (k == 0) {
            return {};
        }

        set<int> s;
        for (int i = k; i >= 0; --i) {
            s.insert(i * shorter + (k - i) * longer);
        }
        return vector<int>(s.begin(), s.end());
    }
};
// 优化比对
class Solution {
public:
    vector<int> divingBoard(int shorter, int longer, int k) {
        vector<int> res;
        res.reserve(k);
        int pre = 0;
        for (int i = k; i >= 0; --i) {
            int len = i * shorter + (k - i) * longer;
            if (len > pre) {
                res.push_back(len);
                pre = len;
            }
        }
        return res;
    }
};
// 区分两种特殊情况k == 0 shorter == longer即可
class Solution {
public:
    vector<int> divingBoard(int shorter, int longer, int k) {
        if (k == 0) {
            return {};
        }
        if (shorter == longer) {
            return {shorter * k};
        }
        vector<int> res;
        res.reserve(k);
        for (int i = k; i >= 0; --i) {
            res.push_back(i * shorter + (k - i) * longer);
        }
        return res;
    }
};
