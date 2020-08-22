/*
给定一个二维网格和一个单词，找出该单词是否存在于网格中。

单词必须按照字母顺序，通过相邻的单元格内的字母构成，其中“相邻”单元格是那些水平相邻或垂直相邻的单元格。同一个单元格内的字母不允许被重复使用。

示例:

board =
[
  ['A','B','C','E'],
  ['S','F','C','S'],
  ['A','D','E','E']
]

给定 word = "ABCCED", 返回 true.
给定 word = "SEE", 返回 true.
给定 word = "ABCB", 返回 false.

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/word-search
*/

// 首先遍历比对是否满足第一个字符
// 递归检测从该坐标开始，向上下左右四个方向扩展
// 最后，对已经探测过符合条件的点，需要设置成特殊字符，这里使用 # 号，避免后续重复查找到该字符
class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        if (board.empty()) {
            return false;
        }
        if (word.empty()) {
            return false;
        }

        for (int row = 0; row < board.size(); ++row) {
            for (int column = 0; column < board[row].size(); ++column) {
                if (board[row][column] == word[0]) {
                    if (backtrace(board, word, 0, row, column)) {
                        return true;
                    }
                }
            }
        }
        
        return false;
    }

    bool backtrace(vector<vector<char>>& board, string& word, int cur, int row, int column) {
        if (row >= board.size() || row < 0 ||
            column >= board[0].size() || column < 0 ||
            cur >= word.size()) {
            return false;
        }

        // 已被访问过的节点
        if (board[row][column] == '#') {
            return false;
        }

        if (cur != 0 && board[row][column] != word[cur]) {
            return false;
        }

        if (cur == word.size() - 1) {
            return board[row][column] == word[cur];
        } 
        
        int tmp = cur;
        char tmpChar = board[row][column];
        if (board[row][column] == word[cur]) {
            ++cur;
        }

        if (tmp != cur) {
            board[row][column] = '#'; // 将探查到过的节点做特殊标记
        }
        bool down = false, up = false, right = false, left = false;

        down = backtrace(board, word, cur, row+1, column);
        if (down) goto END;
        right = backtrace(board, word, cur, row, column + 1);
        if (right) goto END;
        up = backtrace(board, word, cur, row - 1, column);
        if (up) goto END;
        left = backtrace(board, word, cur, row, column - 1);
        if (left) goto END;

END:
        if (tmp != cur) {
            board[row][column] = tmpChar;
        }
        return down || up || right || left;
    }
};


// 优化代码
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
