/*
给定一个字符串数组 arr，字符串 s 是将 arr 某一子序列字符串连接所得的字符串，如果 s 中的每一个字符都只出现过一次，那么它就是一个可行解。

请返回所有可行解 s 中最长长度。

 

示例 1：

输入：arr = ["un","iq","ue"]
输出：4
解释：所有可能的串联组合是 "","un","iq","ue","uniq" 和 "ique"，最大长度为 4。
示例 2：

输入：arr = ["cha","r","act","ers"]
输出：6
解释：可能的解答有 "chaers" 和 "acters"。
示例 3：

输入：arr = ["abcdefghijklmnopqrstuvwxyz"]
输出：26

提示：

1 <= arr.length <= 16
1 <= arr[i].length <= 26
arr[i] 中只含有小写英文字母

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/maximum-length-of-a-concatenated-string-with-unique-characters
*/
// 使用bitset记录每个string出现过的字符对应的bit位
class Solution {
public:
    int maxLength(vector<string>& arr) {
        int sz = arr.size();
        vector<unsigned long> v(sz);
        bitset<26> bs(0);
        for (int i = 0; i < sz; ++i) {
            bs.reset();
            for (auto c : arr[i]) {
                // 该字符串中有重复字符
                if (bs[c - 'a'] == 1) {
                    bs.reset();
                    break;
                }
                bs[c - 'a'] = 1;
            }
            v[i] = bs.to_ulong();
        }
        if (sz == 1) {
            bitset<26> b(v[0]);
            return b.count();
        }

        unsigned long res = 0;
        backtrace(v, arr, 0, sz - 1, 0, res);
        return res;
    }

    void backtrace(vector<unsigned long>& v, vector<string>& arr, int start, int end, unsigned long bits, unsigned long& res) {
        if (start > end) {
            return;
        }
        if (start != 0 && bits == 0) {
            return;
        }
        unsigned long tmp = 0;
        for (int i = start; i <= end; ++i) {
            tmp = bits & v[i];
            if (tmp == 0) {
                    bitset<26> bs(bits | v[i]);
                    res = max(bs.count(), res);
                    backtrace(v, arr, i + 1, end, bs.to_ulong(), res);
            }
        }
    }
};
