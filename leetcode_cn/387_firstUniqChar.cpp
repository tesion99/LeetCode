/*
给定一个字符串，找到它的第一个不重复的字符，并返回它的索引。如果不存在，则返回 -1。

案例:

s = "leetcode"
返回 0.

s = "loveleetcode",
返回 2.
 

注意事项：您可以假定该字符串只包含小写字母。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/first-unique-character-in-a-string
*/
// hash，记录字符出现个数与首次出现的索引
class Solution {
public:
    int firstUniqChar(string s) {
        map<char, pair<int, int>> cm;
        for (int i = 0; i < s.size(); ++i) {
            auto it = cm.find(s[i]);
            if (it != cm.end()) {
                ++it->second.second;
            } else {
                cm[s[i]] = make_pair(i, 1);
            }
        }

        int idx = -1;
        for (auto& it : cm) {
            if (it.second.second > 1) {
                continue;
            }
            if (idx == -1) {
                idx = it.second.first;
            } else {
                idx = min(idx, it.second.first);
            }
        }
        return idx;
    }
};
