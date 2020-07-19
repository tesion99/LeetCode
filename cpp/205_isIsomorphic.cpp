/*
给定两个字符串 s 和 t，判断它们是否是同构的。

如果 s 中的字符可以被替换得到 t ，那么这两个字符串是同构的。

所有出现的字符都必须用另一个字符替换，同时保留字符的顺序。两个字符不能映射到同一个字符上，但字符可以映射自己本身。

示例 1:

输入: s = "egg", t = "add"
输出: true
示例 2:

输入: s = "foo", t = "bar"
输出: false
示例 3:

输入: s = "paper", t = "title"
输出: true
说明:
你可以假设 s 和 t 具有相同的长度。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/isomorphic-strings
*/
// 双向唯一映射
class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if (s.size() != t.size()) {
            return false;
        }
        map<char, char> smap, tmap;
        for (int i = 0; i < s.size(); ++i) {
            auto it1 = smap.find(s[i]);
            auto it2 = tmap.find(t[i]);
            if (it1 == smap.end() && it2 != tmap.end() || 
                it1 != smap.end() && it2 == tmap.end()) {
                return false;
            }
            if (it1 != smap.end() && it2 != tmap.end()) {
                if (it1->second != t[i] || it2->second != s[i]) {
                    return false;
                }
            }
            smap[s[i]] = t[i];
            tmap[t[i]] = s[i];
        }
        return true;
    }
};
