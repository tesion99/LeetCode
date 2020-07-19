/*
给定一个单词列表，我们将这个列表编码成一个索引字符串 S 与一个索引列表 A。

例如，如果这个列表是 ["time", "me", "bell"]，我们就可以将其表示为 S = "time#bell#" 和 indexes = [0, 2, 5]。

对于每一个索引，我们可以通过从字符串 S 中索引的位置开始读取字符串，直到 "#" 结束，来恢复我们之前的单词列表。

那么成功对给定单词列表进行编码的最小字符串长度是多少呢？

 

示例：

输入: words = ["time", "me", "bell"]
输出: 10
说明: S = "time#bell#" ， indexes = [0, 2, 5] 。
 

提示：

1 <= words.length <= 2000
1 <= words[i].length <= 7
每个单词都是小写字母 。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/short-encoding-of-words
*/
// 只有当单词a的长度 <= 单词b的长度时，b才有可能包含a
// 故对单词按照长度排序，再每个单词在遍历比自身长的单词即可
class Solution {
public:
    int minimumLengthEncoding(vector<string>& words) {
        sort(words.begin(), words.end(), [](string& a, string& b) {
            if (a.size() == b.size()) {
                return a > b;
            } else {
                return a.size() > b.size();
            }
        });
        int len = 0, cnt = 0;
        for (int i = 0; i < words.size(); ++i) {
            int sz = words[i].size();
            bool flag = false;
            for (int j = 0; j < i; ++j) {
                auto pos = words[j].find(words[i], words[j].size() - sz);
                if (pos != string::npos) {
                    flag = true;
                    break;
                }
            }
            if (!flag) {
                ++cnt;
                len += words[i].size();
            }
        }
        return len + cnt;
    }
};
