/*
给定一个字符串数组 words，找到 length(word[i]) * length(word[j]) 的最大值，并且这两个单词不含有公共字母。你可以认为每个单词只包含小写字母。如果不存在这样的两个单词，返回 0。

示例 1:

输入: ["abcw","baz","foo","bar","xtfn","abcdef"]
输出: 16 
解释: 这两个单词为 "abcw", "xtfn"。
示例 2:

输入: ["a","ab","abc","d","cd","bcd","abcd"]
输出: 4 
解释: 这两个单词为 "ab", "cd"。
示例 3:

输入: ["a","aa","aaa","aaaa"]
输出: 0 
解释: 不存在这样的两个单词。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/maximum-product-of-word-lengths
*/
// 使用bitset<26>记录每个word的组成字符串，使用bitset::to_ulong()进行与操作
// 如果不为0，表明两个字符串有共享字符存在
class Solution {
public:
    int maxProduct(vector<string>& words) {
        vector<bitset<26>> v(words.size(), bitset<26>(0));
        for (int i = 0; i < words.size(); ++i) {
            for (auto ch : words[i]) {
                v[i][ch - 'a'] = 1;
            }
        }
        int ret = 0;
        for (int i = 0; i < v.size(); ++i) {
            if (v[i].count() == 0) {
                continue;
            }
            for (int j = i + 1; j < v.size(); ++j) {
                if (v[j].count() == 0) {
                    continue;
                }
                if ((v[i].to_ulong() & v[j].to_ulong()) == 0) {
                    // 没有共享字符存在
                    // 单个字符串中可能有重复字符存在，需用words[i]的长度
                    int tmp = words[i].size() * words[j].size();
                    ret = max(tmp, ret);
                } 
            }
        }
        return ret;
    }
};
