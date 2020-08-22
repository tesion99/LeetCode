/*
给定一个二维的矩阵，包含 'X' 和 'O'（字母 O）。

找到所有被 'X' 围绕的区域，并将这些区域里所有的 'O' 用 'X' 填充。

示例:

X X X X
X O O X
X X O X
X O X X
运行你的函数后，矩阵变为：

X X X X
X X X X
X X X X
X O X X
解释:

被围绕的区间不会存在于边界上，换句话说，任何边界上的 'O' 都不会被填充为 'X'。 

任何不在边界上，或不与边界上的 'O' 相连的 'O' 最终都会被填充为 'X'。

如果两个元素在水平或垂直方向相邻，则称它们是“相连”的。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/surrounded-regions
*/
// 寻找4条边界上的O, bfs
class Solution {
public:
    set<pair<int, int>> visited;
    void solve(vector<vector<char>>& board) {
        if (board.empty() || board[0].empty()) return;

        int direcs[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        int rows = board.size() - 1, cols = board[0].size() - 1;
        // 查找4条边界上的O, 做bfs，剩余的O即可被填充
        set<int> cs, rs;
        cs.insert(0);
        cs.insert(cols);
        rs.insert(0);
        rs.insert(rows);
        for (auto c : cs) {
            for (int r = 0; r <= rows; ++r) {
                if (board[r][c] == 'X' || visited.count({r, c})) continue;
                bfs(board, direcs, r, c);
            }
        }
        
        for (auto r : rs) {
            for (int c = 0; c <= cols; ++c) {
                if (board[r][c] == 'X' || visited.count({r, c})) continue;
                bfs(board, direcs, r, c);
            }
        }

        for (int r = 0; r <= rows; ++r) {
            for (int c = 0; c <= cols; ++c) {
                if (board[r][c] == 'O' && visited.count({r, c}) == 0) {
                    board[r][c] = 'X';
                }
            }
        }
    }

    void bfs(vector<vector<char>>& board, int direcs[4][2], int r, int c) {
        if (r < 0 || r >= board.size() || c < 0 || c >= board[0].size()
            || board[r][c] == 'X' || visited.count({r, c})) {
            return;
        }

        visited.insert({r, c});
        for (int i = 0; i < 4; ++i) {
            int x = r + direcs[i][0];
            int y = c + direcs[i][1];
            bfs(board, direcs, x, y);
        }
    }
};

