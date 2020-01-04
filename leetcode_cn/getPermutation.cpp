/*
给出集合 [1,2,3,…,n]，其所有元素共有 n! 种排列。

按大小顺序列出所有排列情况，并一一标记，当 n = 3 时, 所有排列如下：

"123"
"132"
"213"
"231"
"312"
"321"
给定 n 和 k，返回第 k 个排列。

说明：

给定 n 的范围是 [1, 9]。
给定 k 的范围是[1,  n!]。
示例 1:

输入: n = 3, k = 3
输出: "213"

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/permutation-sequence
*/
// 回溯法，记录已访问过的元素
class Solution {
public:
    string getPermutation(int n, int k) {
        if (n == 1) {
            return "1";
        }

        vector<bool> visited(n, false);
        vector<int> path;
        string s;

        path.reserve(n);
        permutation(1, n, visited, path, k, s);
        return s;
    }

    void permutation(int start, int end, vector<bool>& visited, vector<int>& path, int& k, string& s) {
        if (k <= 0) {
            return;
        }

        if (path.size() == end - start + 1) {
            if (k == 1) {
                ostringstream oss;
                for (int i = 0, sz = path.size(); i < sz; ++i) {
                    oss << path[i];
                }
                s = oss.str();
            }
            --k;
            return;
        }

        for (int i = start; i <= end; ++i) {
            if (!visited[i - 1]) {
                visited[i - 1] = true;
                path.push_back(i);
                permutation(start, end, visited, path, k, s);
                path.pop_back();
                visited[i - 1] = false;
            }
        }
    }
};
