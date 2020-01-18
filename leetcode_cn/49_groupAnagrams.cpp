/*
给定一个字符串数组，将字母异位词组合在一起。字母异位词指字母相同，但排列不同的字符串。

示例:

输入: ["eat", "tea", "tan", "ate", "nat", "bat"],
输出:
[
  ["ate","eat","tea"],
  ["nat","tan"],
  ["bat"]
]
说明：

所有输入均为小写字母。
不考虑答案输出的顺序。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/group-anagrams
*/
// 使用计数与bit位，最后执行超时
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        if (strs.empty()) {
            return vector<vector<string>>();
        }
        
        vector<vector<string>> res;
        map<string, map<char, int>> m;
        map<string, unsigned long> mb;
        map<string, int> counters;
        int empty = 0;
        for (auto& s : strs) {
            if (s.empty()) {
                ++empty;
            } else {
                ++counters[s];
                if (counters[s] !=1) {
                    continue;
                }
                map<char, int> tmp;
                bitset<26> bs;
                for (auto c : s) {
                    ++tmp[c];
                    bs[c - 'a'] = 1;
                }
                m[s] = tmp;
                mb[s] = bs.to_ulong();
            }
        }
        if (empty) {
            res.push_back(vector<string>(empty, string("")));
        }
    
        while (!m.empty()) {
            auto it = m.begin();
            vector<string> tmp;
            string key = it->first;
            unsigned long bit = mb[key];
            tmp.insert(tmp.end(), counters[key], key);
            ++it;
            while (it != m.end()) {
                if (it->first.size() != key.size() || bit != mb[it->first]) {
                    ++it;
                    continue;
                }
                auto it1 = m[it->first].begin();
                auto it2 = m[key].begin();
                bool same = true;
                while (it1 != m[it->first].end() && it2 != m[key].end()) {
                    if (it1->first != it2->first || it1->second != it2->second) {
                        same = false;
                        break;
                    }
                    ++it1;
                    ++it2;
                }
                if (same) {
                    tmp.insert(tmp.end(), counters[it->first], it->first);
                    it = m.erase(it);
                } else {
                    ++it;
                }
            }
            m.erase(key);
            res.push_back(tmp);
        }

        return res;
    }
};

// 改进，使用索引计数，生成hash key
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        if (strs.empty()) {
            return vector<vector<string>>();
        }
        
        vector<vector<string>> res;
        int arr[26];
        map<string, int> imap;
        string key;
        key.reserve(sizeof(arr));
        char* parr = (char *)arr;
        for (auto& s : strs) {
            memset(arr, 0, sizeof(arr));
            for (auto c : s) {
                ++arr[c - 'a'];
            }
            key = string(parr, sizeof(arr));
            auto it = imap.find(key);
            if (it == imap.end()) {
                res.push_back(vector<string>());
                res.back().push_back(s);
                imap[key] = res.size() - 1;
            } else {
                res[it->second].push_back(s);
            }
        }

        return res;
    }
};
