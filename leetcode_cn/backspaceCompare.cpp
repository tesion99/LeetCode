/*
给定 S 和 T 两个字符串，当它们分别被输入到空白的文本编辑器后，判断二者是否相等，并返回结果。 # 代表退格字符。

 

示例 1：

输入：S = "ab#c", T = "ad#c"
输出：true
解释：S 和 T 都会变成 “ac”。
示例 2：

输入：S = "ab##", T = "c#d#"
输出：true
解释：S 和 T 都会变成 “”。
示例 3：

输入：S = "a##c", T = "#a#c"
输出：true
解释：S 和 T 都会变成 “c”。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/backspace-string-compare
*/
class Solution {
public:
    bool backspaceCompare(string S, string T) {
        stack<char> ss, st;
        checkString(S, ss);
        checkString(T, st);

        if (ss.size() != st.size()) {
            return false;
        }
        while (!ss.empty() || !st.empty()) {
            if (ss.empty() || st.empty()) {
                return false;
            }
            if (ss.top() == st.top()) {
                ss.pop();
                st.pop();
            } else {
                return false;
            }
        }

        return true;
    }

    void checkString(string& str, stack<char>& st) {
        for (int i = 0, sz = str.size(); i < sz; ++i) {
            if (str[i] == '#') {
                if (!st.empty()) {
                    st.pop();
                }
            } else {
                st.push(str[i]);
            }
        }
    }
};
