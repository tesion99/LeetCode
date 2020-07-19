/*
给定一个单词，你需要判断单词的大写使用是否正确。

我们定义，在以下情况时，单词的大写用法是正确的：

全部字母都是大写，比如"USA"。
单词中所有字母都不是大写，比如"leetcode"。
如果单词不只含有一个字母，只有首字母大写， 比如 "Google"。
否则，我们定义这个单词没有正确使用大写字母。

示例 1:

输入: "USA"
输出: True
示例 2:

输入: "FlaG"
输出: False
注意: 输入是由大写和小写拉丁字母组成的非空单词。



来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/detect-capital
*/
// 统计大写字母的个数以及第一个大写字母出现的索引
class Solution {
public:
    bool detectCapitalUse(string word) {
        int uppers = 0, idx = -1;
        for (int i = 0; i < word.size(); ++i) {
            if (word[i] >= 'A' && word[i] <= 'Z') {
                if (uppers == 0) {
                    idx = i;
                }
                ++uppers;
            }
        }

        if (uppers == 0 || uppers == word.size() || uppers == 1 && idx == 0) {
            return true;
        }
        return false;
    }
};
