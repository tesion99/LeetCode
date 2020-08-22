/*
请设计一个函数，用来判断在一个矩阵中是否存在一条包含某字符串所有字符的路径。

路径可以从矩阵中的任意一格开始，每一步可以在矩阵中向左、右、上、下移动一格。

如果一条路径经过了矩阵的某一格，那么该路径不能再次进入该格子。

例如，在下面的3×4的矩阵中包含一条字符串“bfce”的路径（路径中的字母用加粗标出）。

[["a","b","c","e"],
["s","f","c","s"],
["a","d","e","e"]]

但矩阵中不包含字符串“abfb”的路径，因为字符串的第一个字符b占据了矩阵中的第一行第二个格子之后，路径不能再次进入这个格子。

 

示例 1：

输入：board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word = "ABCCED"
输出：true
示例 2：

输入：board = [["a","b"],["c","d"]], word = "abcd"
输出：false
提示：

1 <= board.length <= 200
1 <= board[i].length <= 200
注意：本题与主站 79 题相同：https://leetcode-cn.com/problems/word-search/

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/ju-zhen-zhong-de-lu-jing-lcof
*/
// 回溯 dfs
class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        if (word.empty()) return false;

        int direcs[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        for (int r = 0; r < board.size(); ++r) {
            for (int c = 0; c < board[0].size(); ++c) {
                if (board[r][c] == word[0]) {
                    if (helper(board, direcs, r, c, 0, word)){
                        return true;
                    }
                }
            }
        }
        return false;
    }

    bool helper(vector<vector<char>>& board, int direcs[4][2], int r, int c, int idx, string& word) {
        if (r < 0 || r >= board.size() || c < 0 || c >= board[0].size()
            || board[r][c] == '#' || board[r][c] != word[idx]) {
            return false;
        }
        if (idx == word.size() - 1) {
            return true;
        }

        board[r][c] = '#';
        bool ret = false;
        for (int i = 0; i < 4; ++i) {
            int x = direcs[i][0] + r;
            int y = direcs[i][1] + c;
            if (helper(board, direcs, x, y, idx + 1, word)) {
                ret = true;
                break;
            }
        }
        board[r][c] = word[idx];
        return ret;
    }
};
