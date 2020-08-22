/*
输入数字 n，按顺序打印出从 1 到最大的 n 位十进制数。比如输入 3，则打印出 1、2、3 一直到最大的 3 位数 999。

示例 1:

输入: n = 1
输出: [1,2,3,4,5,6,7,8,9]
 

说明：

用返回一个整数列表来代替打印
n 为正整数

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/da-yin-cong-1dao-zui-da-de-nwei-shu-lcof
*/
class Solution {
public:
    vector<int> printNumbers(int n) {
        int max = maxNum(n);
        vector<int> res(max - 1, 0);
        for (int i = 1; i < max; ++i) {
            res[i - 1] = i;
        }
        return res;
    }
    int maxNum(int n) {
        int i = 1;
        while (n > 0) {
            i *= 10;
            --n;
        }
        return i;
    }
};
