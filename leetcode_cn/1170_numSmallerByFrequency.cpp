/*
我们来定义一个函数 f(s)，其中传入参数 s 是一个非空字符串；

该函数的功能是统计 s  中（按字典序比较）最小字母的出现频次。

例如，若 s = "dcce"，那么 f(s) = 2，因为最小的字母是 "c"，它出现了 2 次。

现在，给你两个字符串数组待查表 queries 和词汇表 words，请你返回一个整数数组 answer 作为答案，

其中每个 answer[i] 是满足 f(queries[i]) < f(W) 的词的数目，W 是词汇表 words 中的词。
 

示例 1：

输入：queries = ["cbd"], words = ["zaaaz"]
输出：[1]
解释：查询 f("cbd") = 1，而 f("zaaaz") = 3 所以 f("cbd") < f("zaaaz")。
示例 2：

输入：queries = ["bbb","cc"], words = ["a","aa","aaa","aaaa"]
输出：[1,2]
解释：第一个查询 f("bbb") < f("aaaa")，第二个查询 f("aaa") 和 f("aaaa") 都 > f("cc")。
 

提示：

1 <= queries.length <= 2000
1 <= words.length <= 2000
1 <= queries[i].length, words[i].length <= 10
queries[i][j], words[i][j] 都是小写英文字母


来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/compare-strings-by-frequency-of-the-smallest-character
*/
// 利用字符有效范围，索引计数
class Solution {
public:
    vector<int> numSmallerByFrequency(vector<string>& queries, vector<string>& words) {
        int wcnt[11] = {0};
        for (auto& w : words) {
            int ret = f(w);
            ++wcnt[ret];
        }
        int sum = 0;
        for (int i = 10; i >= 0; --i) {
            int cur = wcnt[i];
            wcnt[i] = sum;
            sum += cur;
        }
        vector<int> res;
        for (auto& q : queries) {
            int cnt = f(q);
            res.push_back(wcnt[cnt]);
        }
        return res;
    }
    int f(const string& s) {
        if (s.empty()) {
            return 0;
        }

        int cnt[26] = {0};
        char min_char = s[0];
        ++cnt[min_char - 'a'];
        for (int i = 1, sz = s.size(); i < sz; ++i) {
            if (s[i] > min_char) {
                continue;
            }
            if (s[i] < min_char) {
                min_char = s[i];
            }
            ++cnt[s[i] - 'a'];
        }
        return cnt[min_char - 'a'];
    }
};
