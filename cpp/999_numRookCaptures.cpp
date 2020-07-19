/*
在一个 8 x 8 的棋盘上，有一个白色车（rook）。也可能有空方块，白色的象（bishop）和黑色的卒（pawn）。

它们分别以字符 “R”，“.”，“B” 和 “p” 给出。大写字符表示白棋，小写字符表示黑棋。

车按国际象棋中的规则移动：它选择四个基本方向中的一个（北，东，西和南），然后朝那个方向移动，

直到它选择停止、到达棋盘的边缘或移动到同一方格来捕获该方格上颜色相反的卒。

另外，车不能与其他友方（白色）象进入同一个方格。

返回车能够在一次移动中捕获到的卒的数量。

提示：

board.length == board[i].length == 8
board[i][j] 可以是 'R'，'.'，'B' 或 'p'
只有一个格子上存在 board[i][j] == 'R'

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/available-captures-for-rook
*/
// 首先查找到车所在的位置坐标x, y
// 以该坐标为起点，向四个方向查找是否有黑色的卒p，当遇到p后，该方向查找结束
class Solution {
public:
    int numRookCaptures(vector<vector<char>>& board) {
        int x = -1, y = -1;
        for (int r = 0; r < board.size(); ++r) {
            for (int c = 0; c < board[0].size(); ++c) {
                if (board[r][c] == 'R') {
                    x = r;
                    y = c;
                    break;
                }
            }
            if (x >= 0 && y >= 0) break;
        }
        
        int res = 0;
        int direcs[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        for (int i = 0; i < 4; ++i) {
            int r = x + direcs[i][0], c = y + direcs[i][1];
            while (r >= 0 && r < 8 && c >= 0 && c < 8) {
                char ch = board[r][c];
                if (ch == '.') {
                    r += direcs[i][0];
                    c += direcs[i][1];
                    continue;
                }
                if (ch == 'p') {
                    ++res;
                }
                break;
            }
        }
        return res;
    }
};
