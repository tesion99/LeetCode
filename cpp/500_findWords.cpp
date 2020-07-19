/*
给定一个单词列表，只返回可以使用在键盘同一行的字母打印出来的单词。键盘如下图所示。

示例：

输入: ["Hello", "Alaska", "Dad", "Peace"]
输出: ["Alaska", "Dad"]
 

注意：

你可以重复使用键盘上同一字符。
你可以假设输入的字符串将只包含字母。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/keyboard-row
*/
class Solution {
public:
    vector<string> findWords(vector<string>& words) {
        vector<string> res;
        char line1[] = {'Q', 'W', 'E', 'R', 'T', 'Y', 'U', 'I', 'O', 'P'};
        char line2[] = {'A', 'S', 'D', 'F', 'G', 'H', 'J', 'K', 'L'};
        char line3[] = {'Z', 'X', 'C', 'V', 'B', 'N', 'M'};
        vector<set<char>> lines(3);

        lines[0] = set(line1, line1 + sizeof(line1));
        lines[1] = set(line2, line2 + sizeof(line2));
        lines[2] = set(line3, line3 + sizeof(line3));

        for (auto& w : words) {
            if (w.empty()) continue;

            int row = -1;
            for (int i = 0; i < lines.size(); ++i) {
                if (lines[i].find(toupper(w[0])) != lines[i].end()) {
                    row = i;
                    break;
                }
            }

            if (row == -1) continue;

            set<char>& ls = lines[row];
            bool is_same = true;
            for (int i = 1; i < w.size(); ++i) {
                if (ls.find(toupper(w[i])) == ls.end()) {
                    is_same = false;
                    break;
                }
            }
            if (is_same) {
                res.push_back(w);
            }
        }

        return res;
    }
};
