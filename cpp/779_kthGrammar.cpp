/*
在第一行我们写上一个 0。接下来的每一行，将前一行中的0替换为01，1替换为10。

给定行数 N 和序数 K，返回第 N 行中第 K个字符。（K从1开始）


例子:

输入: N = 1, K = 1
输出: 0

输入: N = 2, K = 1
输出: 0

输入: N = 2, K = 2
输出: 1

输入: N = 4, K = 5
输出: 1

解释:
第一行: 0
第二行: 01
第三行: 0110
第四行: 01101001

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/k-th-symbol-in-grammar
*/
// 由观察得知，每一行长度是上一行的2倍
// 第N行的第K个符号 由第N-1行的第(K+1)/2个符号展开替换后产生
class Solution {
public:
    int kthGrammar(int N, int K) {
        if (K == 1) {
            return 0;
        }
        int pre = kthGrammar(N - 1, (K + 1) / 2);
        int mod = K % 2;
        if (mod == 1) {
            return pre;
        }
        return pre == 0 ? 1 : 0;
    }
};
