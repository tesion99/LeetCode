/*
给一非空的单词列表，返回前 k 个出现次数最多的单词。

返回的答案应该按单词出现频率由高到低排序。如果不同的单词有相同出现频率，按字母顺序排序。

示例 1：

输入: ["i", "love", "leetcode", "i", "love", "coding"], k = 2
输出: ["i", "love"]
解析: "i" 和 "love" 为出现次数最多的两个单词，均为2次。
    注意，按字母顺序 "i" 在 "love" 之前。
 

示例 2：

输入: ["the", "day", "is", "sunny", "the", "the", "the", "sunny", "is", "is"], k = 4
输出: ["the", "is", "sunny", "day"]
解析: "the", "is", "sunny" 和 "day" 是出现次数最多的四个单词，
    出现次数依次为 4, 3, 2 和 1 次。
 

注意：

假定 k 总为有效值， 1 ≤ k ≤ 集合元素数。
输入的单词均由小写字母组成。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/top-k-frequent-words
*/
class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        map<string, int> m;
        for (auto& w : words) {
            ++m[w];
        }
        map<int, vector<string>> fm;
        for (auto it = m.rbegin(); it != m.rend(); ++it) {
            fm[it->second].push_back(it->first);
        }

        vector<string> res;
        auto it = fm.rbegin();
        while (k != 0 && it != fm.rend()) {
            if (!it->second.empty()) {
                res.push_back(it->second.back());
                it->second.pop_back();
                --k;
            } else {
                ++it;
            }
        }
        return res;
    }
};
