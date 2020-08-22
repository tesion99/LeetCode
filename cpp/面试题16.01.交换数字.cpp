/*
编写一个函数，不用临时变量，直接交换numbers = [a, b]中a与b的值。

示例：

输入: numbers = [1,2]
输出: [2,1]
提示：

numbers.length == 2

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/swap-numbers-lcci
*/
// 考虑如下情形
// numbers[0] = numbers[0] + numbers[1]
// numbers[1] = numbers[0] - numbers[1]
// numbers[0] = numbers[0] - numbers[1]
// 如此在numbers[0] numbers[1]为极限值时，其和或差会溢出
// 考虑到异或运算: a ^ b ^ a = b, 故使用异或
class Solution {
public:
    vector<int> swapNumbers(vector<int>& numbers) {
        numbers[0] ^= numbers[1];
        numbers[1] ^= numbers[0];
        numbers[0] ^= numbers[1];
        return numbers;
    }
};
