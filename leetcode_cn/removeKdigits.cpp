/*
给定一个以字符串表示的非负整数 num，移除这个数中的 k 位数字，使得剩下的数字最小。

注意:

num 的长度小于 10002 且 ≥ k。
num 不会包含任何前导零。
示例 1 :

输入: num = "1432219", k = 3
输出: "1219"
解释: 移除掉三个数字 4, 3, 和 2 形成一个新的最小的数字 1219。
示例 2 :

输入: num = "10200", k = 1
输出: "200"
解释: 移掉首位的 1 剩下的数字为 200. 注意输出不能有任何前导零。
示例 3 :

输入: num = "10", k = 2
输出: "0"
解释: 从原数字移除所有的数字，剩余为空就是0。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/remove-k-digits
-----------------------
Note: 注意异常边界情况的判断
*/
class Solution {
public:
    string removeKdigits(string num, int k) {
        if (k <= 0) {
            return num;
        }

        if (num.size() <= k) {
            return "0";
        }

        stack<char> st;
        // 优先从高位(左)向低位(右)进行扫描，删除高位的数字即可
        for (int i = 0, sz = num.size(); i < sz; ++i) {
            while (!st.empty() && k > 0 && st.top() > num[i]) {
                st.pop();
                --k;
            }
            st.push(num[i]);
        }

        // stack成为单调递增的栈，移除最后剩余
        while (k > 0 && !st.empty()) {
            st.pop();
            --k;
        }

        ostringstream oss;
        while (!st.empty()) {
            oss << st.top();
            st.pop();
        }

        string res = oss.str();
        int start = 0, end = res.size() - 1;
        reverse(res.begin(), res.end());
        while (start <= end && res[start] == '0') ++start;

        res = (start > end) ? "0" : string(res.c_str() + start, end - start + 1);
        return res;
    }
};
