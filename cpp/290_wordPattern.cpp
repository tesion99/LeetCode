/*
给定一种规律 pattern 和一个字符串 str ，判断 str 是否遵循相同的规律。

这里的 遵循 指完全匹配，例如， pattern 里的每个字母和字符串 str 中的每个非空单词之间存在着双向连接的对应规律。

示例1:

输入: pattern = "abba", str = "dog cat cat dog"
输出: true
示例 2:

输入:pattern = "abba", str = "dog cat cat fish"
输出: false
示例 3:

输入: pattern = "aaaa", str = "dog cat cat dog"
输出: false
示例 4:

输入: pattern = "abba", str = "dog dog dog dog"
输出: false
说明:
你可以假设 pattern 只包含小写字母， str 包含了由单个空格分隔的小写字母。   

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/word-pattern
*/
// 两个映射表，分别做string->char char->string
// 1. 根据空格或到字符末尾，获取当前的word
// 2. 判断当前word对应的char，是否匹配hash表中对应的char
// 3. 如果当前word未加入过映射表，则分别加入2个hash表中
// 4. 根据下一个pattern字符，查找需要预测匹配的下一个next_word，
// 如果后续word与next_word相同，则符合匹配规则，重复以上操作；
// 否则模式不匹配，直接退出
class Solution {
public:
    bool wordPattern(string pattern, string str) {
        if (pattern.empty() && !str.empty()) {
            return false;
        }

        map<char, string> cm;
        map<string, char> wm;
        int wc = 0;
        int sz = str.size(), psz = pattern.size();
        int start = 0;
        string next_word;
        for (int i = 0; i < sz; ++i) {
            if (psz <= wc) {
                return false;
            }
            if (str[i] == ' ' || i == sz - 1) {
                string word = (i == sz - 1) ? str.substr(start, i - start + 1) : str.substr(start, i - start);
                start = i + 1;
                if (!next_word.empty()) {
                    if (word != next_word) {
                        return false;
                    }
                }else {
                    auto iter = wm.find(word);
                    char c = pattern[wc];
                    if (iter != wm.end()) {
                        if (iter->second != c) {
                            return false;
                        }
                    } else {
                        wm[word] = c;
                        cm[c] = word;
                    }
                }
                if (wc + 1 < psz) {
                    char next_char = pattern[wc + 1];
                    auto it = cm.find(next_char);
                    next_word = (it != cm.end()) ? it->second : "";
                }
                ++wc;
            }
        }

        if (wc != psz) {
            return false;
        }

        return true;
    }
};
