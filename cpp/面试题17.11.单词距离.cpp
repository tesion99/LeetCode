/*
有个内含单词的超大文本文件，给定任意两个单词，找出在这个文件中这两个单词的最短距离(相隔单词数)。如果寻找过程在这个文件中会重复多次，而每次寻找的单词不同，你能对此优化吗?

示例：

输入：words = ["I","am","a","student","from","a","university","in","a","city"], word1 = "a", word2 = "student"
输出：1
提示：

words.length <= 100000

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/find-closest-lcci
*/
// hash记录单词出现的所有索引，在比对索引距离的最小值
class Solution {
public:
    int findClosest(vector<string>& words, string word1, string word2) {
        map<string, vector<int>> m;
        for (int i = 0; i < words.size(); ++i) {
            if (words[i] == word1 || words[i] == word2) {
                m[words[i]].push_back(i);
            }
        }
        int dist = INT_MAX;
        if (m.size() != 2) {
            return -1;
        }
        auto& v1 = m[word1];
        auto& v2 = m[word2];
        for (int i = 0; i < v1.size(); ++i) {
            for (int j = 0; j < v2.size(); ++j) {
                dist = min(dist, int(abs(v1[i] - v2[j])));
            }
        }
        return dist;
    }
};
