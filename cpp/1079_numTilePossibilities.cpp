/*
你有一套活字字模 tiles，其中每个字模上都刻有一个字母 tiles[i]。返回你可以印出的非空字母序列的数目。

 

示例 1：

输入："AAB"
输出：8
解释：可能的序列为 "A", "B", "AA", "AB", "BA", "AAB", "ABA", "BAA"。
示例 2：

输入："AAABBC"
输出：188
 

提示：

1 <= tiles.length <= 7
tiles 由大写英文字母组成

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/letter-tile-possibilities
*/
// 回溯+排列组合思想
// 关键在于每轮回溯时，避免重复元素访问
class Solution {
public:
    int numTilePossibilities(string tiles) {
        if (tiles.empty()) {
            return 0;
        }
        int res = 0;
        string s;
        vector<bool> visited(tiles.size(), false);
        sort(tiles.begin(), tiles.end());
        dfs(tiles, visited, s, res);
        return res;
    }

    void dfs(string& tiles, vector<bool>& visited, string& s, int& res) {
        if (!s.empty()) {
            ++res;
        }

        char pre = '#'; // 标记，避免本次回溯访问到相同的字符
        for (int i = 0, sz = tiles.size(); i < sz; ++i) {
            if (pre == tiles[i]) {
                continue;
            }

            if (!visited[i]) {
                pre = tiles[i];
                s.push_back(tiles[i]);
                visited[i] = true;
                dfs(tiles, visited, s, res);
                s.pop_back();
                visited[i] = false;
            }
        }
    }
};
