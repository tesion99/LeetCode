/*
请从字符串中找出一个最长的不包含重复字符的子字符串，计算该最长子字符串的长度。

 

示例 1:

输入: "abcabcbb"
输出: 3 
解释: 因为无重复字符的最长子串是 "abc"，所以其长度为 3。
示例 2:

输入: "bbbbb"
输出: 1
解释: 因为无重复字符的最长子串是 "b"，所以其长度为 1。
示例 3:

输入: "pwwkew"
输出: 3
解释: 因为无重复字符的最长子串是 "wke"，所以其长度为 3。
     请注意，你的答案必须是 子串 的长度，"pwke" 是一个子序列，不是子串。
 

提示：

s.length <= 40000
注意：本题与主站 3 题相同：https://leetcode-cn.com/problems/longest-substring-without-repeating-characters/

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/zui-chang-bu-han-zhong-fu-zi-fu-de-zi-zi-fu-chuan-lcof
*/
// map记录下重复字符的下标，确定新串的新起始下标
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if (s.size() <= 1) {
            return s.size();
        }

        map<char, int> m;
        int start = 0, end = 0, len = 0;

        m[s[0]] = 0;
        for (int i = 1; i <= s.size(); ++i) {
            if (i == s.size()) {
                len = max(len, end - start + 1);
                break;
            }
        
            auto it = m.find(s[i]);
            if (it != m.end()) {
                len = max(len, end - start + 1);
                start = it->second + 1;
                auto iter = m.begin();
                while (iter != m.end()) {
                    if (iter->second < start) {
                        iter = m.erase(iter);
                    } else {
                        ++iter;
                    }
                }
            }
            end = i;
            m[s[i]] = i;
        }
        
        return len;
    }
};
