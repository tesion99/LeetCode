/*
给定一个字符串 s 和一个非空字符串 p，找到 s 中所有是 p 的字母异位词的子串，返回这些子串的起始索引。

字符串只包含小写英文字母，并且字符串 s 和 p 的长度都不超过 20100。

说明：

字母异位词指字母相同，但排列不同的字符串。
不考虑答案输出的顺序。
示例 1:

输入:
s: "cbaebabacd" p: "abc"

输出:
[0, 6]

解释:
起始索引等于 0 的子串是 "cba", 它是 "abc" 的字母异位词。
起始索引等于 6 的子串是 "bac", 它是 "abc" 的字母异位词。
 示例 2:

输入:
s: "abab" p: "ab"

输出:
[0, 1, 2]

解释:
起始索引等于 0 的子串是 "ab", 它是 "ab" 的字母异位词。
起始索引等于 1 的子串是 "ba", 它是 "ab" 的字母异位词。
起始索引等于 2 的子串是 "ab", 它是 "ab" 的字母异位词。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/find-all-anagrams-in-a-string
*/
// 对字符索引计数，从s的每个字符作为头，向后记录，比较索引数据与p的索引计数是否相同
class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        if (p.size() > s.size()) {
            return {};
        }
        
        int sz = s.size(), psz = p.size();
        int pr[26] = {0}, sr[26] = {0};
        vector<int> res;

        for (auto ch : p) {
            ++pr[ch - 'a'];
        }
        for (int i = 0; i <= sz - psz; ++i) {
            memset(sr, 0, sizeof(sr));
            for (int j = i; j < i + psz; ++j) {
                ++sr[s[j] - 'a'];
            }
            int k = 0;
            while (k < 26) {
                if (sr[k] != pr[k]) break;
                ++k;
            }
            if (k >= 26) {
                res.push_back(i);
            }
        }
        return res;
    }
};
